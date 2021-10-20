#pragma once

//向量的起泡排序（提前终止版）
template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {  // assert: 0 <= lo < hi <= _size
  for (bool sorted = false; sorted = !sorted;) {
    for (Rank i = lo; i < hi - 1; i++) {
      if (_elem[i] > _elem[i + 1]) {
        swap(_elem[i], _elem[i + 1]);
        sorted = false;
      }
    }
  }
}