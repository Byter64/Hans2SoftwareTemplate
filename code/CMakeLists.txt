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

add_executable (Game.elf)

target_include_directories(Game.elf
  PUBLIC SYSTEM ${WUEHANS_ROOT}/system-include/newlib
  PUBLIC SYSTEM ${WUEHANS_ROOT}/system-include
  PUBLIC SYSTEM ${WUEHANS_ROOT}/lib
  PUBLIC SYSTEM ${WUEHANS_ROOT}/wuehans
)

target_link_libraries(Game.elf
  ${WUEHANS_ROOT}/lib/newlib/libc.a
  ${WUEHANS_ROOT}/lib/newlib/libg.a
  ${WUEHANS_ROOT}/lib/newlib/libgloss.a
  ${WUEHANS_ROOT}/lib/newlib/libm.a
  ${WUEHANS_ROOT}/lib/newlib/libgcc.a
  fatfs
  Hall
)

target_sources(Game.elf PUBLIC
  PUBLIC ${WUEHANS_ROOT}/wuehans/start.S
  PUBLIC ${WUEHANS_ROOT}/wuehans/syscall.c

  # Add your .cpp files here
  "main.cpp"
)
