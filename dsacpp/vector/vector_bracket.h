#pragma once

template <typename T>
T& Vector<T>::operator[](Rank r) {
  return _elem[r];  // assert: 0 <= r < _size
}

//只能做右值，为什么需要
template <typename T>
const T& Vector<T>::operator[](Rank r) const {
  return _elem[r];  // assert: 0 <= r < _size
}