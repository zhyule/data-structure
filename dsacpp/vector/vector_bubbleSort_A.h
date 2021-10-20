#pragma once

template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {  // assert: 0 <= lo < hi <= _size
  //[lo, hi)区域内逐个检查相邻元素，逆序则交换使其局部有序
  //结束一轮循环后区域内的最大值正确排到末段，--hi开始下一轮循环
  while (lo < --hi) {
    for (Rank i = lo; i < hi; i++) {
      if (_elem[i] > _elem[i + 1]) {
        swap(_elem[i], _elem[i + 1]);
      }
    }
  }
}