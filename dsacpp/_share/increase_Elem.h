#pragma once

//�������󣺵���һ��T�����
template <typename T>
struct Increase {
  virtual void operator()(T& e) { e++; }  //ǰ�᣺T��ֱ�ӵ�����������++
};