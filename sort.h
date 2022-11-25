#include <stdio.h>

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