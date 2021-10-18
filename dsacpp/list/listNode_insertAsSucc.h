#pragma once

template <typename T>
ListNodePosi<T> ListNode<T>::insertAsSucc(T const& e) {
	ListNodePosi<T> x = new ListNode(e, this, succ); // 创建新节点
	succ->pred = x; // e -> succ
	succ = x; // this -> e
	return x; // 返回新的节点位置
}