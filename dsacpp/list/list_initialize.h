#pragma once

template <typename T>
void List<T>::init() {
  header = new ListNode<T>;   // Õ∑
  trailer = new ListNode<T>;  // Œ≤
  header->succ = trailer;     // header->trailer
  header->pred = NULL;
  trailer->pred = header;
  trailer->succ = NULL;
  _size = 0;  // ø’¡–±Ì
}