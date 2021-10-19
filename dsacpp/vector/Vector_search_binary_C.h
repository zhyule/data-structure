#pragma once

//二分查找（C）：有序向量区间[lo, hi)查找元素e
// assert: 0 <= lo <= hi <= size
template <typename T>
static Rank binSearch(T* S, T const& e, Rank lo, Rank hi) {
  /*DSA*/ printf("BIN search (C)\n");
  //一次比较两个分支[lo, mi)和(mi, hi)，结束后lo = hi为不大于e的元素的最小秩
  while (lo < hi) {
    /*DSA*/  // for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0
             // ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); printf (
             // "\n" );
    Rank mi = (lo + hi) >> 1;
    (e < S[mi]) ? hi = mi : lo = mi + 1; 
  }
  /*DSA*/  // for ( int i = 0; i < lo - 1; i++ ) printf ( "     " ); if ( lo > 0
           // ) printf ( "....|\n" ); else printf ( "<<<<|\n" );
  return lo - 1;  //循环结束时，lo为大于e的元素的最小秩，故lo - 1即不大于e的元素的最大秩
} //有多个命中元素时，返回秩最大者；查找失败时，能够返回失败的位置
