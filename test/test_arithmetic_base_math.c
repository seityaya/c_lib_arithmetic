//Author                 : Seityagiya Terlekchi
//Contacts               : seityaya@ukr.net
//Creation Date          : 2023.02
//License Link           : https://spdx.org/licenses/LGPL-2.1-or-later.html
//SPDX-License-Identifier: LGPL-2.1-or-later
//Copyright © 2023-2023 Seityagiya Terlekchi. All rights reserved.

#include "yaya_unit.h"

#include "yaya_arithmetic.h"

UT_FUNC_GEN(test_arithmetic_base_math) {
    UT_GROUP_BEG(math) {
        UT_GROUP_BEG(sum) {
            UT_ASSERT_NUM_EQ(5, sum(1, sum(1, sum(1, sum(1, sum(1, 0)))))); //TODO: QtCreator crash

            UT_ASSERT_NUM_EQ(    2, sum(    1,    1));
            UT_ASSERT_NUM_EQ(    0, sum(   -1,    1));

            UT_ASSERT_FLT_EQ(  0.2, sum(  0.1,  0.1));
            UT_ASSERT_FLT_EQ(  0.0, sum( -0.1,  0.1));
        } UT_GROUP_END;


        UT_GROUP_BEG(dif) {
            UT_ASSERT_NUM_EQ(    0, dif(    1,    1));
            UT_ASSERT_NUM_EQ(   -2, dif(   -1,    1));

            UT_ASSERT_FLT_EQ(  0.0, dif(  0.1,  0.1));
            UT_ASSERT_FLT_EQ( -0.2, dif( -0.1,  0.1));
        } UT_GROUP_END;


        UT_GROUP_BEG(mul) {
            UT_ASSERT_NUM_EQ(    1, mul(    1,    1));
            UT_ASSERT_NUM_EQ(   -1, mul(   -1,    1));

            UT_ASSERT_FLT_EQ( 0.01, mul(  0.1,  0.1));
            UT_ASSERT_FLT_EQ(-0.01, mul( -0.1,  0.1));
        } UT_GROUP_END;


        UT_GROUP_BEG(div) {
            UT_ASSERT_NUM_EQ(    2, div(    5,    2));
            UT_ASSERT_NUM_EQ(   -2, div(    5,   -2));
            UT_ASSERT_NUM_EQ(    3, div(    6,    2));
            UT_ASSERT_NUM_EQ(   -3, div(    6,   -2));

            UT_ASSERT_NUM_EQ(   -2, div(   -5,    2));
            UT_ASSERT_NUM_EQ(   -3, div(   -6,    2));

            UT_ASSERT_FLT_EQ( 13.0, div(  4.0,  0.3));
            UT_ASSERT_FLT_EQ(-13.0, div(  4.0, -0.3));

            UT_ASSERT_FLT_EQ(  3.0, div(12.77,  3.4));
            UT_ASSERT_FLT_EQ( -3.0, div(12.77, -3.4));
        } UT_GROUP_END;


        UT_GROUP_BEG(mod) {
            UT_ASSERT_NUM_EQ(    1, mod(    4,    3));
            UT_ASSERT_NUM_EQ(    1, mod(    5,    2));
            UT_ASSERT_NUM_EQ(    1, mod(    5,   -2));
            UT_ASSERT_NUM_EQ(    0, mod(    6,    2));
            UT_ASSERT_NUM_EQ(    0, mod(    6,   -2));
            UT_ASSERT_NUM_EQ(   -1, mod(   -5,    2));
            UT_ASSERT_NUM_EQ(    0, mod(   -6,    2));

            UT_ASSERT_FLT_EQ(  0.1, mod(  4.0,  0.3));
            UT_ASSERT_FLT_EQ(  0.1, mod(  4.0, -0.3));
            UT_ASSERT_FLT_EQ( -0.1, mod( -4.0,  0.3));
            UT_ASSERT_FLT_EQ( -0.1, mod( -4.0, -0.3));
        } UT_GROUP_END;


        UT_GROUP_BEG(div_mod) {
#define DIV_MOD(x, y) (((y) * div(x, y) + mod(x, y)) == (x))
            UT_ASSERT_BOOL_TR(DIV_MOD(   5,   2));
            UT_ASSERT_BOOL_TR(DIV_MOD(   5,  -2));
            UT_ASSERT_BOOL_TR(DIV_MOD(   6,   2));
            UT_ASSERT_BOOL_TR(DIV_MOD(   6,  -2));
            UT_ASSERT_BOOL_TR(DIV_MOD(  -6,   2));
            UT_ASSERT_BOOL_TR(DIV_MOD(  -6,  -2));
            UT_ASSERT_BOOL_TR(DIV_MOD(  -5,   2));
            UT_ASSERT_BOOL_TR(DIV_MOD(  -6,   2));
            UT_ASSERT_BOOL_TR(DIV_MOD( -20,   7));

            UT_ASSERT_BOOL_TR(DIV_MOD( 4.0, 0.3));
            UT_ASSERT_BOOL_TR(DIV_MOD( 4.0,-0.3));
            UT_ASSERT_BOOL_TR(DIV_MOD(-4.0, 0.3));
            UT_ASSERT_BOOL_TR(DIV_MOD(-4.0,-0.3));
        } UT_GROUP_END;


        UT_GROUP_BEG(qut) {
            UT_ASSERT_FLT_EQ(fmax_c(+0.333333333333333333342368351437379203616728773340582847595214843750L), qut(   1,    3));
            UT_ASSERT_FLT_EQ(fmax_c(+1.333333333333333333369473405749516814466915093362331390380859375000L), qut(   4,    3));

            UT_ASSERT_FLT_EQ(fmax_c(+0.333333333333333333342368351437379203616728773340582847595214843750L), qut( 1.0,  3.0));
            UT_ASSERT_FLT_EQ(fmax_c(+1.333333333333333333369473405749516814466915093362331390380859375000L), qut( 4.0,  3.0));
            UT_ASSERT_FLT_EQ(fmax_c(               1.25), qut( 5.0,  4.0));
            UT_ASSERT_FLT_EQ(fmax_c(                1.0), qut( 5.0,  5.0));
            UT_ASSERT_FLT_EQ(fmax_c(                0.0), qut( 0.0,  5.0));
            UT_ASSERT_FLT_EQ(fmax_c(           INFINITY), qut( 5.0,  0.0));

            UT_ASSERT_FLT_EQ(fmax_c(-0.333333333333333333342368351437379203616728773340582847595214843750L), qut( -1.0, 3.0));
            UT_ASSERT_FLT_EQ(fmax_c(-1.333333333333333333369473405749516814466915093362331390380859375000L), qut( -4.0, 3.0));
            UT_ASSERT_FLT_EQ(fmax_c(              -1.25), qut( -5.0, 4.0));
            UT_ASSERT_FLT_EQ(fmax_c(               -1.0), qut( -5.0, 5.0));
            UT_ASSERT_FLT_EQ(fmax_c(               -0.0), qut( -0.0, 5.0));
            UT_ASSERT_FLT_EQ(fmax_c(          -INFINITY), qut( -5.0, 0.0));
        } UT_GROUP_END;


        UT_GROUP_BEG(powm) {
            UT_ASSERT_FLT_EQ(8.0, powm( 2.0,  3.0));
            UT_ASSERT_FLT_EQ(3.0, powm( 9.0,  0.5));

            UT_ASSERT_FLT_EQ(0.33333333333333333, powm( 9.0, -0.5));

            UT_ASSERT_NUM_EQ(umax_c( 8), powm(umax_c(2), umax_c(3)));
            UT_ASSERT_NUM_EQ(umax_c(81), powm(umax_c(9), umax_c(2)));
        } UT_GROUP_END;


        UT_GROUP_BEG(root) {
            UT_ASSERT_FLT_EQ(  4.0, root(16.0,  2.0));
            UT_ASSERT_FLT_EQ(  2.0, root( 8.0,  3.0));
            UT_ASSERT_FLT_EQ(  9.0, root( 3.0,  0.5));

            UT_ASSERT_FLT_EQ_E(9.0, root( 0.33333333333333333333333, -0.5), 0.00000000000001);
        } UT_GROUP_END;


        UT_GROUP_BEG(logm) {
            UT_ASSERT_FLT_EQ(                 3.0, logm(8.0 , 2.0 ));
            UT_ASSERT_FLT_EQ(                 2.0, logm(9.0 , 3.0));
            UT_ASSERT_FLT_EQ( 0.33333333333333333, logm( 9.0, -0.5));
        } UT_GROUP_END;











//        UT_GROUP_BEG(gcd) {
//            UT_ASSERT_NUM_EQ(umax_c(  0), gcd(umax_c( 0), umax_c( 0)));
//            UT_ASSERT_NUM_EQ(umax_c(  1), gcd(umax_c( 0), umax_c( 1)));
//            UT_ASSERT_NUM_EQ(umax_c(  1), gcd(umax_c( 1), umax_c( 0)));
//            UT_ASSERT_NUM_EQ(umax_c(  1), gcd(umax_c( 1), umax_c( 1)));
//            UT_ASSERT_NUM_EQ(umax_c(  4), gcd(umax_c(16), umax_c(20)));
//            UT_ASSERT_NUM_EQ(umax_c(  7), gcd(umax_c(21), umax_c( 7)));
//            UT_ASSERT_NUM_EQ(umax_c(  1), gcd(umax_c(36), umax_c( 5)));
//            UT_ASSERT_NUM_EQ(umax_c(  5), gcd(umax_c(35), umax_c( 5)));
//            UT_ASSERT_NUM_EQ(umax_c(  5), gcd(umax_c( 5), umax_c(35)));
//        } UT_GROUP_END;


//        UT_GROUP_BEG(lcm) {
//            UT_ASSERT_NUM_EQ(umax_c(  0), lcm(umax_c( 0), umax_c(  0)));
//            UT_ASSERT_NUM_EQ(umax_c(  0), lcm(umax_c( 0), umax_c(  1)));
//            UT_ASSERT_NUM_EQ(umax_c(  0), lcm(umax_c( 1), umax_c(  0)));
//            UT_ASSERT_NUM_EQ(umax_c(  1), lcm(umax_c( 1), umax_c(  1)));
//            UT_ASSERT_NUM_EQ(umax_c( 80), lcm(umax_c(16), umax_c(20)));
//            UT_ASSERT_NUM_EQ(umax_c( 21), lcm(umax_c(21), umax_c( 7)));
//            UT_ASSERT_NUM_EQ(umax_c(180), lcm(umax_c(36), umax_c( 5)));
//            UT_ASSERT_NUM_EQ(umax_c(180), lcm(umax_c(36), umax_c( 5)));
//        } UT_GROUP_END;
    } UT_GROUP_END;
}
