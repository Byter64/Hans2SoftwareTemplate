project("fatfs")
enable_language(C)

add_compile_options(-nostdlib
                    -DHAVE_MMAP=0 # don't compile MMAP
                    -D_LDBL_EQ_DBL=0 # no long double support
                    -fno-exceptions
)

add_link_options(-nostdlib)

add_library(fatfs STATIC
  diskio.c
  ff.c
  ffunicode.c
)

target_include_directories(fatfs
  PUBLIC SYSTEM ${WUEHANS_ROOT}/include/newlib
)

# target_link_libraries(fatfs
#   ${WUEHANS_ROOT}/lib/newlib/libc.a
#   ${WUEHANS_ROOT}/lib/newlib/libg.a
#   ${WUEHANS_ROOT}/lib/newlib/libgloss.a
#   ${WUEHANS_ROOT}/lib/newlib/libm.a
#   ${WUEHANS_ROOT}/lib/newlib/libgcc.a
# )
