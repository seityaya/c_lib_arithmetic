#Author                 : Seityagiya Terlekchi
#Contacts               : seityaya@ukr.net
#Last Update Date       : 2024
#License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
#SPDX-License-Identifier: LGPL-2.1-or-later
#Copyright © Seityagiya Terlekchi. All rights reserved.

cmake_minimum_required(VERSION 3.0)

project(
    yaya_arithmetic
    VERSION      0.1.0.0
    LANGUAGES    C
    HOMEPAGE_URL "https://github.com/seityaya/c_lib_arithmetic"
    DESCRIPTION  "All arithmetic in one project"
)

set(CMAKE_C_STANDARD 23)

add_compile_options(-Wall -Wfatal-errors -Wconversion -Warith-conversion -Wfloat-conversion -Wsign-conversion -Wenum-conversion -Wno-missing-braces)

file(GLOB FILES *.c *.h)

add_library(${PROJECT_NAME} ${FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC yaya_macro)
