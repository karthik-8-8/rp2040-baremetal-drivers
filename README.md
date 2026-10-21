# RP2040 Bare-Metal Programming and Peripheral Experiments

## Overview

This repository represents my completed hands-on learning project focused on **RP2040 bare-metal programming, embedded C, and microcontroller peripheral interfacing**.

I used the official RP2040 datasheet and hardware documentation to understand the microcontroller's architecture, peripheral registers, and hardware operation. Rather than depending entirely on high-level libraries, I wrote programs to explore peripheral configuration and control through direct register-level programming.

Most of my peripheral experiments focused on **polling-based programming**, which helped me understand how software interacts with hardware registers, monitors peripheral status flags, and performs input/output operations.

This project helped me establish a strong foundation in embedded systems and provided practical knowledge that I later applied while developing **SAT-OS**, my RP2040-based embedded firmware project.

## Peripherals and Concepts Explored

- **GPIO (General-Purpose Input/Output):** Configuring digital input and output pins, controlling LEDs, interfacing push buttons, and understanding pin configuration.
- **Timers and Delays:** Exploring timer configuration, counter operation, prescalers, and timing-based operations.
- **PWM (Pulse-Width Modulation):** Configuring PWM output and understanding duty cycle and signal generation.
- **UART (Universal Asynchronous Receiver/Transmitter):** Implementing serial communication experiments, including polling-based transmission and reception.
- **SPI (Serial Peripheral Interface):** Exploring SPI configuration, communication fundamentals, and peripheral data transfer.
- **I²C (Inter-Integrated Circuit):** Studying I²C configuration, communication fundamentals, and interfacing concepts.
- **ADC (Analog-to-Digital Converter):** Exploring analog signal conversion, ADC configuration, and interrupt-related experiments.
- **Interrupts:** Experimenting with interrupt handling and understanding the differences between polling-based and interrupt-driven approaches.
- **Non-Blocking Programming:** Exploring non-blocking execution techniques and alternatives to continuously waiting for peripheral events.

## Embedded C and Low-Level Programming Skills

Through these practical experiments, I developed a working understanding of several important embedded programming concepts:

- **Register-Level Programming:** Configuring and controlling microcontroller peripherals using hardware register definitions from official documentation.
- **Bit Manipulation:** Using bitwise operators to set, clear, toggle, and check individual bits in hardware registers.
- **Pointers and Memory-Mapped I/O:** Understanding pointer-based memory access and using pointers to interact with peripheral registers.
- **`volatile` Keyword:** Understanding why hardware registers and asynchronously changing values require careful treatment by the compiler.
- **Macros and Preprocessor Directives:** Using macros and header files to organize embedded C code and define reusable operations.
- **Peripheral Status Flags:** Polling status registers to determine when peripherals are ready for data transmission, reception, or other operations.
- **Polling-Based Programming:** Implementing peripheral operations by checking hardware status flags and controlling execution flow accordingly.
- **Interrupt Fundamentals:** Exploring interrupt configuration and event-driven execution.
- **Code Organization:** Working with C source files, header files, functions, and build configuration to organize individual experiments.
- **Hardware Documentation:** Reading the RP2040 datasheet and hardware documentation to understand register fields, peripheral configuration, and expected hardware behavior.

## Development Environment

- **Microcontroller:** Raspberry Pi RP2040
- **Programming Language:** C
- **Programming Approach:** Bare-metal register-level programming, primarily polling-based
- **Development Environment:** Visual Studio Code
- **Build System:** CMake
- **Toolchain:** ARM GNU Toolchain
- **Hardware Reference:** Official RP2040 datasheet and hardware documentation

## Repository Organization

The repository contains individual C programs covering different peripheral experiments and embedded programming techniques.

The examples include bare-metal implementations and selected Raspberry Pi Pico SDK programs used to explore and compare different programming approaches. These are primarily independent experiments rather than a single firmware application containing every source file.

The root `CMakeLists.txt` defines the selected application to build; not every standalone source file is compiled into the same firmware image.

## Key Learning Outcomes

By completing this project, I strengthened my understanding of:

- How microcontroller peripherals are configured and controlled at the register level.
- How embedded C concepts such as pointers, bit manipulation, and `volatile` apply to real hardware.
- How polling-based firmware interacts with peripheral status registers.
- How to use technical documentation to investigate hardware behavior and implement peripheral functionality.
- How to structure and experiment with low-level embedded programs.

## Application of Learning

The knowledge and practical experience gained from this project became a foundation for my subsequent **SAT-OS project**, where I applied my understanding of RP2040 peripherals and embedded C while working on a more integrated firmware system.

This learning project marked an important step in my progression from basic microcontroller programming toward driver development and embedded firmware engineering.

## Project Status

**Completed learning project.**

The core learning and peripheral experiments documented in this repository are complete. The repository serves as a reference for the concepts explored and the practical foundation I developed before moving on to more integrated embedded firmware projects.

