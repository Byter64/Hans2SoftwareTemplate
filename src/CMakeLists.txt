cmake_minimum_required(VERSION 3.24.0)
enable_language(C CXX ASM)
project("Cool game")

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
)

add_link_options(
  -nostdlib
  -T ${WUEHANS_LINKERSCRIPT}
  -Wl,--gc-sections
  -ffreestanding
  -Bstatic
  -nostdlib
  # -nostartfiles
)

add_executable (test.elf)

include_directories(test.elf
  PUBLIC SYSTEM ${WUEHANS_ROOT}/include
  PUBLIC SYSTEM ${WUEHANS_ROOT}/include/newlib
  PUBLIC SYSTEM ${WUEHANS_ROOT}/lib
  PUBLIC SYSTEM ${WUEHANS_ROOT}/wuehans
)

target_link_libraries(test.elf
  ${WUEHANS_ROOT}/lib/newlib/libc.a
  ${WUEHANS_ROOT}/lib/newlib/libg.a
  ${WUEHANS_ROOT}/lib/newlib/libgloss.a
  ${WUEHANS_ROOT}/lib/newlib/libm.a
  fatfs
  Hall
  # Graphic_Hans_API
)

target_sources(test.elf PUBLIC
  PUBLIC ${WUEHANS_ROOT}/wuehans/start.S
  PUBLIC ${WUEHANS_ROOT}/wuehans/syscall.c
  "test.cpp"
)

add_custom_command(TARGET test.elf POST_BUILD
  COMMAND objcopy ARGS -O verilog test.elf test.hex)

add_custom_command(TARGET test.elf POST_BUILD
  COMMAND python ARGS ${WUEHANS_ROOT}/tools/hex8tohex32.py test.hex > test32.hex
)
