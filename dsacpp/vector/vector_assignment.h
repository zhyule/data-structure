#pragma once

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& V) {  //���
  if (_elem) {
    delete[] _elem; // �ͷ�
  }
  copyFrom(V._elem, 0, V.size());
  return *this; //���ص�ǰ��������ã��Ա���ʽ��ֵ
}