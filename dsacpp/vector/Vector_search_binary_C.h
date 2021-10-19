#pragma once

//���ֲ��ң�C����������������[lo, hi)����Ԫ��e
// assert: 0 <= lo <= hi <= size
template <typename T>
static Rank binSearch(T* S, T const& e, Rank lo, Rank hi) {
  /*DSA*/ printf("BIN search (C)\n");
  //һ�αȽ�������֧[lo, mi)��(mi, hi)��������lo = hiΪ������e��Ԫ�ص���С��
  while (lo < hi) {
    /*DSA*/  // for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0
             // ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); printf (
             // "\n" );
    Rank mi = (lo + hi) >> 1;
    (e < S[mi]) ? hi = mi : lo = mi + 1; 
  }
  /*DSA*/  // for ( int i = 0; i < lo - 1; i++ ) printf ( "     " ); if ( lo > 0
           // ) printf ( "....|\n" ); else printf ( "<<<<|\n" );
  return lo - 1;  //ѭ������ʱ��loΪ����e��Ԫ�ص���С�ȣ���lo - 1��������e��Ԫ�ص������
} //�ж������Ԫ��ʱ������������ߣ�����ʧ��ʱ���ܹ�����ʧ�ܵ�λ��
