#pragma once

#include "listNode.h"

template <typename T>
class List {
 private:
  int _size;                // 规模
  ListNodePosi<T> header;   // 头
  ListNodePosi<T> trailer;  // 尾

 protected:
  void init();  //初始化
  // protected函数clear的实现调用了public函数remove的功能，感觉有点微妙
  int clear();  //清除所有节点（不包括首尾哨兵），返回列表大小
  // 内部方法，copyNodes的实现调用了public函数insertAsLast的功能
  void copyNodes(ListNodePosi<T>, int);  //复制列表中位置p起n项(包括p点)
  ListNodePosi<T> merge(ListNodePosi<T>, int, List<T>&, ListNodePosi<T>,
                        int);                //归并
  void mergeSort(ListNodePosi<T>&, int);     //[p, p + n - 1]归并排序
  void selectionSort(ListNodePosi<T>, int);  //[p, p + n - 1]选择排序
  void insertionSort(ListNodePosi<T>, int);  //[p, p + n - 1]插入排序
  void radixSort(ListNodePosi<T>, int);      //[p, p + n - 1]节点基数排序

 public:
  List() { init(); }  // 默认构造
  //拷贝构造的实现调用了copyNodes方法
  List(List<T> const& L);                 // 整体复制
  List(List<T> const& L, Rank r, int n);  // 复制列表r开始后n位
  List(ListNodePosi<T> p, int n);         // 复制列表p节点开始后n位
  ~List();  // 析构，释放所有节点（包括头尾）
  //只读
  Rank size() const { return _size; }  //规模，_size声明的时候还是用的int类型
  bool empty() const { return _size <= 0; }  //判断是否为空列表
  T& operator[](Rank r) const;  //重载操作符号，时间复杂度r
  ListNodePosi<T> first() const { return header->succ; }  //首节点位置
  ListNodePosi<T> last() const { return trailer->pred; }  //首节点位置
  bool valid(ListNodePosi<T> p) {  // 判断节点p是否对外合法
    return p && (trailer != p) && (header != p);
  }  // ListNodePosi类型可以比较吗，是如何比较的
  // find和search分别代表无序列表查找和有序列表查找，命名在表意上没有那么清晰
  ListNodePosi<T> find(T const& e) const {  //无序列表查找
    return find(e, _size, trailer);
  }
  ListNodePosi<T> find(T const& e, int n,
                       ListNodePosi<T> p) const;  //无序区间查找
  ListNodePosi<T> seach(T const& e) const {      //有序列表查找
    return search(e, _size, trailer);
  }
  ListNodePosi<T> search(T const& e, int n,
                         ListNodePosi<T> p) const;  //有序区间查找
  ListNodePosi<T> selectMax() {
    return selectMax(header->succ, _size);
  }  //[0, _size - 1]中的最大值
  ListNodePosi<T> selectMax(ListNodePosi<T> p,
                            int n);  // [p, p + n - 1]中的最大值
  // 可写
  // 插入的实现调用了listNode的insertAsSucc方法
  ListNodePosi<T> insertAsFirst(T const& e);              // e作为首节点
  ListNodePosi<T> insertAsLast(T const& e);               // e作为末节点
  ListNodePosi<T> insert(ListNodePosi<T> p, T const& e);  // e插入p后
  ListNodePosi<T> insert(T const& e, ListNodePosi<T> p);  // e插入p前
  T remove(ListNodePosi<T> p);  // 删除p节点，返回被删除节点的数据，p是合法位置
  void merge(List<T>& L) {                                   // 全列表归并
    merge(header->succ, _size, L, L.header->succ, L._size);  // 可以默认return吗
  }
  void sort() {            // 列表排序
    sort(first(), _size);  // 可以默认return吗
  }
  void sort(ListNodePosi<T> p, int n);  // 列表区间排序
  int deduplicate();                   //无序去重
  int uniquify();                      //有序去重
  void reverse();                       //前后倒置
  // 遍历
  void traverse(void (*)(T&));  //函数指针遍历执行，只读或局部性修改
  template <typename VST>       //操作器
  void traverse(VST&);          //函数对象遍历执行，全局性修改
};

#include "list_implementation.h"