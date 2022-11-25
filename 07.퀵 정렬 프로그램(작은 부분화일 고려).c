#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include <conio.h>

#define N 100000										// N�� 100000���� ����
#define M 20											// M�� 20���� ����

void InsertionSort(int a[], int l, int r) {				// InsertionSort�Լ� �迭a�� ���� l,r�� �޾ƿ´�.
	int i, j, v;										// ������ �����Ѵ�.

	for (i = l + 1; i <= r; i++) {						// i=l+1���̸� i���� r���� Ŀ�������� �ݺ��ϸ� i�� 1�� ����
		v = a[i];										// v�� i��° �迭 ���� ����
		j = i;											// ��ġ ���� j�� ����

		while (a[j - 1] > v) {							// a[j - 1] > v�� ���� �ݺ�
			a[j] = a[j - 1];							// a[j]��  a[j - 1]���� ����
			j--;										// j���� 1�� ���ҽ�Ŵ
		}
		a[j] = v;										// ���� �������� ���� j��ġ�� ����
	}
}

void QuickSort(int a[], int l, int r) {					// �� ���� �˰������� �迭 
	int i, j, v;										// ������ �����Ѵ�.

	if (r - l <= M)										// r-l �� M(20)���� �������
		InsertionSort(a, l, r);							// InsertionSort�Լ� ����

	else {												// r-l �� M(20)���� ū���
		v = a[r];										// ���� �迭�� ���� v�� ����
		i = l - 1;										// i�� l - 1���� ����
		j = r;											// j �� r ����

		for (;;) {
			while (a[++i] < v);							// a[i]�� v������ Ŀ�������� i���� �����Ѵ�.
			while (a[--j] > v);							// a[j]�� v������ �۾��������� j���� �����Ѵ�.
			if (i >= j)									// i�� j���� ũ�ų� �������� for���� Ż���Ѵ�.
				break;
			swap(a, i, j);								// ��� ���� �� swap ��� ������� i,j��ġ ����
		}
		swap(a, i, r);									// ��� ���� �� swap ��� ������� i,r��ġ ����
		QuickSort(a, l, i - 1);							// �迭 a ���� ���� l, i-1���� �ְ� �� ���� �ݺ�
		QuickSort(a, i + 1, r);							// �迭 a ���� ���� i+1, r���� �ְ� �� ���� �ݺ�
	}
}

void main() {
	int i, a[N + 1];
	double start_time;

	a[0] = -1;
	srand(time(NULL));
	for (i = 1; i <= N; i++)
		a[i] = rand();

	start_time = clock();
	QuickSort(a, 1, N);
	printf("���� �κ�ȭ���� ����� �� ������ ���� �ð� (N = %d) : %.0f\n", N, clock() - start_time);
	CheckSort(a, N);

	printf("�ƹ�Ű�� ��������.\n");
	while (!_kbhit());
	fflush(stdin);
}