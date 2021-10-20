#pragma once

template <typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {  // assert: 0 <= lo < hi <= _size
  //[lo, hi)����������������Ԫ�أ������򽻻�ʹ��ֲ�����
  //����һ��ѭ���������ڵ����ֵ��ȷ�ŵ�ĩ�Σ�--hi��ʼ��һ��ѭ��
  while (lo < --hi) {
    for (Rank i = lo; i < hi; i++) {
      if (_elem[i] > _elem[i + 1]) {
        swap(_elem[i], _elem[i + 1]);
      }
    }
  }
}