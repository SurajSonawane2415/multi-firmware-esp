# Multi-Firmware-ESP

## About The Project

Develope a bootloader for the ESP32 microcontroller to enable flashing of multiple firmware versions. and navigate between them using switches.

## Table of Contents

- [Project](#project)
   - [Table of Contents](#table-of-contents)
   - [About The Project](#about-the-project)
   - [Demo](#demo)
   - [File Structure](#file-structure)
   - [Getting started](#getting-started)
   - [Future Work](#future-work)
   - [Contributors](#contributors)
   - [Resources](#resources)
   - [Acknowledgements](#acknowledgements)
   - [License](#license)

## Project Workflow

-  Understanding [bootloader:](https://embeddedinventor.com/embedded-bootloader-and-booting-process-explained/), Clarified my theories on bootloaders in embedded systems and how they work.
-  Look deep inside [OTA code](https://github.com/espressif/esp-idf/tree/master/examples/system/ota) of ESP-IDF (master branch) to understand how it switches between firmware versions.
-  Implemented an OTA (Over The Air) update mechanism for ESP32, enabling firmware updates/uploads over WiFi from anywhere.
-  Developed a custom bootloader to select a particular firmware from multiple firmware options using switches(GPIO).
-  Implemented ESP-Serial-Flasher to flash firmware from the Master ESP to the second ESP Over The Air (OTA) via WiFi from anywhere.

## Demo

https://github.com/SurajSonawane2415/multi-firmware-esp/assets/129578177/d3a5834c-3084-4c83-a85e-c9e183cdd8c1

## Future Scope 

- [ ] Implement [Over The Air Updates (OTA)](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/ap1-reference/system/ota.html) Firmware update in bootloader stage to eliminate need of Master ESP for flashing the firmware.

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
