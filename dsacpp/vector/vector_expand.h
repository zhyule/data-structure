#pragma once

//����
template <typename T>
void Vector<T>::expand() {
  if (_size < _capacity) {
    return;
  }
  if (_capacity < DEFAULT_CAPACITY) {
    _capacity = DEFAULT_CAPACITY;  //��������С����
  }
  T* oldElem = _elem;              //_elemָ���׵�ַ��ָ��
  _elem = new T[_capacity <<= 1];  //�����ӱ�
  for (int i = 0; i < _size; i++) {
    _elem[i] = oldElem[i];  //��ֵԭ���������ݣ�T������Ҫ֧�ָ�ֵ����
  }
  /*DSA*/  // printf("\n_ELEM [%x]*%d/%d expanded and shift to [%x]*%d/%d\n",
           // oldElem, _size, _capacity/2, _elem, _size, _capacity);
  delete[] oldElem;  //�ͷſռ�
}
