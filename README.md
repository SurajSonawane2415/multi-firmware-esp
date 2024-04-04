# Multi-Firmware-ESP

Develop a bootloader for the ESP32 microcontroller to enable flashing of multiple firmware versions and navigation between them using switches.

## Table of Contents

- [Multi-Firmware-ESP](#multi-firmware-esp)
  - [Table of Contents](#table-of-contents)
  - [Demonstrations](#demonstrations)
  - [About The Project](#about-the-project)
    - [Project Workflow](#project-workflow)
    - [File Structure](#file-structure)
    - [Bootloader](#bootloader)
    - [Over The Air Updates (OTA)](#over-the-air-updates-ota)
  - [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Installation](#installation)
  - [Usage](#usage)
    - [ESP Serial Flasher (Over The Air)](#part-1-esp-serial-flasher-over-the-air)
    - [Custom Bootloader (Multi firmware ESP)](#part-2-custom-bootloader-multi-firmware-esp)
  - [Contributor](#contributor)
  - [Resources](#resources)
  - [Acknowledgements](#acknowledgements)
  
## Demonstrations
https://github.com/SurajSonawane2415/multi-firmware-esp/assets/129578177/d3a5834c-3084-4c83-a85e-c9e183cdd8c1

## About the project
### Project Workflow

-  Understanding [bootloader:](https://embeddedinventor.com/embedded-bootloader-and-booting-process-explained/), Clarified my theories on bootloaders in embedded systems and how they work.
-  Look deep inside [OTA code](https://github.com/espressif/esp-idf/tree/master/examples/system/ota) of ESP-IDF (master branch) to understand how it switches between firmware versions.
-  Implemented an [OTA (Over The Air) update](https://github.com/SurajSonawane2415/OTA_UPDATE_ESP32/tree/7446e1fa84ad3d33f6d277d31926ffdc2e9baafa) mechanism for ESP32, enabling firmware updates/uploads over WiFi from anywhere.
-  Developed a [custom bootloader])(https://github.com/SurajSonawane2415/multi-firmware-esp/tree/main/custom_bootloader) to select a particular firmware from multiple firmware options using switches(GPIO).
-  Implemented [ESP-Serial-Flasher](https://github.com/espressif/esp-serial-flasher) to flash firmware from the [Master ESP to the second ESP, Over The Air (OTA)](https://github.com/SurajSonawane2415/OTA_UPDATE_ESP32/tree/7446e1fa84ad3d33f6d277d31926ffdc2e9baafa) via WiFi from anywhere.
-  Currently, I am developing a [OTA](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/system/ota.html) firmware update/upload mechanism to load multiple firmware in ESP at the **bootloader stage** to eliminate the need for a master ESP.

### File Structure

```
👨‍💻Multi-Firmware-ESP
├ 📂 OTA_UPDATE_ESP32 //Contains code to flash firmware from the Master ESP to the second ESP, Over The Air (OTA) via WiFi.
| ├ 📂frontend
| |  └📄index.html
| └ 📂main
|   |   ├ 📂include
|   |   |  └📄flasher.h   
|   |   ├ 📄CMakeLists.txt
|   |   ├ 📄component.mk
|   |   ├ 📄favicon.ico
|   |   ├ 📄fileserver.c
|   |   ├ 📄flasher.c 
|   |   └ 📄main.c 
|   ├ 📄CMakeList.txt
|   ├ 📄Makefile
|   ├ 📄partitions_example.csv //custom partition table
|   └ 📄sdkconfig.defaults
├ 📂Components //Contains all the header and source files of esp-serial-flasher library   
├ 📂 custom_bootloader // contains custom bootloader code (Multi firmware ESP) to select a particular firmware from multiple firmware options using switches(GPIO).
|  ├ 📂 bootloader_override
|    ├ 📂bootloader_components // contains custom bootloader code
|    ├ 📂main
|    ├ 📄CMakeList.txt
|    ├ 📄Makefile
|    └ 📄sdkconfig
└ 📄README.md //Documentation of project
```

### [Bootloader](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/bootloader.html)
- An embedded bootloader is a piece of software that takes a system from a power-up state to a usable state. To be more specific, it is the code that runs from the moment you press the power button, till the point in time where it reaches the main function in your code.

![image](https://github.com/SurajSonawane2415/multi-firmware-esp/assets/129578177/477169bf-fdfa-400f-b083-c54f8b138929)

### [Over The Air Updates (OTA)](https://blog.espressif.com/ota-updates-framework-ab5438e30c12)
![image](https://github.com/SurajSonawane2415/multi-firmware-esp/assets/129578177/f246b119-2727-4d73-a275-1b116feb793c)
- The OTA update mechanism allows a device to update itself based on data received while the normal firmware is running (for example, over Wi-Fi or Bluetooth.).
- OTA requires configuring the [Partition Tables](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/partition-tables.html) of the device with at least two OTA app slot partitions (i.e., ota_0 and ota_1) and an OTA Data Partition. The Partition table defines the flash layout on ESP32.
- ![image](https://github.com/SurajSonawane2415/multi-firmware-esp/assets/129578177/d0420f10-9e6d-4075-9896-5f01f26aceb6)


## Future Scope 

- [ ] Implement [Over The Air Updates (OTA)](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/ap1-reference/system/ota.html) Firmware update in bootloader stage to eliminate need of Master ESP for flashing the multiple firmwares into ESP.

## Getting Started
### Prerequisites
To download and use this code, the minimum requirements are:
- ESP_IDF
- Windows 7 or later (64-bit), Ubuntu 20.04 or later

### Installation
Clone the project by typing the following command in your Terminal/CommandPrompt:
      
     `git clone --recursive https://github.com/SurajSonawane2415/multi-firmware-esp.git`

Navigate to the project folder:
`cd multi-firmware-esp`

## Usage

### PART-1: ESP Serial Flasher (Over The Air)
To flash firmware from the Master ESP to the second ESP, Over The Air (OTA) via WiFi.

- **Hardware connection :**
Table below shows connection between two ESP32 devices.

| ESP32 (master) | ESP32 (second esp) |
|:------------:|:-------------:|
|    IO26      |      IO0      |
|    IO25      |     RESET     |
|    IO4       |      RX0      |
|    IO5       |      TX0      |

Once the requirements are satisfied, you can easily download the project and use it on your machine. After following the above steps, use the following commands to:

Navigate to the OTA_UPDATE_ESP32 folder:
`cd OTA_UPDATE_ESP32`

To activate the IDF:
`get_idf`

To configure wi-fi:
`idf.py menuconfig`

* `Example Connection Configuration`
  * `WiFi SSID` - Set wifi SSID
  * `WiFi PASSWORD` - Set wifi Password

To build the code:
`idf.py build`

To flash the code:
`idf.py -p (PORT) flash monitor`

### PART-2: Custom Bootloader (Multi firmware ESP)
To use a [custom bootloader](https://github.com/SurajSonawane2415/multi-firmware-esp/tree/main/custom_bootloader) (Multi firmware ESP) to select a particular firmware from multiple firmware options using switches(GPIO).

Navigate to the folder:
`cd custom_bootloader/bootloader_override`

To activate the IDF:
`get_idf`

To build the code:
`idf.py build`

To flash the partition table:
`idf.py -p (PORT) partition-table-flash`

To flash the custom bootloader:
`idf.py -p (PORT) bootloader-flash monitor`

## Resources

- [Bootloader ESP32](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/apiguides/bootloader.html)

- [Bootloader Stages](https://embeddedinventor.com/embedded-bootloader-and-booting-process-explained/)

- [Custom Bootloader](https://esp32.com/viewtopic.php?t=29232)

- [Over The Air Updates(OTA)](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/system/ota.html)

## Contributor

[Suraj Sonawane](https://github.com/SurajSonawane2415)

## Acknowledgements

[SRA VITI](https://sravjti.in/) for providing us with required resources and Special thanks to my mentors [Moteen Shah](https://github.com/Jamm02) and all the seniors at SRA, VJTI for their
constant support and guidance throughout the project.

## License

[MIT License](https://opensource.org/license/mit)
