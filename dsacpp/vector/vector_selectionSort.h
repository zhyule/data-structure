#pragma once

//����[lo, hi)ѡ������
template <typename T>
void Vector<T>::selectionSort(Rank lo, Rank hi) {  // 0 <= lo < hi <= size
  /*DSA*/ printf("\tSELECTIONsort [%3d, %3d)\n", lo, hi);
  //ѭ������ʱhi = lo + 1
  while (lo < --hi) {
    swap(_elem[maxItem(lo, hi)], _elem[hi]);
  }
}

//�ҳ�����[lo, hi]�ڵ����ֵ
template <typename T>
Rank Vector<T>::maxItem(Rank lo, Rank hi) {
  Rank max = hi;
  while (lo < hi--) {
    //[hi]��[lo, hi - 1]֮���ֵ�����ϸ�Ƚ�
    //��֤�ж����ͬ���ֵʱ�������ȣ�������֤selectionSort���ȶ�
    if (_elem[max] < _elem[hi]) {
      max = hi;
    }
  }
  return max;
}