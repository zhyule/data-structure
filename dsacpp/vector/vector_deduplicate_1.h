#pragma once

//ɾ�������������ظ�Ԫ�أ������棩
template <typename T>
int Vector<T>::deduplicate() {
  int oldSize = _size;
  int i = -1;
  //[0, ..., i, j, ..., _size - 1], _elem[i]��[i + 1, _size - 1]��������ɾ���ظ�Ԫ��
  while (++i < _size - 1) {
    int j = i + 1; //assert: _elem[0, i]�в����ظ�Ԫ��
    while (j < _size) {
      if (_elem[i] == _elem[j]) {
        remove(j);
      } else {
        j++;
      }
    }
  }
  return oldSize - _size;  //���ر�ɾ��Ԫ�ص�����
}