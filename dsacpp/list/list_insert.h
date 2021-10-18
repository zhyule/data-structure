#pragma once

template <typename T>
ListNodePosi<T> List<T>::insertAsFirst(T const& e) {
  _size++;
  return header->insertAsSucc(e);  // +-*-*+-作为首节点插入并返回新节点位置
}

template <typename T>
ListNodePosi<T> List<T>::insertAsLast(T const& e) {
  _size++;
  return trailer->insertAsPred(e);  // 作为尾节点插入并返回新节点位置
}

template <typename T>
ListNodePosi<T> List<T>::insert(ListNodePosi<T> p, T const& e) {
  _size++;
  return p->insertAsSucc(e);  // 插入p后并返回新节点位置
}

template <typename T>
ListNodePosi<T> List<T>::insert(T const& e, ListNodePosi<T> p) {
  _size++;
  return p->insertAsPred(e);  // 插入p前并返回新节点位置
}