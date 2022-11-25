#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include <conio.h>

#define N 100000										// N�� 100000���� ����
#define MAX_STACK_SIZE 100								// MAX_STACK_SIZE�� 100���� ����

int stack[MAX_STACK_SIZE];								// stack[] ���� �迭�� ����
int top = -1;											// -1���� ������ top����

void push(int *top, int item) {							// push�Լ� top ������ �� item���� �޴´�
	stack[++*top] = item;								// ���� top������ 1������ ��ġ�� item�� ���� �ִ´�.
}

int pop(int *top) {										// top �����Ͱ��� �޴´�.
	return stack[(*top)--];								// ���� top������ 1 ������ ���� ��ȯ�Ѵ�.
}

int partition(int a[], int l, int r) {					// �迭 a�� ���� l,r���� �޾ƿ´�.
	int i, j, v;										// ���� ����

	v = a[r];											// ���� a[r]��ġ�� ���� v�� ����
	i = l - 1;											// l-1���� i�� ����
	j = r;												// j�� r ���� ����

	for (;;) {								
		while (a[++i] < v);							// a[i]�� v������ Ŀ�������� i���� �����Ѵ�.
		while (a[--j] > v);							// a[j]�� v������ �۾��������� j���� �����Ѵ�.

		if (i >= j)									// i�� j���� ũ�ų� �������� for���� Ż���Ѵ�.
			break;

		swap(a, i, j);								// ��� ���� �� swap ��� ������� i,j��ġ ����
	}

	swap(a, i, r);									// ��� ���� �� swap ��� ������� i,r��ġ ����
	return i;										// i���� ��ȯ�Ѵ�.
}

void QuickSort(int a[], int l, int r) {				// ��� a�� ���� l,r�� �޾ƿ´�
	int i, j, v;									// ���� ����

	for (;;) {										// ���� �ݺ���
		while (r > l) {								// r���� l���� ū ���ȿ� �ݺ�
			i = partition(a, l, r);					// i�� ��Ƽ�� �Լ��� �� ����

			if (i - l > r - i) {					// ���� i - l > r - i�̶�� if�� ����
				push(&top, l);						// push�Լ��� ������ ����
				push(&top, i - 1);					// push�Լ��� ������ ����
				l = i + 1;							// l�� i+1�� ����
			}

			else {									// ���� i - l > r - i�� �ƴ϶�� else�� ����
				push(&top, i+1);					// push�Լ��� ������ ����
				push(&top, r);						// push�Լ��� ������ ����
				r = i - 1;							// r�� i-1�� ����
			}
		}

		if (top < 0)								// ���� top���� 0���� ������ �ݺ��� Ż���� ��� ����
			break;

		r = pop(&top);								// r�� pop �Լ��� �� ����
		l = pop(&top);								// l�� pop �Լ��� �� ����

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
	printf("��ȯ�� ������ �� ������ ���� �ð� (N = %d) : %.0f\n", N, clock() - start_time);
	CheckSort(a, N);

	printf("�ƹ�Ű�� ��������.\n");
	while (!_kbhit());
	fflush(stdin);
}