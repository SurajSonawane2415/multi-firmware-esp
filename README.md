# Multi-Firmware-ESP

## About The Project

Develope a bootloader for the ESP32 microcontroller to enable flashing of multiple firmware versions. and navigate between them using switches.

## Table of Contents

- [Project](#project)
   - [Table of Contents](#table-of-contents)
   - [About The Project](#about-the-project)
   - [Demonstration](#demonstration)
   - [File Structure](#file-structure)
   - [Getting started](#getting-started)
   - [Future Scope](#future-scope)
   - [Contributors](#contributors)
   - [Resources](#resources)
   - [Acknowledgements](#acknowledgements)
   - [License](#license)

## Project Workflow

-  Understanding [bootloader:](https://embeddedinventor.com/embedded-bootloader-and-booting-process-explained/), Clarified my theories on bootloaders in embedded systems and how they work.
-  Look deep inside [OTA code](https://github.com/espressif/esp-idf/tree/master/examples/system/ota) of ESP-IDF (master branch) to understand how it switches between firmware versions.
-  Implemented an [OTA (Over The Air) update](https://github.com/SurajSonawane2415/OTA_UPDATE_ESP32/tree/7446e1fa84ad3d33f6d277d31926ffdc2e9baafa) mechanism for ESP32, enabling firmware updates/uploads over WiFi from anywhere.
-  Developed a [custom bootloader])(https://github.com/SurajSonawane2415/multi-firmware-esp/tree/main/custom_bootloader) to select a particular firmware from multiple firmware options using switches(GPIO).
-  Implemented [ESP-Serial-Flasher](https://github.com/espressif/esp-serial-flasher) to flash firmware from the [Master ESP to the second ESP, Over The Air (OTA)](https://github.com/SurajSonawane2415/OTA_UPDATE_ESP32/tree/7446e1fa84ad3d33f6d277d31926ffdc2e9baafa) via WiFi from anywhere.
-  Currently, I am developing a [OTA](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/system/ota.html) firmware update/upload mechanism to load multiple firmware in ESP at the **bootloader stage** to eliminate the need for a master ESP.

## Demonstration

https://github.com/SurajSonawane2415/multi-firmware-esp/assets/129578177/d3a5834c-3084-4c83-a85e-c9e183cdd8c1

## Future Scope 

- [ ] Implement [Over The Air Updates (OTA)](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/ap1-reference/system/ota.html) Firmware update in bootloader stage to eliminate need of Master ESP for flashing the multiple firmwares into ESP.

## Contributor

[Suraj Sonawane](https://github.com/SurajSonawane2415)

## Resources

- [Bootloader ESP32](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/apiguides/bootloader.html)

- [Bootloader Stages](https://embeddedinventor.com/embedded-bootloader-and-booting-process-explained/)

- [Custom Bootloader](https://esp32.com/viewtopic.php?t=29232)

- [Over The Air Updates(OTA)](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-reference/system/ota.html)

## Acknowledgements

[SRA VITI](https://sravjti.in/) for providing us with required resources and Special thanks to my mentors [Moteen Shah](https://github.com/Jamm02) and all the seniors at SRA, VJTI for their
constant support and guidance throughout the project.

## License

[MIT License](https://opensource.org/license/mit)
