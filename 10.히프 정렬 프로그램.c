#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include <conio.h>

#define N 100000

void heapify(int a[], int h, int m) {					// heapify �Լ��� a�迭�� ����h,m���� �޴´�
	int j, v;											// ���� ����
	v = a[h];											// v�� �迭���� ����

	for (j = 2 * h; j <= m; j *= 2) {					
		if (j < m && a[j] < a[j + 1])
			j++;										
		if (v >= a[j])
			break;
		else
			a[j / 2] = a[j];
	}
	a[j / 2] = v;
}

void HeapSort(int a[], int n) {							// ���� ���� �˰������� �迭
	int i;												// ������ �����Ѵ�.

	for (i = n / 2; i >= 1; i--)						// for���� �ݺ��Ǵ� ����
		heapify(a, i, n);								// heapify �Լ��� a�迭�� i,n���� �����Ѵ�.
	for (i = n - 1; i >= 1; i--) {						// for���� �ݺ��Ǵ� ����
		swap(a, 1, i + 1);								// ��� �Լ� ��swap�Լ��� 1������ i+1��°�� ��ġ�� �ٲپ� �ش�
		heapify(a, 1, i);								// heapify �Լ��� a�迭�� 1,i���� �����Ѵ�.
	}
}

int main() {
	int i, a[N + 1];									// �����Լ����� ���� i�� �迭a�� �����Ѵ�.
	double start_time;									// ���� �ð��� Ȯ���ϱ� ���� �Ǽ� start_time�� �����Ѵ�.

	srand(time(NULL));									// �ð����� ����Ͽ� ���� ����
	for (i = 1; i <= N; i++)
		a[i] = rand();									// �ݺ������� i�� N������ Ŀ�������� ��� �������� a[i]�迭�� �ִ´�.

	start_time = clock();								// ���� �ð��� start_time�� ����Ѵ�.
	HeapSort(a, N);										// HeapSort �Լ��� a�迭�� N���� ����. 
	printf("���� ������ ���� �ð� (N = %d) : %.0f\n", N, clock() - start_time);
														// ���� �ð������� ���۽ð� �������� ��� �ð��� ����Ѵ�.
	CheckSort(a, N);									// CheckSort ���� a�� N���� ���� �迭�� �ùٸ��� ���� �Ǿ����� Ȯ��


	printf("�ƹ�Ű�� ��������.\n");
	while (!_kbhit());									// Ű���� �Է��� ������ ���� �ݺ��Ѵ�.
	fflush(stdin);										// �Էµ� ���۸� �����Ѵ�
}