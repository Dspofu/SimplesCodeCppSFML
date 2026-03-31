# Moving circle
Used [MinGw-64 or MinGw](https://github.com/niXman/mingw-builds-binaries/releases)

Download the [SFML 2.6.2](https://www.sfml-dev.org/download/sfml/2.6.2) library
- [Download](https://www.sfml-dev.org/files/SFML-2.6.2-windows-gcc-13.1.0-mingw-32-bit.zip) for Windows 32 Bit version
- [Download](https://www.sfml-dev.org/files/SFML-2.6.2-windows-gcc-13.1.0-mingw-64-bit.zip) for Windows 64 Bit version

> Paste the `"SFML2.6.2"` folder into the project root and copy the `.dll` files from `"SFML-2.6.2\bin"` and paste into `"out"`

- From the `"out"` folder keep only the `"font"` folder
# 
- Testing **C++** after inserting `"bin"` in Windows `environment variables`: `g++ --version`<br>
- Now just run the `"build.bat"` file and run the file that is in the `"out"` folder

<br>

\- [**Download release for demo**](https://github.com/dspofu/SimplesCodeCppSFML/releases/tag/v0.2.0%40demo)
## Result 🕹️


**In this example I leave a** `WASD` **control. Movement and speed controls.**

![DemoGame](image.png)