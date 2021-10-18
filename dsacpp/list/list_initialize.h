#pragma once

template <typename T>
void List<T>::init() {
  header = new ListNode<T>;   // ͷ
  trailer = new ListNode<T>;  // β
  header->succ = trailer;     // header->trailer
  header->pred = NULL;
  trailer->pred = header;
  trailer->succ = NULL;
  _size = 0;  // ���б�
}