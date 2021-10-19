#pragma once

//���ֲ��ң�B����������������[lo, hi)����Ԫ��e
// assert: 0 <= lo < hi <= size
template <typename T>
static Rank binSearch(T* S, T const& e, Rank lo, Rank hi) {
  /*DSA*/ printf("BIN search (B)\n");
  //���ֲ���ֻ��������֧���ɹ�����Ҳ������ǰ��ֹ
  //��hi = lo + 1ʱ�˳����˳�ʱ��ʣһ��Ԫ��S[lo]
  while (1 < hi - lo) {
    /*DSA*/  // for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0
             // ) for ( int i = lo; i < hi; i++ ) printf ( "....^" ); printf (
             // "\n" );
    Rank mi = (lo + hi) >> 1;
    (e < S[mi]) ? hi = mi : lo = mi;
  }
  /*DSA*/  // for ( int i = 0; i < lo; i++ ) printf ( "     " ); if ( lo >= 0 )
           // printf ( "....|\n" ); else printf ( "<<<<|\n" );
  return e < S[lo] ? lo - 1 : lo;  //���ز�����e�����ֵ��λ��
}  //������з����ȵ����ֵ������ʧ��ֱ�ӷ���-1������ָʾʧ�ܵ�λ��