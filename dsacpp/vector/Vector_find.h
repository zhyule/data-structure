#pragma once

//��������˳����ң��������һ��Ԫ��e��λ�ã�ʧ�ܷ���lo - 1
template <typename T>
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const {
  //lo < hi-- : if (lo < hi) hi -= 1; 
  while ((lo < hi--) && (e != _elem[hi]))
    ;
  return hi; 
}