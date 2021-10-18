#pragma once

#include "list/list.h"

template <typename T> void checkOrder(List(T)& L) {
	int nInv = 0; // ������
	L.traverse() // ����
	if (0 < nInv) {
		printf("Unsorted with %d adjacent inversion(s)\n", nInv);
	}
	else {
		printf("Sorted\n");
	}
}