#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include <conio.h>

#define N 100000

void QuickSort(int a[], int l, int r) {
	int i, j, m, v;										// 정수 선언

	if (r - l > 1) {									// r - l > 1이면 if문 실행
		m = (l + r) / 2;
		if (a[l] > a[m])
			swap(a, l, m);								// 헤더 파일 속 swap 기능 사용으로 l,m위치 변경
		if (a[l] > a[r])
			swap(a, l, r);								// 헤더 파일 속 swap 기능 사용으로 l,r위치 변경
		if (a[m] > a[r])
			swap(a, m, r);								// 헤더 파일 속 swap 기능 사용으로 m,r위치 변경

		swap(a, m, r - 1);								// 헤더 파일 속 swap 기능 사용으로 m,r-1위치 변경

		v = a[r-1];										// 배열의 값을 v에 저장
		i = l;											// i에 l값을 저장
		j = r-1;										// j 에 r - 1저장

		for (;;) {
			while (a[++i] < v);							// a[i]가 v값보다 커질때까지 i값을 증가한다.
			while (a[--j] > v);							// a[j]가 v값보다 작아질때까지 j값을 감소한다.
			if (i >= j)									// i가 j보다 크거나 같아지면 for문을 탈출한다.
				break;
			swap(a, i, j);								// 헤더 파일 속 swap 기능 사용으로 i,j위치 변경
		}
		swap(a, i, r-1);								// 헤더 파일 속 swap 기능 사용으로 i,r-1위치 변경
		QuickSort(a, l, i - 1);							// 배열 a 현재 정수 l, i-1값을 넣고 퀵 정렬 반복
		QuickSort(a, i + 1, r);							// 배열 a 현재 정수 i+1, r값을 넣고 퀵 정렬 반복
	}
	else												// r - l > 1이 아니라면 else문 실행
		if (a[l] > a[r]) 
			swap(a, l, r);								// 헤더 파일 속 swap 기능 사용으로 l,r위치 변경
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