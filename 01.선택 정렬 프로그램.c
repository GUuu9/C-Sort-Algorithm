#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>					

#define N 10000											// N�� 10000���� ����
#define TRUE 1											// TRUE�� 1�� ����
#define FALSE 0											// FALSE�� 0���� ���� 

void swap(int a[], int i, int j) {						// swap �Լ����� �迭�� i, j���� ���� �޾ƿ´�.
	int t = a[i];										// �ش� �Լ��� �迭�� i��°�� ���� j��° ����
														// ������ ���� �ٲپ� �ִ� ������ �Ѵ�.
	a[i] = a[j];					
	a[j] = t;
}

void CheckSort(int a[], int n) {						// CheckSort �Լ��� �迭�� N���� �޾�
	int i, Sorted;										// swap �Լ��� ���� ���� ������� �迭�Ǿ�����
														// Ȯ�� �ϴ� �Լ� �̴�.
	Sorted = TRUE;

	for (i = 1; i < n; i++) {							// i�� n���� �۴ٸ� ��� �ݺ� �� i���� 1�� �����Ѵ�.
		if (a[i] > a[i + 1])							// ���簪�� ������ ���� ũ�ٸ�
			Sorted = FALSE;								// �ùٸ��� ���� �迭�� ���� FALSE�� �����Ѵ�.
		if (!Sorted)									// �迭�� �ùٸ��� �ʾ� FALSE�� �����ٸ�
			break;										// !Sorted�� ���� 0���� ���� �ƴϱ⿡ �ݺ��� �׸��д�.
	}

	if (Sorted)											// ���� Sorted ���� ������ TRUE, 1���̶�� ���̹Ƿ�					
		printf("���ĿϷ�.\n");							// ���� �Ϸ� ���
	else												// Sorted ���� �߰��� FALSE, 0������ �����ٸ� ��������
		printf("���� ���� �߻�.\n");					// ���� ���� �߻��� ��� �Ѵ�.

}

void SelectionSort(int a[], int n) {					// ���� ���� �˰������� �迭�� n���� �޴´�.
	int i, j, min;										// �迭�� ���� ������ �����Ѵ�.

	for (i = 1; i < n; i++) {							// i�� n���� �۴ٸ� ��� �ݺ� �� i���� 1�� �����Ѵ�.
		min = i;										// ���� i���� min���� ����

		for (j = i + 1; j <= n; j++) {					// j���� i+1���̸� j�� n���� �۰ų� ���ٸ� �ݺ��� j���� 1 ����
			if (a[j] < a[min])							// ���� j��°���� ���� i(min)��° ������ �۴ٸ�
				min = j;								// ���� j���� min���� ����
		}
		swap(a, min, i);								// �迭 a�� ���� j(min)����, i���� swap�Լ��� �����Ͽ� ������ �ٲ۴�.
	}													// for ���� ���� �ɶ����� �ݺ��Ѵ�.
}

void main() {
	int i, a[N + 1];									// �����Լ����� ���� i�� �迭a�� �����Ѵ�.
	double start_time;									// ���� �ð��� Ȯ���ϱ� ���� �Ǽ� start_time�� �����Ѵ�.

	srand(time(NULL));									// �ð����� ����Ͽ� ���� ����
	for (i = 1; i <= N; i++)										
		a[i] = rand();									// �ݺ������� i�� N������ Ŀ�������� ��� �������� a[i]�迭�� �ִ´�.

	start_time = clock();								// ���� �ð��� start_time�� ����Ѵ�.
	SelectionSort(a, N);								// Selection �Լ��� a�迭�� N���� ����. 
	printf("���� ������ ���� �ð� (N = %d) : %.0f\n", N, clock() - start_time);	
														// ���� �ð������� ���۽ð� �������� ��� �ð��� ����Ѵ�.
	CheckSort(a, N);									// CheckSort ���� a�� N���� ���� �迭�� �ùٸ��� ���� �Ǿ����� Ȯ��


	printf("�ƹ�Ű�� ��������.\n");
	while (!_kbhit());									// Ű���� �Է��� ������ ���� �ݺ��Ѵ�.
	fflush(stdin);										// �Էµ� ���۸� �����Ѵ�.
}