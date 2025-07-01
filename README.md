# Setup
We officially only support Windows and Linux. If anything else also works, then this is pure coincidence.

## The easy stuff
You need:
- [CMake](https://cmake.org/download/)
- [Ninja](https://github.com/ninja-build/ninja/wiki/Pre-built-Ninja-packages)
- A code editor

## Download Clang
#### Windows
The clang binaries for windows can be downloaded from this shady google drive link (size ca. 7 GB): [https://drive.google.com/file/d/1f136QhEjiOVqIvz3E0IVTMM5NRc88Kyc/view?usp=drivesdk](https://drive.google.com/file/d/1f136QhEjiOVqIvz3E0IVTMM5NRc88Kyc/view?usp=drivesdk). Just kidding, this is *my* shady google drive so you should be safe. Anyway, Unpack the zip file and add clangBinaries\Release\bin to your path. You should now be able to execute the following in your command line:

```bash
clang
```
which should return:
```bash
clang: error: no input files
```

#### Linux
@Jonathan, bitte nochmal durchlesen

Clang can be downloaded with your preferred package manager (example shown with ???). After download, make sure that the binaries are within your path.

## Download the Software Template
Go to this Github repo and download it (we recommend to not clone it, but to rather download it and move it into your own game repo manually). [Hans 2 Software Template](https://github.com/Byter64/Hans2SoftwareTemplate/tree/main). Feel free to rename this folder to match your project's name, but don't forget to adjust the commands in the next section.

## Setup the Template
Open a command line and execute the following:
```bash
cd blaaa/Hans2SoftwareTemplate/build/Desktop
cmake ../.. -G Ninja -DDESKTOPBUILD=ON
cd ../wueHans
cmake ../.. -G Ninja
```
This initialises the build folder, in which cmake and ninja will throw in the build files. Desktop contains the desktop version which should run on your PC, while wueHans contains the wueHans build.
> 💡 **_Good To Know_**: Windows users, who want to use Visual Studio, can skip the "-G Ninja" for the Desktop build. The wueHans build **NEEDS** Ninja
> 
> 💡 **_Good To Know_**: You can build both the desktop and wueHans version by calling "Ninja" from Hans2SoftwareTemplate/build

# Template Structure
#### build/
This directory will contain your built project
#### cmake/
This directory contains helper files for cmake. You usually don't need to touch it
#### code/
This is where all your code, assets, and any file in general should go. This folder is yours
#### lib/
This directory contains system libraries, that are needed for building your project. You usually don't need to touch it
#### system-include/
This directory contains system headers, that are needed for building your project. You usually don't need to touch it
#### wuehans/
This directory contains files that are wueHans specific but are needed by every project. You usually don't need to touch it

# Adding Code to the Project
If you already know cmake, you can skip this section.

A target is a file, that is built by clang. The template lets clang generate exactly one target by default, that is your executable software. In order to add a new .c/.cpp to this target, you need to edit code/CMakeLists.txt. Open the file and add your new file under the "# Add your .cpp files here" comment.

# Building the Project
If you want to build the projectv open a command line and execute the following:
```bash
cd blaaa/Hans2SoftwareTemplate/build
ninja
```
If you have only added new source files in CMake, this should build the project and result in an executable file called build/code/game.elf.
