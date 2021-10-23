/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

using Rank = int;  //��
#define DEFAULT_CAPACITY 3  //Ĭ�ϵĳ�ʼ������ʵ��Ӧ���п�����Ϊ����

template <typename T>
class Vector {
 protected:
  Rank _size;                                   //��ģ
  int _capacity;                                //����
  T* _elem;                                     //��������
  void copyFrom(T const* A, Rank lo, Rank hi);  //����A[lo, hi]
  void expand();                                //�ռ䲻������
  void shrink();                                //װ�����ӹ�Сѹ��
  // bool bubble(Rank lo, Rank hi);                //ɨ�轻��
  void bubbleSort(Rank lo, Rank hi);      //��������
  Rank maxItem(Rank lo, Rank hi);         //ѡȡ���Ԫ��
  void selectionSort(Rank lo, Rank hi);   //ѡ�������㷨
  void merge(Rank lo, Rank mi, Rank hi);  //�鲢�㷨
  void mergeSort(Rank lo, Rank hi);       //�鲢�����㷨
  void shellSort(Rank lo, Rank hi);       //ϣ�������㷨
 public:
  //���캯��
  Vector(int s, T v = 0, int c = DEFAULT_CAPACITY) {
    _elem = new T[_capacity = c];
    for (_size = 0; _size < s;
         _elem[_size++] = v)  //_size < _capacity ��Խ�����
      ;
  }
  Vector(T const* A, Rank n) { copyFrom(A, 0, n); }  // �������帴��
  Vector(T const* A, Rank lo, Rank hi) {
    copyFrom(A, lo, hi);
  }  // ��������[lo, hi)����
  Vector(Vector<T> const& V) { copyFrom(V._elem, 0, V._size); }  // �������帴��
  Vector(Vector<T> const& V, Rank lo, Rank hi) {
    copyFrom(V._elem, lo, hi);
  }  // ��������[lo, hi)����
  //����+
  ~Vector() { delete[] _elem; }
  //ֻ��
  Rank size() const { return _size; }                        //��ģ
  bool empty() const { return !_size; }                      //�п�
  Rank find(T const& e) const { return find(e, 0, _size); }  //���������������
  Rank find(T const& e, Rank lo, Rank hi) const;  //������������[lo, hi)����
  Rank search(T const& e) const {
    return (0 >= _size) ? -1 : search(e, 0, _size);
  }
  Rank search(T const& e, Rank lo, Rank hi) const;  //���������������
  //��д
  T& operator[](Rank r);                   //�±������
  const T& operator[](Rank r) const;       //ֻ������ֵ
  Vector<T>& operator=(Vector<T> const&);  //���ظ�ֵ������
  T remove(Rank r);                        //ɾ����Ϊr��Ԫ��
  int remove(Rank lo, Rank hi);            //ɾ��[lo, hi)֮���Ԫ��
  Rank insert(Rank r, T const& e);         //����Ԫ��
  Rank insert(T const& e) { return insert(_size, e); }  //ĩԪ�ز���
  void sort(Rank lo, Rank hi);                          //��[lo, hi)����
  void sort() { sort(0, _size); }                       //��������
  void unsort(Rank lo, Rank hi);                        //��[lo, hi)����
  void unsort() { unsort(0, _size); }                   //��������
  int deduplicate();                                    //����ȥ��
  int uniquify();                                       //����ȥ��
  // ����
  void traverse(void (*)(T&));  //������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
  template <typename VST>
  void traverse(VST&);  //������ʹ�ú������󣬿�ȫ�����޸ģ�
};
#include "vector_implementation.h"
