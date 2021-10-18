#pragma once

#include <typeinfo>

/******************************************************************************************
 * �б������Ƚṹ�ڵĽڵ��У����Դ�Ż������ͻ�������
 * ���ձ���Լ������Ч�ʿ��ǣ����ں�һ�����ֻ��������ָ��
 * ��ˣ�������ṹ����֮ǰ����Ҫ�����ͷ���Щ��Ա������ռ�Ŀռ�
 * �˴�������C++��ƫ�־û����������������������������Ӧ����
 ******************************************************************************************/

template <typename T>
struct Cleaner {
  static void clean(T x) {
#ifdef _DEBUG
    static int n = 0;
    if (7 > strlen(typeid(T).name())) {
      printf("\t<%s>[%d]=", typeid(T).name(), ++n);
      print(x);
      printf("purged\n");
    }
#endif
  }
};

template <typename T>
struct Cleaner<T*> {
  static void clean(T* x) {
    if (x) {
      delete x;
    }
#ifdef _DEBUG
    static int n = 0;
    printf("\t<%s>[%d] released\n", typeid(T*).name(), ++n);
#endif  // _DEBUG
  }
};
