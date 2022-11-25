#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include <conio.h>

#define N 10000

int b[N + 1];											// b�迭 ����

void MergeSort(int a[], int l, int r) {					// �պ� ���� �˰������� �迭
	int i, j, k, m;										// ������ �����Ѵ�.

	if (r > l) {
		m = (r + l) / 2;
		MergeSort(a, l, m);								// �迭 a ���� ���� l, m���� �ְ� �պ� ���� �ݺ�
		MergeSort(a, m + 1, r);							// �迭 a ���� ���� m+1, r���� �ְ� �պ� ���� �ݺ�

		for (i = m + 1; i > l; i--)						// i���� ��� ���� ��Ű�� l���� ���ų� �۾����� ����
			b[i - 1] = a[i - 1];						// b�迭�� a�迭 ���� ����
		for (j = m; j < r; j++)							// j���� ��� ���� ��Ű�� r���� ���ų� Ŀ���� ����
			b[r + m - j] = a[j + 1];					// b�迭�� a�迭 ���� ����
		for (k = l; k <= r; k++)						// k���� ��� ������Ű�� k���� r���� Ŀ���� ����
			a[k] = (b[i] < b[j]) ? b[i++] : b[j--];		// a�迭�� b[i]�� b[j]�� ���� ���� ���̸� i�� ����
	}													// �����̸� j�� ����
}

void main() {
	int i, a[N + 1];									// �����Լ����� ���� i�� �迭a�� �����Ѵ�.
	double start_time;									// ���� �ð��� Ȯ���ϱ� ���� �Ǽ� start_time�� �����Ѵ�.

	srand(time(NULL));									// �ð����� ����Ͽ� ���� ����
	for (i = 1; i <= N; i++)
		a[i] = rand();									// �ݺ������� i�� N������ Ŀ�������� ��� �������� a[i]�迭�� �ִ´�.

	start_time = clock();								// ���� �ð��� start_time�� ����Ѵ�.
	MergeSort(a, 1, N);									// MergeSort �Լ��� a�迭�� N���� ����. 
	printf("�պ� ������ ���� �ð� (N = %d) : %.0f\n", N, clock() - start_time);
														// ���� �ð������� ���۽ð� �������� ��� �ð��� ����Ѵ�.
	CheckSort(a, N);									// CheckSort ���� a�� N���� ���� �迭�� �ùٸ��� ���� �Ǿ����� Ȯ��


	printf("�ƹ�Ű�� ��������.\n");
	while (!_kbhit());									// Ű���� �Է��� ������ ���� �ݺ��Ѵ�.
	fflush(stdin);										// �Էµ� ���۸� �����Ѵ�
}