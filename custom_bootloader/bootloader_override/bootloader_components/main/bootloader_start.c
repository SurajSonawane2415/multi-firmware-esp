#include "sdkconfig.h"
#include <stdbool.h>
#include "esp_log.h"
#include "esp_rom_sys.h"
#include "bootloader_init.h"
#include "bootloader_utility.h"
#include "bootloader_common.h"
#include "soc/gpio_reg.h"
#include "soc/rtc_io_reg.h"
#include "soc/io_mux_reg.h"


#define GPIO_PIN_REG_16         IO_MUX_GPIO16_REG
#define GPIO_PIN_REG_17         IO_MUX_GPIO17_REG

static const char *TAG = "boot";

static int load_partition_table(bootloader_state_t *bs);

void __attribute__((noreturn)) call_start_cpu0(void)
{ 

  // 1. Hardware initialization
    bootloader_init();

    CLEAR_PERI_REG_MASK(RTC_IO_TOUCH_PAD3_REG, RTC_IO_TOUCH_PAD3_MUX_SEL_M);
    PIN_FUNC_SELECT(GPIO_PIN_REG_16, PIN_FUNC_GPIO);
    PIN_INPUT_ENABLE(GPIO_PIN_REG_16);
    REG_WRITE(GPIO_ENABLE_W1TC_REG, BIT16);
    REG_CLR_BIT(GPIO_PIN_REG_16, FUN_PD);
    REG_SET_BIT(GPIO_PIN_REG_16, FUN_PU);

    CLEAR_PERI_REG_MASK(RTC_IO_TOUCH_PAD3_REG, RTC_IO_TOUCH_PAD3_MUX_SEL_M);
    PIN_FUNC_SELECT(GPIO_PIN_REG_17, PIN_FUNC_GPIO);
    PIN_INPUT_ENABLE(GPIO_PIN_REG_17);
    REG_WRITE(GPIO_ENABLE_W1TC_REG, BIT17);
    REG_CLR_BIT(GPIO_PIN_REG_17, FUN_PD);
    REG_SET_BIT(GPIO_PIN_REG_17, FUN_PU);


    // 2. Load partition table
    bootloader_state_t bs = {0};
    load_partition_table(&bs);

    // 2. Select the number of boot partition
    int boot_index;
    int select_partition = 1;
    ESP_LOGI(TAG, "Select the firmware:");
    ESP_LOGI(TAG, "Switch 1: serial_led(ota_0) Switch 2: all_ledblink(ota_1)");
    while(select_partition == 1){

    if ( REG_GET_BIT(GPIO_IN_REG, BIT16) != BIT16) {
			ESP_LOGI(TAG, "Switch 2(GPIO 16) PRESSED: serial_led firmware(ota_0)\n");
            boot_index = 0; //for ota_0
            select_partition = 0;
        } 

    if ( REG_GET_BIT(GPIO_IN_REG, BIT17) != BIT17) {
			ESP_LOGI(TAG, "Switch 2(GPIO 17) PRESSED: all_ledblink firmware(ota_1)\n");
            boot_index = 1; //for ota_1
            select_partition = 0;
        }     

    }
    
    ESP_LOGE(TAG, "Load the app image for booting\n");
    // 3. Load the app image for booting
    bootloader_utility_load_boot_image(&bs, boot_index);

}

static int load_partition_table(bootloader_state_t *bs)
{
    // Load partition table
    if (!bootloader_utility_load_partition_table(bs)) {
        ESP_LOGE(TAG, "load partition table error!");
        return INVALID_INDEX;
    }

    // Get selected boot partition
    return bootloader_utility_get_selected_boot_partition(bs);
}

// Return global reent struct if any newlib functions are linked to bootloader
struct _reent *__getreent(void)
{
    return _GLOBAL_REENT;
}
