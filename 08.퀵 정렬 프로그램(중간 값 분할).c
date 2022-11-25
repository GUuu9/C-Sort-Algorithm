#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include <conio.h>

#define N 100000

void QuickSort(int a[], int l, int r) {
	int i, j, m, v;										// ���� ����

	if (r - l > 1) {									// r - l > 1�̸� if�� ����
		m = (l + r) / 2;
		if (a[l] > a[m])
			swap(a, l, m);								// ��� ���� �� swap ��� ������� l,m��ġ ����
		if (a[l] > a[r])
			swap(a, l, r);								// ��� ���� �� swap ��� ������� l,r��ġ ����
		if (a[m] > a[r])
			swap(a, m, r);								// ��� ���� �� swap ��� ������� m,r��ġ ����

		swap(a, m, r - 1);								// ��� ���� �� swap ��� ������� m,r-1��ġ ����

		v = a[r-1];										// �迭�� ���� v�� ����
		i = l;											// i�� l���� ����
		j = r-1;										// j �� r - 1����

		for (;;) {
			while (a[++i] < v);							// a[i]�� v������ Ŀ�������� i���� �����Ѵ�.
			while (a[--j] > v);							// a[j]�� v������ �۾��������� j���� �����Ѵ�.
			if (i >= j)									// i�� j���� ũ�ų� �������� for���� Ż���Ѵ�.
				break;
			swap(a, i, j);								// ��� ���� �� swap ��� ������� i,j��ġ ����
		}
		swap(a, i, r-1);								// ��� ���� �� swap ��� ������� i,r-1��ġ ����
		QuickSort(a, l, i - 1);							// �迭 a ���� ���� l, i-1���� �ְ� �� ���� �ݺ�
		QuickSort(a, i + 1, r);							// �迭 a ���� ���� i+1, r���� �ְ� �� ���� �ݺ�
	}
	else												// r - l > 1�� �ƴ϶�� else�� ����
		if (a[l] > a[r]) 
			swap(a, l, r);								// ��� ���� �� swap ��� ������� l,r��ġ ����
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