#pragma once

//向量归并排序
template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {  // 0 <= lo < hi <= size
  if (hi - lo < 2) {
    return;  //单元素区间自然有序
  }
  int mi = (lo + hi) / 2;
  mergeSort(lo, mi);  //分别排序
  mergeSort(mi, hi);  //分别排序
  merge(lo, mi, hi);  //归并
}