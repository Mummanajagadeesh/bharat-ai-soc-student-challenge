# Zybo (xc7z010clg400-1) PYNQ and WiFi Setup Documentation



## 1. Overview
This document outlines the procedure for installing the PYNQ framework on the original Zybo board (xc7z010clg400-1) and configuring a D-Link WiFi dongle for wireless connectivity. 

## 2. Initial Constraints and Challenges
Initial attempts to boot the board using standard Board Support Packages (BSP) were unsuccessful. The officially available BSP files are compiled exclusively for the newer Zybo-Z10 and Zybo-Z20 hardware variants, making them incompatible with the legacy xc7z010clg400-1 architecture.

---

## 3. Step-by-Step Configuration Guide

### Step 3.1: PYNQ Image Installation
Due to the BSP compatibility issues, a community-maintained PYNQ image specifically built for the xc7z010clg400-1 must be used.

* **Repository Reference:** [nick-petrovsky/PYNQ-ZYBO](https://github.com/nick-petrovsky/PYNQ-ZYBO)
* **Action:** Download and flash the board-specific image to your boot media. 
* **Download Link:** [Zybo-3.0.1-fix-boot-bin-fix-havege.img.xz](https://github.com/nick-petrovsky/PYNQ-ZYBO/releases/download/v0.1.0/Zybo-3.0.1-fix-boot-bin-fix-havege.img.xz)

### Step 3.2: Temporary Network Configuration
To compile the necessary WiFi drivers directly on the board, the Zybo requires a temporary internet connection.



* **Hardware Setup:** Connect the Zybo board directly to a host laptop using an Ethernet cable.
* **Network Setup:** Configure a DHCP server on the host laptop to share its active internet connection with the Zybo board over the Ethernet interface.

### Step 3.3: Native WiFi Driver Compilation
The base PYNQ image does not come pre-loaded with comprehensive wireless drivers. To enable the D-Link WiFi Dongle (using the `rtl8188guib` chipset), the driver must be compiled natively on the Zybo's ARM processor.

* **Repository Reference:** [lwfinger/rtw88](https://github.com/lwfinger/rtw88)
* **Action:** Clone the repository to the Zybo board over the active Ethernet connection. Compile and install the driver directly on the ARM architecture to initialize the D-Link hardware.
