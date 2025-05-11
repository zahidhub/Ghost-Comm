# ghostComm - A language encryption system

A simple Morse code encryptor & decryptor, written in C, with a built-in test suite.

#### Status:
[![build](https://github.com/zahidhub/Ghost-Comm/actions/workflows/build.yml/badge.svg)](https://github.com/zahidhub/Ghost-Comm/actions/workflows/build.yml)
[![test](https://github.com/zahidhub/Ghost-Comm/actions/workflows/test.yml/badge.svg)](https://github.com/zahidhub/Ghost-Comm/actions/workflows/test.yml)
[![GitHub Release](https://img.shields.io/github/v/release/zahidhub/Ghost-Comm?style=flat-square)](https://github.com/zahidhub/Ghost-Comm/releases)
[![License](https://img.shields.io/github/license/zahidhub/Ghost-Comm?style=flat-square)](LICENSE)
![GitHub contributors](https://img.shields.io/github/contributors/zahidhub/Ghost-Comm)


---

## Features

**Encrypt** plain‐text → Morse code

**Decrypt** Morse code → plain‐text




---

## Project Structure

The project works with standard input and runs Unit tests via CTest. Moreover CI workflow is configured in .github/workflows.

```
.
├── CMakeLists.txt        # top-level build script
├── src/
│   ├── ghostComm.c         # encryption/decryption logic
│   ├── ghostComm.h
│   └── main.c            # command-line interface
├── tests/
│   └── testGhostComm.c    # unit tests
├── .github/
│   └── workflows/        # CI (build + test) definitions
├── .gitignore
├── README.md
└── LICENSE               # MIT License

```

#### Components
**`ghostComm.c`**: This files holds the main logic behind encryption de decrypt

**`ghostComm.h`**: The library file

**`main.c`**: The executable file and entry point to the program.

**`testGhostComm.c`**: In order to test the implemantation, various tests are added to it.

**`CMakelists.c`**: Helps to automate the build and make the process easy.

#### CI/CD
**`build.yml`**: The file hold jobs to build the project in pipeline.

**`test.yml`**: We run the tests in pipeline through this file

---

## Installation (Run Locally)

 **Prerequisites:** CMake ≥ 3.10, A C compiler (GCC, Clang, MSVC, etc.)

 - **Step1:** Git clone the project
```
git clone git@github.com:zahidhub/Ghost-Comm.git
```

- **Step2:** Now open the ghostComm folder in your favourite IDE

- **Step3:** Open the terminal and nevigate to the ghostComm folder and add this command:
```
mkdir build
cd build
cmake ..
cmake --build .
./ghostComm
```
The program should start!

---

## Usage

 **Learn and practice Morse code:** Turn any text you type into dots and dashes (and back again) to drill your own encoding/decoding skills.
 
 **Integration in learning platforms:** Wrap Ghost-Comm as a backend service in a web app or mobile app to quiz users on Morse code translation, track progress, or build interactive tutorials.

 **Retro-style notifications:** Hook it up to LEDs or a Raspberry Pi GPIO to blink Morse-coded alerts (“New email”, “Timer done”, etc.) in hardware DIY projects.

 **Embed in scripts for alerts:** Have important system notifications (cronjobs, build failures, monitoring alerts) whispered in Morse code, either on screen or even audibly via:
 ```
 ghost-comm -e "Build failed!" | festival --tts
 ```


---

## Tools

- **C**
- **CMAke**
- **Unit Tests**
- **Github Actions**

---

## Materials Used

- **Google**: For research purpose
- **C**: Program language


---

## Credits

- **Created by**: Hasan Zahid

---

## License

This project is open-source and available under the [MIT License](LICENSE).
