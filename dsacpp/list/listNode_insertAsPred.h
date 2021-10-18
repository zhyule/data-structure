#pragma once

template <typename T>
ListNodePosi<T> ListNode<T>::insertAsPred(T const& e) {
	ListNodePosi<T> x = new ListNode(e, pred, this); // 创建新的节点
	pred->succ = x; // pre -> new
	pred = x; // new -> this
	return x;
}