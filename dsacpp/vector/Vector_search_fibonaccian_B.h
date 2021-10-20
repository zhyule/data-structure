#pragma once
#include "fibonacci/Fib.h"  //引入Fib数列类

template <typename T>
static Rank fibSearch(T* S, T const& e, Rank lo, Rank hi) {
  /*DSA*/ printf("FIB search (B)\n");
  for (Fib fib(hi - lo); lo < hi;) {
    while (hi - lo < fib.get()) {
      fib.prev();
    }
    Rank mi = lo + fib.get() - 1;
    (e < S[mi]) ? hi = mi : lo = mi + 1;
  }
  return --lo;
}