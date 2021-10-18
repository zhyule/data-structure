#pragma once

#include "vector/vector.h"

template <typename T>
void checkOrder(Vector<T>& V) {
  int unsorted = 0;                           //���������
  V.traverse(CheckOrder<T>(unsorted, V[0]));  //���б���
  if (0 < unsorted) {
    printf("Unsorted with %d adjacent inversion(s)\n", unsorted);
  } else {
    printf("Sorted\n");
  }
}

//template <typename T>
//void checkOrder(Vector<T>& V) {
//  if (0 < V.disordered()) {
//    printf("Unsorted with %d adjacent disordered pair(s)\n", V.disordered());
//  } else {
//    printf("Sorted\n");
//  }
//}