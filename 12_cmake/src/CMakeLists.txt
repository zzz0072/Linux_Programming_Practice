# Build binary
set(test_SRCS test.c)
add_executable(${PROJECT_NAME} ${test_SRCS})
target_link_libraries(${PROJECT_NAME} a b)

# Install
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
