cmake_minimum_required(VERSION 3.20)

project(A4)

add_executable(A4 main.cpp)

# Demo run command
add_custom_target(run
        COMMENT "Run A4"
        COMMAND $<TARGET_FILE:A4> 
        DEPENDS A4
        USES_TERMINAL
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
