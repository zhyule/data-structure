#pragma once

//�������󣺱���һ��T�����
template <typename T>
struct Double {
  virtual void operator()(T& e) { e *= 2; }  // ǰ�᣺T�����ִ��*2�������Ա���
};