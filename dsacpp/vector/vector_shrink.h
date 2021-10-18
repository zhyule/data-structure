#pragma once

//装填因子过小时压缩向量所占空间
template <typename T>
void Vector::shrink() {
  if (_capacity < DEFAULT_CAPACITY << 1) {
    return;
  }
  if (_size << 2 > _capacity) {
    return;  // 25%为界
  }
  T* oldElem = _elem;
  _elem = new T[_capacity >>= 1];  //容量减半
  for (int i = 0; i < _size; i++) {
    _elem[i] = oldElem[i];  //复制原向量内容
  }
  delete[] oldElem;  //释放原空间
}