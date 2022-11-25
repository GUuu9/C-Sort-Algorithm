#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include <conio.h>

#define N 10000												// N�� 10000���� ����


void BubbleSort(int a[], int n) {							// ���� ���� �˰������� �迭�� n���� �޴´�.
	int i, j;												// �迭�� ���� ���� ����

	for (i = n; i >= 1; i--) {								// i�� 1�����۾����� ���� �ݺ��Ѵ�.
		for (j = 1; j < i; j++)								// j�� i������ Ŀ���� ���� �ݺ��Ѵ�.
			if (a[j] > a[j + 1])							// ���� j��° ���� j+1������ ũ�ٸ� 
				swap(a, j, j + 1);							// sort ��� �Լ��� ���Ե� swap�Լ���  �� ������ �־� ��ġ�� �ٲ�
	}
}
void main() {
	int i, a[N + 1];										// �����Լ����� ���� i�� �迭a�� �����Ѵ�.
	double start_time;										// ���� �ð��� Ȯ���ϱ� ���� �Ǽ� start_time�� �����Ѵ�.

	srand(time(NULL));										// �ð����� ����Ͽ� ���� ����
	for (i = 1; i <= N; i++)
		a[i] = rand();										// �ݺ������� i�� N������ Ŀ�������� ��� �������� 
															// a[i]�迭�� �ִ´�.

	start_time = clock();									// ���� �ð��� start_time�� ����Ѵ�.
	BubbleSort(a, N);										// BubbleSort �Լ��� a�迭�� N���� ����. 
	printf("���� ������ ���� �ð� (N = %d) : %.0f\n", N, clock() - start_time); 
															// ���� �ð������� ���۽ð� �������� ��� �ð��� ����Ѵ�.
	CheckSort(a, N);										// CheckSort ���� a�� N���� ���� �迭�� �ùٸ��� ���� �Ǿ�����
															// Ȯ��


	printf("�ƹ�Ű�� ��������.\n");
	while (!_kbhit());										// Ű���� �Է��� ������ ���� �ݺ��Ѵ�.
	fflush(stdin);											// �Էµ� ���۸� �����Ѵ�.
}