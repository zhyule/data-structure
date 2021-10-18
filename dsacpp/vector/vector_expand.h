#pragma once

//扩容
template <typename T>
void Vector<T>::expand() {
  if (_size < _capacity) {
    return;
  }
  if (_capacity < DEFAULT_CAPACITY) {
    _capacity = DEFAULT_CAPACITY;  //不低于最小容量
  }
  T* oldElem = _elem;              //_elem指向首地址的指针
  _elem = new T[_capacity <<= 1];  //容量加倍
  for (int i = 0; i < _size; i++) {
    _elem[i] = oldElem[i];  //赋值原向量的内容，T类型需要支持赋值操作
  }
  /*DSA*/  // printf("\n_ELEM [%x]*%d/%d expanded and shift to [%x]*%d/%d\n",
           // oldElem, _size, _capacity/2, _elem, _size, _capacity);
  delete[] oldElem;  //释放空间
}
