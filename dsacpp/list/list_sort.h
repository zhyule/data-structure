#pragma once

template <typename T>
void List<T>::sort(ListNodePosi<T> p, int n) {
  //*DSA*/ switch (3) {
  switch (rand() % 4) {  //���ѡȡ�����㷨���ɸ��ݾ���������ص����ѡȡ������
    case 1:
      insertionSort(p, n);
      break;  //��������
    case 2:
      selectionSort(p, n);
      break;  //ѡ������
    case 3:
      mergeSort(p, n);
      break;  //�鲢����
    default:
      radixSort(p, n);
      break;  //��������
  }
}