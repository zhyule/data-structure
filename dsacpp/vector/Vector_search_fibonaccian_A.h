#pragma once
#include "fibonacci/Fib.h"  //����Fib������

// Fibonacci�����㷨���汾A��������������������[lo, hi)�ڲ���Ԫ��e
//assert: 0 <= o <= hi < _size
template <typename T>
static Rank fibSearch(T* S, T const& e, Rank lo, Rank hi) {
  /*DSA*/ printf("FIB search (A)\n");
  for (Fib fib(hi -lo); lo < hi; ) {
    while (hi - lo < fib.get()) {
      fib.prev();
    }
    Rank mi = lo + fib.get() - 1;
    if (e < S[mi]) {
      hi = mi;
    } else if (S[mi] < e) {
      lo = mi + 1;
    } else {
      return mi;
    }
  }
  return -1;
}