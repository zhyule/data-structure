#pragma once

#include "listNode.h"

template <typename T>
class List {
 private:
  int _size;                // ��ģ
  ListNodePosi<T> header;   // ͷ
  ListNodePosi<T> trailer;  // β

 protected:
  void init();  //��ʼ��
  // protected����clear��ʵ�ֵ�����public����remove�Ĺ��ܣ��о��е�΢��
  int clear();  //������нڵ㣨��������β�ڱ����������б��С
  // �ڲ�������copyNodes��ʵ�ֵ�����public����insertAsLast�Ĺ���
  void copyNodes(ListNodePosi<T>, int);  //�����б���λ��p��n��(����p��)
  ListNodePosi<T> merge(ListNodePosi<T>, int, List<T>&, ListNodePosi<T>,
                        int);                //�鲢
  void mergeSort(ListNodePosi<T>&, int);     //[p, p + n - 1]�鲢����
  void selectionSort(ListNodePosi<T>, int);  //[p, p + n - 1]ѡ������
  void insertionSort(ListNodePosi<T>, int);  //[p, p + n - 1]��������
  void radixSort(ListNodePosi<T>, int);      //[p, p + n - 1]�ڵ��������

 public:
  List() { init(); }  // Ĭ�Ϲ���
  //���������ʵ�ֵ�����copyNodes����
  List(List<T> const& L);                 // ���帴��
  List(List<T> const& L, Rank r, int n);  // �����б�r��ʼ��nλ
  List(ListNodePosi<T> p, int n);         // �����б�p�ڵ㿪ʼ��nλ
  ~List();  // �������ͷ����нڵ㣨����ͷβ��
  //ֻ��
  Rank size() const { return _size; }  //��ģ��_size������ʱ�����õ�int����
  bool empty() const { return _size <= 0; }  //�ж��Ƿ�Ϊ���б�
  T& operator[](Rank r) const;  //���ز������ţ�ʱ�临�Ӷ�r
  ListNodePosi<T> first() const { return header->succ; }  //�׽ڵ�λ��
  ListNodePosi<T> last() const { return trailer->pred; }  //�׽ڵ�λ��
  bool valid(ListNodePosi<T> p) {  // �жϽڵ�p�Ƿ����Ϸ�
    return p && (trailer != p) && (header != p);
  }  // ListNodePosi���Ϳ��ԱȽ�������αȽϵ�
  // find��search�ֱ���������б���Һ������б���ң������ڱ�����û����ô����
  ListNodePosi<T> find(T const& e) const {  //�����б����
    return find(e, _size, trailer);
  }
  ListNodePosi<T> find(T const& e, int n,
                       ListNodePosi<T> p) const;  //�����������
  ListNodePosi<T> seach(T const& e) const {      //�����б����
    return search(e, _size, trailer);
  }
  ListNodePosi<T> search(T const& e, int n,
                         ListNodePosi<T> p) const;  //�����������
  ListNodePosi<T> selectMax() {
    return selectMax(header->succ, _size);
  }  //[0, _size - 1]�е����ֵ
  ListNodePosi<T> selectMax(ListNodePosi<T> p,
                            int n);  // [p, p + n - 1]�е����ֵ
  // ��д
  // �����ʵ�ֵ�����listNode��insertAsSucc����
  ListNodePosi<T> insertAsFirst(T const& e);              // e��Ϊ�׽ڵ�
  ListNodePosi<T> insertAsLast(T const& e);               // e��Ϊĩ�ڵ�
  ListNodePosi<T> insert(ListNodePosi<T> p, T const& e);  // e����p��
  ListNodePosi<T> insert(T const& e, ListNodePosi<T> p);  // e����pǰ
  T remove(ListNodePosi<T> p);  // ɾ��p�ڵ㣬���ر�ɾ���ڵ�����ݣ�p�ǺϷ�λ��
  void merge(List<T>& L) {                                   // ȫ�б�鲢
    merge(header->succ, _size, L, L.header->succ, L._size);  // ����Ĭ��return��
  }
  void sort() {            // �б�����
    sort(first(), _size);  // ����Ĭ��return��
  }
  void sort(ListNodePosi<T> p, int n);  // �б���������
  int deduplicate();                   //����ȥ��
  int uniquify();                      //����ȥ��
  void reverse();                       //ǰ����
  // ����
  void traverse(void (*)(T&));  //����ָ�����ִ�У�ֻ����ֲ����޸�
  template <typename VST>       //������
  void traverse(VST&);          //�����������ִ�У�ȫ�����޸�
};

#include "list_implementation.h"