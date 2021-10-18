#pragma once

template <typename T>
ListNodePosi<T> List<T>::insertAsFirst(T const& e) {
  _size++;
  return header->insertAsSucc(e);  // +-*-*+-��Ϊ�׽ڵ���벢�����½ڵ�λ��
}

template <typename T>
ListNodePosi<T> List<T>::insertAsLast(T const& e) {
  _size++;
  return trailer->insertAsPred(e);  // ��Ϊβ�ڵ���벢�����½ڵ�λ��
}

template <typename T>
ListNodePosi<T> List<T>::insert(ListNodePosi<T> p, T const& e) {
  _size++;
  return p->insertAsSucc(e);  // ����p�󲢷����½ڵ�λ��
}

template <typename T>
ListNodePosi<T> List<T>::insert(T const& e, ListNodePosi<T> p) {
  _size++;
  return p->insertAsPred(e);  // ����pǰ�������½ڵ�λ��
}