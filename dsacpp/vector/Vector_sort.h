#pragma once

template <typename T>
void Vector<T>::sort(Rank lo, Rank hi) {  //��������[lo, hi)����
  return bubbleSort(lo, hi);
  //switch (rand() % 6) {
  //  case 1:
  //    bubbleSort(lo, hi);
  //    break;  //��������
  //  case 2:
  //    selectionSort(lo, hi);
  //    break;  //ѡ������ϰ�⣩
  //  case 3:
  //    mergeSort(lo, hi);
  //    break;  //�鲢����
  //  case 4:
  //    heapSort(lo, hi);
  //    break;  //�����򣨵�12�£�
  //  case 5:
  //    quickSort(lo, hi);
  //    break;  //�������򣨵�14�£�
  //  default:
  //    shellSort(lo, hi);
  //    break;  //ϣ�����򣨵�14�£�
  //}  //���ѡ���㷨�Գ�ֲ��ԡ�ʵ��ʱ���Ӿ���������ص����ȷ��������
}