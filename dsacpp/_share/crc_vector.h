#pragma once

#include "vector/vector.h"

//ͳ�����������������е�Ԫ���ܺͣ�
template <typename T>
void crc(Vector<T>& V) {
  T crc = 0;
  V.traverse(Crc<T>(crc));
  printf("CRC =");
  print(crc);
  printf("\n");
}
