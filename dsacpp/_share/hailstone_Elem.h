#pragma once

//�������󣺰���Hailstone����ת��һ��T�����
template <typename T>
struct Hailstone {
  virtual void operator()(T& e) {  //����T��ֱ������������
    int step = 0;                  //ת�����貽��
    while (1 != e) {               //���桢ż��ת����ֱ��Ϊ1
      (e % 2) ? e = 3 * e + 1 : e /= 2;
      step++;
    }
    e = step;  //����ת����������
  }
};