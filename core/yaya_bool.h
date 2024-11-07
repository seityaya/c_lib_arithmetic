// Author                 : Seityagiya Terlekchi
// Contacts               : seityaya@ukr.net
// License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
// SPDX-License-Identifier: LGPL-2.1-or-later
// Copyright © Seityagiya Terlekchi. All rights reserved.

#ifndef YAYA_BOOL_H
#define YAYA_BOOL_H

#include "stdbool.h"

// clang-format off
#include "yaya_cdecl.h"
BEG_C_DECLARATION

//================= BOOL =============================================================================================================================

#ifdef bool
    #undef  bool
    #define bool_t  _Bool
#else
    typedef enum bool_t {
        true  = 1,
        false = 0
    } bool_t;
#endif

//====================================================================================================================================================

END_C_DECLARATION
// clang-format on
#endif /*YAYA_BOOL_H*/
