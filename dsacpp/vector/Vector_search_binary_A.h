#pragma once

template <typename T>
static Rank binSearch(T* S, T const& e, Rank lo, Rank hi) {
  /*DSA*/ printf("BIN search (A)\n");
  while (lo < hi) {
    /*DSA*/ for (int i = 0; i < lo; i++)
      printf("     ");
    if (lo >= 0)
      for (int i = lo; i < hi; i++) printf("....^");
    printf("\n");
    Rank mi = (lo + hi) >> 1;  //以中点为轴线
    if (e < S[mi]) {
      hi = mi;  //[lo, mi)段查找
    } else if (S[mi] < e) {
      lo = mi + 1;  //(mi, hi]段查找
    } else {
      return mi;  // mi处命中
    }
    /*DSA*/ if (lo >= hi) {
      for (int i = 0; i < mi; i++) printf("     ");
      if (mi >= 0)
        printf("....|\n");
      else
        printf("<<<<|\n");
    }
  }           //成功查找可以提前终止
  return -1;  // 查找失败
}  //有多个命中元素时，不能保证返回秩最大者；查找失败时，简单地返回-1，而不能指示失败的位置
