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

add_executable (firmware.elf)

target_include_directories(firmware.elf
  # PUBLIC SYSTEM ${WUEHANS_ROOT}/include/libstdc++
  # PUBLIC SYSTEM ${WUEHANS_ROOT}/include/libstdc++/riscv32-unknown-elf
  PUBLIC SYSTEM ${WUEHANS_ROOT}/include/newlib
  PUBLIC SYSTEM ${WUEHANS_ROOT}/include
  PUBLIC SYSTEM ${WUEHANS_ROOT}/lib
  PUBLIC SYSTEM ${WUEHANS_ROOT}/wuehans
)

target_link_libraries(firmware.elf
  ${WUEHANS_ROOT}/lib/newlib/libc.a
  ${WUEHANS_ROOT}/lib/newlib/libg.a
  ${WUEHANS_ROOT}/lib/newlib/libgloss.a
  ${WUEHANS_ROOT}/lib/newlib/libm.a
  ${WUEHANS_ROOT}/lib/newlib/libgcc.a
  # ${WUEHANS_ROOT}/lib/libstdc++.a
  # ${WUEHANS_ROOT}/lib/libsupc++.a
  fatfs
  Hall
)

target_sources(firmware.elf PUBLIC
  PUBLIC ${WUEHANS_ROOT}/wuehans/start.S
  PUBLIC ${WUEHANS_ROOT}/wuehans/syscall.c

  "main.cpp"
)

# add_custom_command(TARGET firmware.elf POST_BUILD
#   COMMAND objcopy ARGS -O verilog firmware.elf test.hex)

# add_custom_command(TARGET firmware.elf POST_BUILD
#   COMMAND python ARGS ${WUEHANS_ROOT}/tools/hex8tohex32.py test.hex > test32.hex
# )
