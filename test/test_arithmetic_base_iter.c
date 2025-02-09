// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_base_iter) {
UT_GROUP_BEG(iter) {
        UT_GROUP_BEG(num_prev_integer) {
            UT_ASSERT_NUM_EQ(u8_c(   1), num_prev(u8_c(   2)));
            UT_ASSERT_NUM_EQ(u8_c(   0), num_prev(u8_c(   1)));
            UT_ASSERT_NUM_EQ(u8_c(   0), num_prev(u8_c(   0)));

            UT_ASSERT_NUM_EQ(s8_c(1), num_prev(s8_c(2)));
            UT_ASSERT_NUM_EQ(s8_c(0), num_prev(s8_c(1)));
            UT_ASSERT_NUM_EQ(s8_c(-1), num_prev(s8_c(0)));
            UT_ASSERT_NUM_EQ(s8_c(-128), num_prev(s8_c(-128)));
            UT_ASSERT_NUM_EQ(s8_c(126), num_prev(s8_c(127)));
        } UT_GROUP_END;

        UT_GROUP_BEG(num_next_integer) {
            UT_ASSERT_NUM_EQ(u8_c( 255), num_next(u8_c( 255)));
            UT_ASSERT_NUM_EQ(u8_c(   1), num_next(u8_c(   0)));
            UT_ASSERT_NUM_EQ(u8_c(   2), num_next(u8_c(   1)));

            UT_ASSERT_NUM_EQ(s8_c(0), num_next(s8_c(-1)));
            UT_ASSERT_NUM_EQ(s8_c(1), num_next(s8_c(0)));
            UT_ASSERT_NUM_EQ(s8_c(2), num_next(s8_c(1)));
            UT_ASSERT_NUM_EQ(s8_c(-127), num_next(s8_c(-128)));
            UT_ASSERT_NUM_EQ(s8_c(127), num_next(s8_c(127)));
        } UT_GROUP_END;

        UT_GROUP_BEG(num_after_integer) {
            UT_ASSERT_NUM_EQ(u8_c(   0), num_appr(u8_c(   0), u8_c(    0)));
            UT_ASSERT_NUM_EQ(u8_c(   1), num_appr(u8_c(   1), u8_c(    1)));

            UT_ASSERT_NUM_EQ(s8_c(1), num_appr(s8_c(0), s8_c(3)));
            UT_ASSERT_NUM_EQ(s8_c(2), num_appr(s8_c(1), s8_c(3)));
            UT_ASSERT_NUM_EQ(s8_c(3), num_appr(s8_c(2), s8_c(3)));
            UT_ASSERT_NUM_EQ(s8_c(3), num_appr(s8_c(3), s8_c(3)));

            UT_ASSERT_NUM_EQ(s8_c(-1), num_appr(s8_c(0), s8_c(-3)));
            UT_ASSERT_NUM_EQ(s8_c(-2), num_appr(s8_c(-1), s8_c(-3)));
            UT_ASSERT_NUM_EQ(s8_c(-3), num_appr(s8_c(-2), s8_c(-3)));
            UT_ASSERT_NUM_EQ(s8_c(-3), num_appr(s8_c(-3), s8_c(-3)));
        } UT_GROUP_END;

        UT_GROUP_BEG(num_prev_next_float) {
            UT_ASSERT_FLT_EQ(fmax_c(-0.0), num_prev(fmax_c(+0.0)));
            UT_ASSERT_FLT_EQ(fmax_c(+0.0), num_next(fmax_c(-0.0)));

            UT_ASSERT_FLT_EQ(fmax_c( 1.0), num_next(num_prev(fmax_c( 1.0))));
            UT_ASSERT_FLT_EQ(fmax_c( 1.0), num_prev(num_next(fmax_c( 1.0))));
        } UT_GROUP_END;
    } UT_GROUP_END;
}
