#pragma once

//起泡排序
template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {  // assert: 0 <= lo < hi <= _size
  // [lo, last]之间是待排区间，如果其中存在逆序会依次交换使其局部有序
  // 通过最后一次交换可以判断
  for (Rank last = hi--; lo < hi; hi = last) {
    for (Rank i = last = lo; i < hi; i++) {
      if (_elem[i] > _elem[i + 1]) {
        swap(_elem[last = i], _elem[i + 1]);
      }
    }
  }
}