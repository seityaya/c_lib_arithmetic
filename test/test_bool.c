// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_bool.h"

UT_FUNC_GEN(test_bool) {
    UT_GROUP_BEG(bool) {
        UT_GROUP_BEG(macro) {
            UT_ASSERT_BOOL_TR(true);
            UT_ASSERT_BOOL_FL(false);
        } UT_GROUP_END;

        UT_GROUP_BEG(type) {
            bool_t A = false;
            UT_ASSERT_BOOL_FL(A);
            A = 0;
            UT_ASSERT_BOOL_FL(A);

            A = true;
            UT_ASSERT_BOOL_TR(A);
            A = 1;
            UT_ASSERT_BOOL_TR(A);
            A = 2;
            UT_ASSERT_BOOL_TR(A);
        } UT_GROUP_END;
    } UT_GROUP_END;
}
