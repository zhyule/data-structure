#pragma once

//������������[lo hi)���Ҳ�����e�����һ���ڵ����
template <typename T>
Rank Vector<T>::search(T const &e, Rank lo,
                       Rank hi) const {  // assert: 0 <= lo < hi <= _size
  //return (rand() % 2) ? binSearch(_elem, e, lo, hi)
  //                    : fibSearch(_elem, e, lo, hi);
  return binSearch(_elem, e, lo, hi);
}