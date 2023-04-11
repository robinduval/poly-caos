/* 
 * INF559 Data Lab 
 * 
 * Robin DUVAL
  * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#endif

/* Copyright (C) 1991-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* We do support the IEC 559 math functionality, real and complex.  */
/* wchar_t uses ISO/IEC 10646 (2nd ed., published 2011-03-15) /
   Unicode 6.0.  */
/* We do not support C11 <threads.h>.  */


/* bit manipulation */

/*
 * func1 - returns 1 if x == 0, and 0 otherwise 
 *   Examples: func1(5) = 0, func1(0) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int func1(int x) {

  return !x;
}

/* 
 * func2 - ~(x|y) using only ~ and & 
 *   Example: func2(0x6, 0x5) = 0xFFFFFFF8
 *   Legal ops: ~ &
 *   Max ops: 8
 *   Rating: 1
 */
int func2(int x, int y) {
  return ~x & ~y;
}

/* 
 * func3 - x&~y using only ^ and &
 *   Example: func3(1,2) = 1, func3(0,1) = 0, 0
 *   Legal ops: ^ &
 *   Max ops: 8
 *   Rating: 1
 */
int func3(int x, int y) {
  return x & (x ^ y);
}

/* 
 * func4 - swap the first 16 bits of x with the last 16 bits of x
 *   Examples: func4(0x87654321) = 0x87654321, func4(0x12345678) = 0x56781234
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 2
 */
int func4(int x) {
    int high_mask = (0xFF << 8) | 0xFF;   // 0x0000FFFF
    int first16b = (x >> 16) & high_mask; // Extract the first 16 bits of x by right-shifting x by 16 and masking with high_mask.
    int last16b = x & high_mask;          // Extract the last 16 bits of x by simply masking x with high_mask.

    return (last16b << 16) | first16b;    // Shift the last 16 bits to the left by 16 positions, and then use the bitwise OR operation to merge the first 16 bits into the result.
}

/* 
 * func5 - set all bits of result to least significant bit (lsb) of x
 *         FR : init tous les bits du résultat sur le lsb.
 *   Example: func5(5) = 0xFFFFFFFF, func5(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int func5(int x) {
    int lsb = x & 1;               // Extract the least significant bit of x
    int mask = (lsb << 31) >> 31;  // Create a mask with all bits set to the least significant bit of x
 
    return mask;
}

/* 
 * func6 - return 1 if all even-numbered bits in word set to 1
 *         FR : renvoie 1 si tous les bits de numéros pairs dans le mot sont définis à 1, sinon elle renvoie 0.
 *   Examples func6(0xFFFFFFFE) = 0, func6(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int func6(int x) {
    int mask = (0x55 << 8) | 0x55;      // 0x00005555
    int mask2 = (mask << 16) | mask;    // 0x55555555
    int even_bits = x & mask2;
    int result = !(even_bits ^ mask2);

    return result;
}

/* 
 * func7 - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: func7(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int func7(int x, int n) {
    int mask = ~(((1 << 31) >> n) << 1);  // Create a mask with n 0 bits on the right
    int shifted = x >> n;                 // Shift x to the right by n

    return shifted & mask;                // Return x shifted by n with the rightmost n bits masked out
}

/*  2's complement  */

/* 
 * func8 - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int func8(void) {
    return ~0 << 31;                              // Shift the bitwise negation of 0 to the left by 31 positions
}

/*
 * func9 - returns 1 if x is the maximum, two's complement number and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int func9(int x) {
    int mask = 0xFF;
    int max_twos_complement = ~(1 << 31);
    int twos_complement = (x ^ max_twos_complement) + 1;
    int sign_bit = twos_complement >> 31;
    int is_max_twos_comp = !(sign_bit | ((twos_complement | mask) ^ mask));
    
    return is_max_twos_comp;
}
/* 
 * func10 - return -x 
 *   Example: func10(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int func10(int x) {
  return (~x) + 1;
}

/* 
 * func11 - Determine if can compute x+y without overflow 
 *   Example: func11(0x80000000,0x80000000) = 0,
 *            func11(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int func11(int x, int y) {
    int sum = x + y;                                            // Compute the sum of x and y
    int sign_x = x >> 31;                                       // Extract the sign of x
    int sign_y = y >> 31;                                       // Extract the sign of y
    int sign_sum = sum >> 31;                                   // Extract the sign of the sum
    int overflow = (sign_x ^ sign_sum) & (sign_y ^ sign_sum);   // Check for overflow

    return !overflow;                                           // Return true if no overflow occurred, false otherwise
}

/* 
 * func12 - if x > y  then return 1, else return 0 
 *   Example: func12(4,5) = 0, func12(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int func12(int x, int y) {
  //int diff = x + (~y + 1);
  //int sign_bit = (diff >> 31) & 1;

  //return !sign_bit;
  return 2;
}

/*
 * func13 - adds two numbers but when positive overflow occurs, returns
 *          maximum possible value, and when negative overflow occurs,
 *          it returns minimum positive value.
 *   Examples: func13(0x40000000,0x40000000) = 0x7fffffff
 *             func13(0x80000000,0xffffffff) = 0x80000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 30
 *   Rating: 4
 */
int func13(int x, int y) {
    int sum = x + y;                                                              // Compute the sum of x and y

    int is_negative_x = (x >> 31) & 1;                                            // Check if x is negative
    int is_negative_y = (y >> 31) & 1;                                            // Check if y is negative
    int is_negative_sum = (sum >> 31) & 1;                                        // Check if the sum is negative

    int is_negative_overflow = is_negative_x & is_negative_y & ~is_negative_sum;  // Check if the overflow is negative
    int is_positive_overflow = ~is_negative_x & ~is_negative_y & is_negative_sum; // Check if the overflow is positive

    int max_val = ~(1 << 31);                                                     // Set the maximum value that can be represented by a 32-bit two's complement integer
    int min_val = 1 << 31;                                                        // Set the minimum value that can be represented by a 32-bit two's complement integer

    int overflow = is_negative_overflow | is_positive_overflow;                   // Compute the overflow flag
    int sign = (x >> 31) & 1;                                                     // Compute the sign of x

    int overflow_val = overflow & ((sign & min_val) | (~sign & max_val));         // Compute the overflow value
    int sum_val = ~overflow & sum;                                                // Compute the sum value

    return overflow_val | sum_val;                                                // Return the final result
}
