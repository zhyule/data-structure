#pragma once

//ɾ�������������ظ�Ԫ��
template <typename T>
int Vector<T>::deduplicate() {
  int oldSize = _size; //��¼ԭ��ģ
  //[0, ..., i -1, i, ..., _size - 1], _elem[i]��[0, i-1]�������ظ�ֵ��ɾ����������һ��
  Rank i = 1;
  while (i < _size) {
    if (find(_elem[i], 0, i) < 0) {
      i++;
    } else {
      remove(i);
    }
  }
  return oldSize - _size; //���ر�ɾ��Ԫ�ص�����
}