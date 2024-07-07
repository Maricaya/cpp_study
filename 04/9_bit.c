#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test01() {
  int num = 2;
  // 010 取反
  // 101 源码
  // 计算机用补码的方式存数据 110+1 = 111
  printf("~num=%d", ~num);
}

/*
 *  5 - 0101
 *  3 - 0011
 *      0111 = 7
 *
 *
 *  A    01010101
 *  B    00011100
 *  R    01001001
 *
 *  A^B=R
 *  A^R=B
 *  B^R=A
 *
 *
 */

void test04() {
  int num1 = 5;
  int num2 = 9;
//  num1 = num1^num2;
//  num2 = num1^num2;
//  num1 = num2^num1;

  num1 = num1+num2;
  num2 = num1-num2;
  num1 = num1-num2;

  printf("%d, %d", num1, num2);
}

// <<x 相当于乘以 2^x
// >>x 相当于除以 2^x
  // positive number, 有些机器用0填充高位
  // negative number, 有些机器用1填充高位
  // 如果是无符号，都是用0填充

int main() {
  test04();
  return EXIT_SUCCESS;
}