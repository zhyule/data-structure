#pragma once

//�����鲢����
template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {  // 0 <= lo < hi <= size
  if (hi - lo < 2) {
    return;  //��Ԫ��������Ȼ����
  }
  int mi = (lo + hi) / 2;
  mergeSort(lo, mi);  //�ֱ�����
  mergeSort(mi, hi);  //�ֱ�����
  merge(lo, mi, hi);  //�鲢
}