#pragma once

//��������
template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {  // assert: 0 <= lo < hi <= _size
  // [lo, last]֮���Ǵ������䣬������д�����������ν���ʹ��ֲ�����
  // ͨ�����һ�ν��������ж�
  for (Rank last = hi--; lo < hi; hi = last) {
    for (Rank i = last = lo; i < hi; i++) {
      if (_elem[i] > _elem[i + 1]) {
        swap(_elem[last = i], _elem[i + 1]);
      }
    }
  }
}