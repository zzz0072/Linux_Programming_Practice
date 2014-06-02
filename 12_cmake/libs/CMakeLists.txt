# Build binary, inherit setting from parent
set(liba_SRCS liba.c)
set(libb_SRCS libb.c)

add_library(a SHARED ${liba_SRCS})
add_library(b SHARED ${libb_SRCS})

