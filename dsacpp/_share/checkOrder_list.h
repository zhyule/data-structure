#pragma once

#include "list/list.h"

template <typename T>
void checkOrder(List<T>& L) {
  int nInv = 0; //���������
  //CheckOrder<T>(nInv, L.first()->data) ��ʼ����һ��CheckOrder���͵Ķ���
  //traverseÿ�α���������øö����()���������������Ӧ����
  CheckOrder<T> order(nInv, L.first()->data);
  L.traverse(order);  // ����
  if (0 < nInv) {
    printf("Unsorted with %d adjacent inversion(s)\n", nInv);
  } else {
    printf("Sorted\n");
  }
}