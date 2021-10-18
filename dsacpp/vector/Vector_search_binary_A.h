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
    Rank mi = (lo + hi) >> 1;  //���е�Ϊ����
    if (e < S[mi]) {
      hi = mi;  //[lo, mi)�β���
    } else if (S[mi] < e) {
      lo = mi + 1;  //(mi, hi]�β���
    } else {
      return mi;  // mi������
    }
    /*DSA*/ if (lo >= hi) {
      for (int i = 0; i < mi; i++) printf("     ");
      if (mi >= 0)
        printf("....|\n");
      else
        printf("<<<<|\n");
    }
  }           //�ɹ����ҿ�����ǰ��ֹ
  return -1;  // ����ʧ��
}  //�ж������Ԫ��ʱ�����ܱ�֤����������ߣ�����ʧ��ʱ���򵥵ط���-1��������ָʾʧ�ܵ�λ��
