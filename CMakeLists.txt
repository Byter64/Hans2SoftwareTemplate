cmake_minimum_required(VERSION 3.24.0)

#set(COMPILER_PATH "/home/jonathan/.opt/riscv/bin/")
#set(CMAKE_CXX_COMPILER "${COMPILER_PATH}riscv32-unknown-elf-g++")
#set(CMAKE_C_COMPILER "${COMPILER_PATH}riscv32-unknown-elf-gcc")
#set(CMAKE_LINKER "${COMPILER_PATH}riscv32-unknown-elf-ld")
#set(CMAKE_OBJDUMP "${COMPILER_PATH}riscv32-unknown-elf-objdump")
#set(CMAKE_OBJCOPY "${COMPILER_PATH}riscv32-unknown-elf-objcopy")
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchain.cmake)
set(WUEHANS_LINKERSCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/wuehans/wuehans.ld)
set(WUEHANS_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

project("WueHans Template Game")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(FetchContent)
FetchContent_Declare(Hall
    GIT_REPOSITORY https://github.com/byter64/Hall.git
    GIT_TAG main
)

add_subdirectory(lib)
FetchContent_MakeAvailable(Hall)

add_subdirectory(src)
