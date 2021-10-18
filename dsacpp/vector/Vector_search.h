#pragma once

//有序向量区间[lo hi)查找不大于e的最后一个节点的秩
template <typename T>
Rank Vector<T>::search(T const &e, Rank lo,
                       Rank hi) const {  // assert: 0 <= lo < hi <= _size
  //return (rand() % 2) ? binSearch(_elem, e, lo, hi)
  //                    : fibSearch(_elem, e, lo, hi);
  return binSearch(_elem, e, lo, hi);
}