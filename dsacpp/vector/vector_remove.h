#pragma once

//ɾ����������Ϊr��Ԫ��
template <typename T>
T Vector<T>::remove(Rank r) { //assert: 0 <= r < _size
  T e = _elem[r]; //����
  remove(r, r + 1); //ɾ��[r, r + 1)�����Ԫ��
  return e; //���ر�ɾ����Ԫ��
}