#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma pack(show) // 查看当前对其 模数，对其模数⬆可以修改，
// 默认对其模数是8

// 2^n
// 第一个属性开始 从0开始偏移
// 第二个属性开始 要放在 该类型的大小 与 对其模数比 取小的值 的增数倍。
// 所有的属性都计算完成后，再整体做二次偏移，将整体计算的结果，要放在 结构体最大类型 与 对其模数比 取小的值的 整数倍上
typedef struct _STUDENT {
    int a;    // 4 0~3       0～3
    char b;   // 1 4~7      4
    double c; // 8 8~15   5~12
    float d;  // 4 16~19   13~16
} Student;

void test01() {
  printf("sizeof student = %d\n", sizeof(Student));
}

// 结构体嵌套结构体的时候，子结构体放在该结构体中最大的类型 和 对其模数比 的整数倍上
typedef struct _STUDENT2 {
    char a; // 0～7
    Student b; // 8～31
    double c; // 32～39
} Student2;

void test02() {
  printf("sizeof student = %d\n", sizeof(Student2));
}

int main() {
  test01();
  test02();
  return EXIT_SUCCESS;
}