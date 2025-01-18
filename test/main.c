// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// Creation Date          : 2020.05
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © 2020-2023 Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

UT_FUNC_GEN(test_arithmetic_base_conv);
UT_FUNC_GEN(test_arithmetic_base_inverse);
UT_FUNC_GEN(test_arithmetic_base_isnum);
UT_FUNC_GEN(test_arithmetic_base_iter);
UT_FUNC_GEN(test_arithmetic_base_logical);
UT_FUNC_GEN(test_arithmetic_base_math_chk);
UT_FUNC_GEN(test_arithmetic_base_math);
UT_FUNC_GEN(test_arithmetic_base_minmax);
UT_FUNC_GEN(test_arithmetic_base_segment);
UT_FUNC_GEN(test_arithmetic_base_unar);
UT_FUNC_GEN(test_arithmetic_base);
UT_FUNC_GEN(test_arithmetic_combinatoric);
UT_FUNC_GEN(test_arithmetic_progresion);
UT_FUNC_GEN(test_arithmetic_round);
UT_FUNC_GEN(test_arithmetic_series);

int main(void) {
    unit_test_p MyUnTest = nullptr;

    unit_test_sett_t MyUnSett = {
        .suse = false,
        .stat = true,
    };

    // clang-format off
    unit_test_func_t MyUnFunc[] = {
        {test_arithmetic_base_conv        , 1},
        {test_arithmetic_base_inverse     , 1},
        {test_arithmetic_base_isnum       , 1},
        {test_arithmetic_base_iter        , 1},
        {test_arithmetic_base_logical     , 1},
        {test_arithmetic_base_math_chk    , 1},
        {test_arithmetic_base_math        , 1},
        {test_arithmetic_base_minmax      , 1},
        {test_arithmetic_base_segment     , 1},
        {test_arithmetic_base_unar        , 1},
        {test_arithmetic_base             , 1},
        {test_arithmetic_combinatoric     , 1},
        {test_arithmetic_progresion       , 1},
        {test_arithmetic_round            , 1},
        {test_arithmetic_series           , 1},
        {NULL                             , 0},
    };
    // clang-format on

    unit_test_init(&MyUnTest, MyUnFunc, &MyUnSett);

    unit_test_print(MyUnTest);

    unit_test_start(MyUnTest);

    unit_test_stats(MyUnTest);

    unit_test_free(&MyUnTest);

    return 0;
}
