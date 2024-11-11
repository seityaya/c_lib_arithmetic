#Author                 : Seityagiya Terlekchi
#Contacts               : seityaya@ukr.net
#Creation Date          : 2020.05
#License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
#SPDX-License-Identifier: LGPL-2.1-or-later
#Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

cmake_minimum_required(VERSION 3.0)

project(define_test)

set(CMAKE_C_STANDARD 11)

file(GLOB FILES
    *.c
    *.h
    test_arithmetic/*.c
    test_bit/*.c
)

add_executable(
    ${PROJECT_NAME}
    ${FILES}
)

target_link_libraries(${PROJECT_NAME} PUBLIC yaya_testing)
