cmake_minimum_required(VERSION 3.24.0)

#If you want to build for desktop, use the flag -DDESKTOPBUILD, when running cmake
option(DESKTOPBUILD "If ON, the result will run on your system, if OFF (default) the result will run on wueHans")

if(NOT DESKTOPBUILD)
	set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchain.cmake)
	set(WUEHANS_LINKERSCRIPT ${CMAKE_CURRENT_SOURCE_DIR}/wuehans/wuehans.ld)
endif()

set(WUEHANS_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project("WueHans Template Game")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(FetchContent)
FetchContent_Declare(Halib
    GIT_REPOSITORY https://github.com/byter64/Halib.git
    GIT_TAG main
    #GIT_TAG develop #For the devs only :)
)

if(NOT DESKTOPBUILD)
	add_subdirectory(lib)
endif()
FetchContent_MakeAvailable(Halib)

if(NOT DESKTOPBUILD)
	add_compile_options(
	  -fno-exceptions
	  -nostdlib
	  -fno-unwind-tables
	  -fno-rtti
	  -march=rv32im
	  -Os
	  -ffreestanding
	  -Bstatic
	  -nostdinc
	  -fno-builtin
	)

	add_link_options(
	  -nostdlib
	  -T ${WUEHANS_LINKERSCRIPT}
	  -Wl,--gc-sections
	  -ffreestanding
	  -Bstatic
	  -nostdlib
	  -fno-builtin
	)
endif()

add_subdirectory(code)
