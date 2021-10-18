#pragma once

#include "list/list.h"

//统计列表的特征（所有的元素总和）
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
