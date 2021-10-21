#pragma once

template <typename T>
void Vector<T>::merge(Rank lo, Rank mi,
                      Rank hi) {  //[lo, mi)��[mi, hi)��������lo < mi < hi
  Rank i = 0;
  //�Ƚ�B��C��������Ԫ�غϲ���A�С�ֻ��B�������¿ռ�
  T* A = _elem + lo;
  Rank j = 0, lb = mi - lo;
  T* B = new T[lb];
  for (Rank i = 0; i < lb; i++) {
    B[i] = A[i];
  }
  Rank k = 0, lc = hi - mi;
  T* C = _elem + mi;
  while ((j < lb) && (k < lc)) {
    A[i++] = (B[j] <= C[k]) ? B[j++] : C[k++];
  }
  //��B�Ⱥľ����������Ѿ����
  while (j < lb) {  //��C�Ⱥľ���B�ĺ�׺����A��
    A[i++] = B[j++];
  }
  delete[] B; //�ͷ���ʱ�ռ䣺mergeSort()�����У���α�����෴����new/delete��
}