#pragma once

//ɾ�������������ظ�Ԫ�أ���Ч�棩
template <typename T>
int Vector<T>::uniquify() {
  Rank i = 0, j = 0;
  //������ͬ��Ԫ�أ�ֱ�ӽس�����Ԫ��
  while (++j < _size) {
    if (_elem[i] != _elem[j]) {
      _elem[i++] = _elem[j];
    }
  }
  _size = ++i;
  shrink();
  return j - i;
}
