//// dsacpp.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
////
//
//#include "Vector.h"
//
//#include <iostream>
//
// int testID = 0;  // vector测试单元编号
//
////格式化输出vector
//#define PRINT(x)   \
//  {                \
//    print(x);      \
//    crc(x);        \
//    checkOrder(x); \
//  }
//
////向量测试接口，支持多种类型
// template <typename T>
// void testVector(int testSize) {
//  printf("\n  ==== Test %2d. Generate a random vector\n", testID++);
//  //构造一个容量为357，元素在[0, 3 * 357]内随机组成的向量
//  // dice生成的随机数依赖于srand设定的随机数种子
//  Vector<T> V;
//  for (int i = 0; i < testSize; i++) {
//    V.insert(dice(i + 1), dice((T)testSize * 3));
//  }
//  PRINT(V);
//  //将向量乱序排列
//  permute(V);
//  PRINT(V);
//
//  printf("\n  ==== Test %2d. Lowpass on\n", testID++);
//  PRINT(V);
//  // f(n) = (f(n) * 7 + f(n + 1)) >> 3
//  int i = V.size();
//  while (0 < --i) {
//    V[i - 1] *= 7;
//    V[i - 1] += V[i];
//    V[i - 1] >>= 3;
//  }
//  PRINT(V);
//
//  printf("\n  ==== Test %2d. Increase\n", testID++);
//  PRINT(V);
//  increase(V);
//  PRINT(V);
//
//  printf("\n  ==== Test %2d. FIND in\n", testID++);
//  PRINT(V);
//  TestFind<T>(V, testSize);
//
//  // size不能被5整除时输出7次，循环6次，sort(i,
//  // i)退化区间没有排序，所有输出是一样的
//  printf("\n  ==== Test %2d. Sort degenerate intervals each of size 1 in\n",
//         testID++);
//  PRINT(V);
//  for (int i = 0; i < V.size(); i += V.size() / 5) {
//    V.sort(i, i);
//    PRINT(V);
//  }  // element by element
//
//  //排序
//  printf("\n  ==== Test %2d. Sort %d intervals each of size <=%d in\n",
//         testID++, 5 + (V.size() % 5 > 0), V.size() / 5);
//  PRINT(V);
//  for (int i = 0; i < V.size(); i += V.size() / 5) {
//    V.sort(i, min(V.size(), i + V.size() / 5));
//    PRINT(V);
//    printf("[%d , %d)\n", i, min(V.size(), i + V.size() / 5));
//  }  // interval by interval
//
//  printf("\n  ==== Test %2d. Sort the entire vector of\n", testID++);
//  PRINT(V);
//  V.sort();
//  PRINT(V);
//
//  printf("\n  ==== Test %2d. FIND in\n", testID++);
//  PRINT(V);
//  TestFind<T>(V, testSize);
//
//  printf("\n  ==== Test %2d. SEARCH in\n", testID++);
//  PRINT(V);
//  TestSearch<T>(V);
//
//  printf("\n  ==== Test %2d. Unsort interval [%d, %d) in\n", testID++,
//         V.size() / 4, 3 * V.size() / 4);
//  PRINT(V);
//  V.unsort(V.size() / 4, 3 * V.size() / 4);
//  PRINT(V);
//
//  printf("\n  ==== Test %2d. Unsort interval [%d, %d) in\n", testID++, 0,
//         V.size());
//  PRINT(V);
//  V.unsort();
//  PRINT(V);
//
//  printf("\n  ==== Test %2d. Copy interval [%d, %d) from\n", testID++,
//         V.size() / 4, 3 * V.size() / 4);
//  PRINT(V);
//  Vector<T> U(V, V.size() / 4, 3 * V.size() / 4);
//  PRINT(U);
//  printf("\n  ==== Test %2d. Copy from\n", testID++);
//  PRINT(V);
//  Vector<T> W(V);
//  PRINT(W);
//  printf("\n  ==== Test %2d. Clone from\n", testID++);
//  PRINT(U);
//  W = U;
//  PRINT(W);
//  printf("\n  ==== Test %2d. Remove redundancy in unsorted\n", testID++);
//  PRINT(V);
//  printf("%d node(s) removed\n", V.deduplicate());
//  PRINT(V);
//
//  printf("\n  ==== Test %2d. Sort interval [%d, %d) in\n", testID++, 0,
//         V.size());
//  PRINT(V);
//  V.sort();
//  PRINT(V);
//
//  printf("\n  ==== Test %2d. FIND in\n", testID++);
//  PRINT(V);
//  TestFind<T>(V, testSize);
//
//  printf("\n  ==== Test %2d. SEARCH & INSERT in\n", testID++);
//  PRINT(V);
//  TestOrderedInsertion<T>(V, testSize);
//  PRINT(V);
//
//  printf("\n  ==== Test %2d. Remove redundancy in sorted\n", testID++);
//  PRINT(V);
//  printf("%d node(s) removed\n", V.uniquify());
//  PRINT(V);
//}
//
//// 测试接口
// int main(int argc, char* argv[]) {
//  srand((unsigned int)time(NULL));  //设置随机种子
//  testVector<int>(atoi(argv[1]));
//}
#include <iostream>
#include <string>
#include "Vector.h"

void printElem(int e) { std::cout << e << " "; }

template <typename T> 
void printInfo(std::string message, T& s) {
  std::cout << message << ": ";
  s.traverse(printElem);
  std::cout << "\n" << std::endl;
}

int main() {
  int i = 23;

  //初始化
  Vector<int> a(4, 3, 8);
  std::string message = "初始化";
  printInfo(message, a);
  //查找
  Rank result = a.find(3, 0, 1);
  std::cout << "查找3的结果：" << result << "\n" << std::endl;
  //写入
  a[2] = 7;
  message = "写入";
  printInfo(message, a);
  //插入
  a.insert(2, 12);
  message = "插入";
  printInfo(message, a);
  //移除
  a.remove(1, 3);
  message = "移除";
  printInfo(message, a);
  std::cout << a.size() << "\n" << std::endl;

  std::cout << "Hello World!\n" << std::endl;
}