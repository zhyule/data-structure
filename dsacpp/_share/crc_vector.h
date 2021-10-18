#pragma once

#include "vector/vector.h"

//统计向量的特征（所有的元素总和）
template <typename T>
void crc(Vector<T>& V) {
  T crc = 0;
  V.traverse(Crc<T>(crc));
  printf("CRC =");
  print(crc);
  printf("\n");
}
