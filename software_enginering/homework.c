#include <stdio.h>
#include <string.h>

typedef struct {
  int id;
  char name[50];
} Student;

typedef struct {
  int n;
  Student students[100];
} Students;

Students students = {4,
                     {{2017000001, "陈大"},
                      {2017000002, "王二"},
                      {2017000003, "张三"},
                      {2017000004, "李四"}}};

int seqSearch(int k) {
  for (int i = 0; i < students.n; i++) {
    if (students.students[i].id == k) {
      return i;
    }
  }
  return -1;
}

int binarySearch(int k) {
  int l = 0, r = students.n - 1, mid;
  while (l <= r) {
    mid = (l + r) >> 1;
    if (students.students[mid].id == k) {
      return mid;
    }
    if (students.students[mid].id > k)
      r = mid - 1;
    else
      l = mid + 1;
  }
  return -1;
}

int main() {
  printf("*****查找学生信息*****\n");
  printf("*    1 . 顺序查找    *\n");
  printf("*    2 . 二分查找    *\n");
  printf("*****输入信号运行*****\n");
  int choice, query, id;
  scanf("%d", &choice);
  printf("请输入要查询的学号:\n");
  scanf("%d", &query);
  switch (choice) {
    case 1:
      id = seqSearch(query);
      printf("该学生姓名为:%s\n", students.students[id].name);
      break;
    case 2:
      id = binarySearch(query);
      printf("该学生姓名为:%s\n", students.students[id].name);
      break;
    defalt:
      break;
  }
}