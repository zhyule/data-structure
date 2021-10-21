#pragma once

//区间[lo, hi)选择排序
template <typename T>
void Vector<T>::selectionSort(Rank lo, Rank hi) {  // 0 <= lo < hi <= size
  /*DSA*/ printf("\tSELECTIONsort [%3d, %3d)\n", lo, hi);
  //循环截至时hi = lo + 1
  while (lo < --hi) {
    swap(_elem[maxItem(lo, hi)], _elem[hi]);
  }
}

//找出区间[lo, hi]内的最大值
template <typename T>
Rank Vector<T>::maxItem(Rank lo, Rank hi) {
  Rank max = hi;
  while (lo < hi--) {
    //[hi]与[lo, hi - 1]之间的值进行严格比较
    //保证有多个相同最大值时后者优先，进而保证selectionSort的稳定
    if (_elem[max] < _elem[hi]) {
      max = hi;
    }
  }
  return max;
}