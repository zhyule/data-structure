#pragma once

#include "list/list.h"

//ͳ���б�����������е�Ԫ���ܺͣ�
template <typename T>
void crc(List<T>& L) {
  T crc = 0;
  Crc<T> sum(crc);
   L.traverse(sum);
  //L.traverse(Crc<T>(crc));
  printf("CRC =");
  //print(0);
  printf("\n");
}
