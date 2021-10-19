#pragma once

//二分查找（B）：有序向量区间[lo, hi)查找元素e
// assert: 0 <= lo < hi <= size
template <typename T>
static Rank binSearch(T* S, T const& e, Rank lo, Rank hi) {
  /*DSA*/ printf("BIN search (B)\n");
  //二分查找只有两个分支，成功查找也不会提前中止
  //在hi = lo + 1时退出，退出时仅剩一个元素S[lo]
  while (1 < hi - lo) {
    /*DSA*/  // for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0
             // ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); printf (
             // "\n" );
    Rank mi = (lo + hi) >> 1;
    (e < S[mi]) ? hi = mi : lo = mi;
  }
  /*DSA*/  // for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 )
           // printf ( "....|\n" ); else printf ( "<<<<|\n" );
  return e < S[lo] ? lo - 1 : lo;  //返回不超过e的最大值的位置
}  //多个命中返回秩的最大值；查找失败直接返回-1，不能指示失败的位置