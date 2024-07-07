#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
    char name[64];
    int age;
    int Id;
    double score;
};

// 将 struct Person p 改为 struct Person *p 节省资源
// const 使用，修饰行参，防止误操作
void showPerson(const struct Person *p) {
  printf("name: %s, age: %d, in: %d, score: %f\n", p->name, p->age, p->Id, p->score);
}

void test01() {
  struct Person p = {"Tom", 18, 1,60};
  showPerson(&p);
}

int main() {
  test01();
  return EXIT_SUCCESS;
}