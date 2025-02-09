// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_base_minmax) {
    UT_GROUP_BEG(minmax) {
        UT_GROUP_BEG(min) {
            UT_ASSERT_NUM_EQ(  1, min( 1, 2));
            UT_ASSERT_NUM_EQ( -2, min(-1,-2));
        } UT_GROUP_END;

        UT_GROUP_BEG(max) {
            UT_ASSERT_NUM_EQ(  2, max( 1, 2));
            UT_ASSERT_NUM_EQ( -1, max(-1,-2));
        } UT_GROUP_END;

        UT_GROUP_BEG(min_not_zero) {
            UT_ASSERT_NUM_EQ(  0, min_not_zero( 0, 0));
            UT_ASSERT_NUM_EQ(  0, min_not_zero( 0, 0));

            UT_ASSERT_NUM_EQ(  1, min_not_zero( 1, 2));
            UT_ASSERT_NUM_EQ( -2, min_not_zero(-1,-2));

            UT_ASSERT_NUM_EQ(  1, min_not_zero( 1, 0));
            UT_ASSERT_NUM_EQ( -1, min_not_zero(-1, 0));
        } UT_GROUP_END;

        UT_GROUP_BEG(max_not_zero) {
            UT_ASSERT_NUM_EQ(  0, max_not_zero( 0, 0));
            UT_ASSERT_NUM_EQ(  0, max_not_zero( 0, 0));

            UT_ASSERT_NUM_EQ(  2, max_not_zero( 1, 2));
            UT_ASSERT_NUM_EQ( -1, max_not_zero(-1,-2));

            UT_ASSERT_NUM_EQ(  1, max_not_zero( 1, 0));
            UT_ASSERT_NUM_EQ( -1, max_not_zero(-1, 0));
        } UT_GROUP_END;

        UT_GROUP_BEG(minmax_init) {
            int min =  10;
            int max = -10;
            minmax_init(min, max);
            UT_ASSERT_NUM_EQ(INT_MAX, min);
            UT_ASSERT_NUM_EQ(INT_MIN, max);
        } UT_GROUP_END;

        UT_GROUP_BEG(minmax_set) {
            int min =  10;
            int max = -10;
            UT_ASSERT_NUM_EQ( 10, min);
            UT_ASSERT_NUM_EQ(-10, max);
            minmax_set(0, min, max);
            UT_ASSERT_NUM_EQ(  0, min);
            UT_ASSERT_NUM_EQ(  0, max);
            minmax_set(10, min, max);
            UT_ASSERT_NUM_EQ(  0, min);
            UT_ASSERT_NUM_EQ( 10, max);
            minmax_set(-10, min, max);
            UT_ASSERT_NUM_EQ(-10, min);
            UT_ASSERT_NUM_EQ( 10, max);
        } UT_GROUP_END;

        UT_GROUP_BEG(minmax_not_zero_set) {
            int min =  10;
            int max = -10;
            UT_ASSERT_NUM_EQ( 10, min);
            UT_ASSERT_NUM_EQ(-10, max);
            minmax_not_zero_set(0, min, max);
            UT_ASSERT_NUM_EQ( 10, min);
            UT_ASSERT_NUM_EQ(-10, max);
            minmax_not_zero_set(10, min, max);
            UT_ASSERT_NUM_EQ( 10, min);
            UT_ASSERT_NUM_EQ( 10, max);
            minmax_not_zero_set(-10, min, max);
            UT_ASSERT_NUM_EQ(-10, min);
            UT_ASSERT_NUM_EQ( 10, max);
        } UT_GROUP_END;
    } UT_GROUP_END;
}
