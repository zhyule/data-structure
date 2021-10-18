#pragma once

//函数对象，累计T类对象的特征（比如总和），以便校验对象集合
template <typename T>
struct Crc {
  T& c;
  Crc(T& crc) : c(crc) {}
  virtual void operator() (T& e) { c += e; }  // T可以执行+运算符
};