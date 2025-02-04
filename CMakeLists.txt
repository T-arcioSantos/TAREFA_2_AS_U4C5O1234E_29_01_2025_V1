# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

cmake_minimum_required(VERSION 3.13)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PICO_BOARD pico_w CACHE STRING "Board type")

include(pico_sdk_import.cmake)
project(TAREFA_2_AS_U4C5O1234E_29_01_2025_V1 C CXX ASM)
pico_sdk_init()
add_executable(TAREFA_2_AS_U4C5O1234E_29_01_2025_V1 TAREFA_2_AS_U4C5O1234E_29_01_2025_V1.c )
pico_set_program_name(TAREFA_2_AS_U4C5O1234E_29_01_2025_V1 "TAREFA_2_AS_U4C5O1234E_29_01_2025_V1")
target_link_libraries(TAREFA_2_AS_U4C5O1234E_29_01_2025_V1 pico_stdlib)
pico_add_extra_outputs(TAREFA_2_AS_U4C5O1234E_29_01_2025_V1)


