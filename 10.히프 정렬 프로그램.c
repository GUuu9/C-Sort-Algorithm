#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include <conio.h>

#define N 100000

void heapify(int a[], int h, int m) {					// heapify 함수로 a배열과 정수h,m값을 받는다
	int j, v;											// 정수 선언
	v = a[h];											// v에 배열값을 저장

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

void HeapSort(int a[], int n) {							// 히프 정렬 알고리즘으로 배열
	int i;												// 정수를 선언한다.

	for (i = n / 2; i >= 1; i--)						// for문이 반복되는 동안
		heapify(a, i, n);								// heapify 함수에 a배열과 i,n값을 전달한다.
	for (i = n - 1; i >= 1; i--) {						// for문이 반복되는 동안
		swap(a, 1, i + 1);								// 헤더 함수 속swap함수로 1번값과 i+1번째의 위치를 바꾸어 준다
		heapify(a, 1, i);								// heapify 함수에 a배열과 1,i값을 전달한다.
	}
}

int main() {
	int i, a[N + 1];									// 메인함수에서 정수 i와 배열a를 생성한다.
	double start_time;									// 실행 시간을 확인하기 위한 실수 start_time을 생성한다.

	srand(time(NULL));									// 시간값을 사용하여 난수 생성
	for (i = 1; i <= N; i++)
		a[i] = rand();									// 반복문으로 i가 N값보다 커질때까지 계속 난수값을 a[i]배열에 넣는다.

	start_time = clock();								// 시작 시간을 start_time에 기록한다.
	HeapSort(a, N);										// HeapSort 함수에 a배열과 N값을 전달. 
	printf("히프 정렬의 실행 시간 (N = %d) : %.0f\n", N, clock() - start_time);
														// 현재 시간값에서 시작시간 값을빼서 경과 시간을 출력한다.
	CheckSort(a, N);									// CheckSort 값에 a와 N값을 보내 배열이 올바르게 정렬 되었는지 확인


	printf("아무키나 누르세요.\n");
	while (!_kbhit());									// 키보드 입력이 있을때 까지 반복한다.
	fflush(stdin);										// 입력된 버퍼를 제거한다
}