#pragma once

template <typename T>
void Vector<T>::merge(Rank lo, Rank mi,
                      Rank hi) {  //[lo, mi)和[mi, hi)各自有序，lo < mi < hi
  Rank i = 0;
  //比较B、C向量的首元素合并到A中。只有B开辟了新空间
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
  //若B先耗尽，则排序已经完成
  while (j < lb) {  //若C先耗尽将B的后缀归于A中
    A[i++] = B[j++];
  }
  delete[] B; //释放临时空间：mergeSort()过程中，如何避免此类反复的new/delete？
}