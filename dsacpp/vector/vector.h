/******************************************************************************************
 * Data Structures in C++
 * ISBN: 7-302-33064-6 & 7-302-33065-3 & 7-302-29652-2 & 7-302-26883-3
 * Junhui DENG, deng@tsinghua.edu.cn
 * Computer Science & Technology, Tsinghua University
 * Copyright (c) 2003-2021. All rights reserved.
 ******************************************************************************************/

#pragma once

using Rank = int;  //秩
#define DEFAULT_CAPACITY 3  //默认的初始容量（实际应用中可设置为更大）

template <typename T>
class Vector {
 protected:
  Rank _size;                                   //规模
  int _capacity;                                //容量
  T* _elem;                                     //数据区域
  void copyFrom(T const* A, Rank lo, Rank hi);  //复制A[lo, hi]
  void expand();                                //空间不足扩容
  void shrink();                                //装填因子过小压缩
  // bool bubble(Rank lo, Rank hi);                //扫描交换
  void bubbleSort(Rank lo, Rank hi);      //起泡排序
  Rank maxItem(Rank lo, Rank hi);         //选取最大元素
  void selectionSort(Rank lo, Rank hi);   //选择排序算法
  void merge(Rank lo, Rank mi, Rank hi);  //归并算法
  void mergeSort(Rank lo, Rank hi);       //归并排序算法
 public:
  //构造函数
  Vector(int s, T v = 0, int c = DEFAULT_CAPACITY) {
    _elem = new T[_capacity = c];
    for (_size = 0; _size < s;
         _elem[_size++] = v)  //_size < _capacity 有越界风险
      ;
  }
  Vector(T const* A, Rank n) { copyFrom(A, 0, n); }  // 数组整体复制
  Vector(T const* A, Rank lo, Rank hi) {
    copyFrom(A, lo, hi);
  }  // 数组区间[lo, hi)复制
  Vector(Vector<T> const& V) { copyFrom(V._elem, 0, V._size); }  // 向量整体复制
  Vector(Vector<T> const& V, Rank lo, Rank hi) {
    copyFrom(V._elem, lo, hi);
  }  // 向量区间[lo, hi)复制
  //析构+
  ~Vector() { delete[] _elem; }
  //只读
  Rank size() const { return _size; }                        //规模
  bool empty() const { return !_size; }                      //判空
  Rank find(T const& e) const { return find(e, 0, _size); }  //无序向量整体查找
  Rank find(T const& e, Rank lo, Rank hi) const;  //无序向量区间[lo, hi)查找
  Rank search(T const& e) const {
    return (0 >= _size) ? -1 : search(e, 0, _size);
  }
  Rank search(T const& e, Rank lo, Rank hi) const;  //有序向量区间查找
  //可写
  T& operator[](Rank r);                   //下标操作符
  const T& operator[](Rank r) const;       //只能做右值
  Vector<T>& operator=(Vector<T> const&);  //重载赋值操作符
  T remove(Rank r);                        //删除秩为r的元素
  int remove(Rank lo, Rank hi);            //删除[lo, hi)之间的元素
  Rank insert(Rank r, T const& e);         //插入元素
  Rank insert(T const& e) { return insert(_size, e); }  //末元素插入
  void sort(Rank lo, Rank hi);                          //对[lo, hi)排序
  void sort() { sort(0, _size); }                       //整体排序
  void unsort(Rank lo, Rank hi);                        //对[lo, hi)置乱
  void unsort() { unsort(0, _size); }                   //整体置乱
  int deduplicate();                                    //无序去重
  int uniquify();                                       //有序去重
  // 遍历
  void traverse(void (*)(T&));  //遍历（使用函数指针，只读或局部性修改）
  template <typename VST>
  void traverse(VST&);  //遍历（使用函数对象，可全局性修改）
};
#include "vector_implementation.h"
