#pragma once

template <typename T>
int Vector<T>::deduplicate() {
  int oldSize = _size;
  for (Rank i = 1; i < _size; i++) {
    Rank j = find(_elem[i], 0, i);
    std::cout << "���ҽ����" << i << _elem[i] << j << "\n" << std::endl;
    if (0 <= j) {
      remove(j ); //ɾ������Ȼ������������һ������Ԫ�ط��ʴ�λ
    }
  }
  return oldSize - _size;
}