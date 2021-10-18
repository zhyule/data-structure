#pragma once

#include "list/list.h"

template <typename T>
void checkOrder(List<T>& L) {
  int nInv = 0; //逆序计数器
  //CheckOrder<T>(nInv, L.first()->data) 初始化了一个CheckOrder类型的对象
  //traverse每次遍历都会调用该对象的()操作符，并传入对应参数
  CheckOrder<T> order(nInv, L.first()->data);
  L.traverse(order);  // 遍历
  if (0 < nInv) {
    printf("Unsorted with %d adjacent inversion(s)\n", nInv);
  } else {
    printf("Sorted\n");
  }
}