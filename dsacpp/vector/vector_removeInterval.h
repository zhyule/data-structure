#pragma once

//ɾ������[lo, hi)
template <typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
  if (lo == hi) {
    return 0;
  }
  while (hi < _size) {  //����[hi, _size)
    _elem[lo++] = _elem[hi++];
  }
  _size = lo;      //���¹�ģ
  shrink();        //��Ҫʱ����
  return hi - lo;  //���ر�ɾ����Ԫ�ص���Ŀ
}