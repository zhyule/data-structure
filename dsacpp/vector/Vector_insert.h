#pragma once

template <typename T>
Rank Vector<T>::insert(Rank r, T const& e) {  // assert: 0 <= r <= size
  expand();                                   // ���ݸ�����Ԫ���ڿռ�
  for (int i = _size; i > r; i--) {           // �Ӻ���ǰ
    _elem[i] = _elem[i - 1];
  }
  _elem[r] = e;  // ������Ԫ��
  _size++;       // ��������
  return r;      // ������
}