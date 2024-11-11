#Author                 : Seityagiya Terlekchi
#Contacts               : seityaya@ukr.net
#Last Update Date       : 2024
#License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
#SPDX-License-Identifier: LGPL-2.1-or-later
#Copyright © Seityagiya Terlekchi. All rights reserved.

cmake_minimum_required(VERSION 3.0)

project(
    yaya_define
    VERSION      0.1.0.0
    LANGUAGES    C
    HOMEPAGE_URL "https://github.com/seityaya/c_lib_define"
    DESCRIPTION  "All define in one project"
)

set(CMAKE_C_STANDARD 23)

set(VERSION 0.1)

#add_compile_options(-Wall -Wfatal-errors -Wconversion -Warith-conversion -Wfloat-conversion -Wsign-conversion -Wenum-conversion)

file(GLOB FILES
    *.c
    *.h
)

set(SOURSE_LIST                        #decor    #impl     #test
    yaya_argcount.h                    #100%     #100%     #100%
    yaya_arithmetic_constant.h         #100%     #100%     #----
    yaya_arithmetic_discrete.h         #         #         #
    yaya_arithmetic_round.h            #         #         #
    yaya_arithmetic.c                  #         #         #
    yaya_arithmetic.h                  #100%     #         #
    yaya_bit.c                         #100%     #100%     #100%
    yaya_bit.h                         #100%     #100%     #100%
    yaya_bool.h                        #100%     #100%     #100%
    yaya_cdecl.h                       #100%     #100%     #----
    yaya_check.h                       #100%     #100%     #100%
    yaya_concat.h                      #100%     #100%     #100%
    yaya_debug.c                       #100%     #100%     #100%
    yaya_debug.h                       #100%     #100%     #100%
    yaya_endian.h                      #100%     #100%     #100%
    yaya_flag.h                        #100%     #         #
    yaya_gover.h                       #100%     #100%     #----
    yaya_rand.c                        #         #         #
    yaya_rand.h                        #         #         #
    yaya_sugar.h                       #100%     #100%     # 50%
    yaya_type.h                        #100%     #100%     #100%
    yaya_unused.h                      #100%     #100%     #100%

    ${FILES}
)

add_library(${PROJECT_NAME} ${SOURSE_LIST})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
