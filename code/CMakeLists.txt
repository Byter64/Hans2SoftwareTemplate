cmake_minimum_required(VERSION 3.24.0)
enable_language(C CXX ASM)
project("Cool game")

if(NOT DESKTOPBUILD)
  set(FINAL_TARGET game.elf)
else()
  set(FINAL_TARGET game)
endif()

add_executable(${FINAL_TARGET})

add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_SOURCE_DIR}/../cmake/cmake_copy.cmake
)
add_dependencies(${FINAL_TARGET} copy_assets)


#libstdc++ is not working properly currently. I would like to try out libc++, 
#I just need to get it compiled :(
if(NOT DESKTOPBUILD)
  target_include_directories(${FINAL_TARGET}
  #PUBLIC SYSTEM ${WUEHANS_ROOT}/system-include/libstdc++
  #PUBLIC SYSTEM ${WUEHANS_ROOT}/system-include/libstdc++/riscv32-unknown-elf
  PUBLIC SYSTEM ${WUEHANS_ROOT}/system-include
  PUBLIC SYSTEM ${WUEHANS_ROOT}/lib
  PUBLIC SYSTEM ${WUEHANS_ROOT}/system-include/newlib # This needs to be after libstdc++ because of include_nexts - JH
  PRIVATE include
  )

  target_link_libraries(${FINAL_TARGET}
  ${WUEHANS_ROOT}/lib/newlib/libc.a
  ${WUEHANS_ROOT}/lib/newlib/libg.a
  ${WUEHANS_ROOT}/lib/newlib/libgloss.a
  ${WUEHANS_ROOT}/lib/newlib/libm.a
  ${WUEHANS_ROOT}/lib/newlib/libgcc.a
  #${WUEHANS_ROOT}/lib/libstdc++.a
  #${WUEHANS_ROOT}/lib/libsupc++.a
  fatfs
  Halib
  )

  target_sources(${FINAL_TARGET} PUBLIC
  PUBLIC ${WUEHANS_ROOT}/wuehans/start.s
  PUBLIC ${WUEHANS_ROOT}/wuehans/start.cpp
  PUBLIC ${WUEHANS_ROOT}/wuehans/syscall.c
  )

else()
  target_link_libraries(${FINAL_TARGET}
  Halib_Desktop
  )
endif()

target_include_directories(${FINAL_TARGET}
  PUBLIC SYSTEM ${WUEHANS_ROOT}/wuehans
  PRIVATE include
)

#███████████████████████████████████████████████████████████
#███████████████████████████████████████████████████████████
#█████████████ Below starts your realm █████████████████████
#███████████████████████████████████████████████████████████
#███████████████████████████████████████████████████████████


target_sources(${FINAL_TARGET} PUBLIC
  # Add your .cpp files here
  "source/main.cpp"
)

# This is stuff for debugging the hardware. Just ignore it :)
# add_custom_command(TARGET ${FINAL_TARGET} POST_BUILD
#	COMMAND objcopy ARGS -O verilog ${FINAL_TARGET} Game.hex)
#
# add_custom_command(TARGET ${FINAL_TARGET} POST_BUILD
#	COMMAND python ARGS ${WUEHANS_ROOT}/wuehans/hex8tohex32.py Game.hex > Game32.hex
#)
