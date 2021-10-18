#pragma once

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T> const& V) {  //深复制
  if (_elem) {
    delete[] _elem; // 释放
  }
  copyFrom(V._elem, 0, V.size());
  return *this; //返回当前对象的引用，以便链式赋值
}