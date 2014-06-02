# Build binary, inherit setting from parent
set(liba_SRCS liba.c)
set(libb_SRCS libb.c)

add_library(a ${liba_SRCS})
add_library(b ${libb_SRCS})

