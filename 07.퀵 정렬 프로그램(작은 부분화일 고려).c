#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include <conio.h>

#define N 100000										// N을 100000으로 정의
#define M 20											// M을 20으로 정의

void InsertionSort(int a[], int l, int r) {				// InsertionSort함수 배열a와 정수 l,r을 받아온다.
	int i, j, v;										// 정수를 선언한다.

	for (i = l + 1; i <= r; i++) {						// i=l+1값이며 i값이 r보다 커질때까지 반복하며 i는 1씩 증가
		v = a[i];										// v에 i번째 배열 값을 저장
		j = i;											// 위치 값을 j에 저장

		while (a[j - 1] > v) {							// a[j - 1] > v인 동안 반복
			a[j] = a[j - 1];							// a[j]에  a[j - 1]값을 저장
			j--;										// j값을 1씩 감소시킴
		}
		a[j] = v;										// 원래 넣으려던 값을 j위치에 저장
	}
}

void QuickSort(int a[], int l, int r) {					// 퀵 정렬 알고리즘으로 배열 
	int i, j, v;										// 정수를 선언한다.

	if (r - l <= M)										// r-l 이 M(20)보다 작은경우
		InsertionSort(a, l, r);							// InsertionSort함수 실행

	else {												// r-l 이 M(20)보다 큰경우
		v = a[r];										// 현재 배열의 값을 v에 저장
		i = l - 1;										// i에 l - 1값을 저장
		j = r;											// j 에 r 저장

		for (;;) {
			while (a[++i] < v);							// a[i]가 v값보다 커질때까지 i값을 증가한다.
			while (a[--j] > v);							// a[j]가 v값보다 작아질때까지 j값을 감소한다.
			if (i >= j)									// i가 j보다 크거나 같아지면 for문을 탈출한다.
				break;
			swap(a, i, j);								// 헤더 파일 속 swap 기능 사용으로 i,j위치 변경
		}
		swap(a, i, r);									// 헤더 파일 속 swap 기능 사용으로 i,r위치 변경
		QuickSort(a, l, i - 1);							// 배열 a 현재 정수 l, i-1값을 넣고 퀵 정렬 반복
		QuickSort(a, i + 1, r);							// 배열 a 현재 정수 i+1, r값을 넣고 퀵 정렬 반복
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
	printf("작은 부분화일을 고려한 퀵 정렬의 실행 시간 (N = %d) : %.0f\n", N, clock() - start_time);
	CheckSort(a, N);

	printf("아무키나 누르세요.\n");
	while (!_kbhit());
	fflush(stdin);
}