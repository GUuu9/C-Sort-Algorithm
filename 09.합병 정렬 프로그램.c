#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include <conio.h>

#define N 10000

int b[N + 1];											// b배열 선언

void MergeSort(int a[], int l, int r) {					// 합병 정렬 알고리즘으로 배열
	int i, j, k, m;										// 정수를 선언한다.

	if (r > l) {
		m = (r + l) / 2;
		MergeSort(a, l, m);								// 배열 a 현재 정수 l, m값을 넣고 합병 정렬 반복
		MergeSort(a, m + 1, r);							// 배열 a 현재 정수 m+1, r값을 넣고 합병 정렬 반복

		for (i = m + 1; i > l; i--)						// i값을 계속 감소 시키며 l보다 같거나 작아질때 까지
			b[i - 1] = a[i - 1];						// b배열에 a배열 값을 복사
		for (j = m; j < r; j++)							// j값을 계속 증가 시키며 r보다 같거나 커질때 까지
			b[r + m - j] = a[j + 1];					// b배열에 a배열 값을 복사
		for (k = l; k <= r; k++)						// k값을 계속 증가시키며 k값이 r보다 커질때 까지
			a[k] = (b[i] < b[j]) ? b[i++] : b[j--];		// a배열에 b[i]와 b[j]값 비교후 값이 참이면 i값 증가
	}													// 거짓이면 j값 감소
}

void main() {
	int i, a[N + 1];									// 메인함수에서 정수 i와 배열a를 생성한다.
	double start_time;									// 실행 시간을 확인하기 위한 실수 start_time을 생성한다.

	srand(time(NULL));									// 시간값을 사용하여 난수 생성
	for (i = 1; i <= N; i++)
		a[i] = rand();									// 반복문으로 i가 N값보다 커질때까지 계속 난수값을 a[i]배열에 넣는다.

	start_time = clock();								// 시작 시간을 start_time에 기록한다.
	MergeSort(a, 1, N);									// MergeSort 함수에 a배열과 N값을 전달. 
	printf("합병 정렬의 실행 시간 (N = %d) : %.0f\n", N, clock() - start_time);
														// 현재 시간값에서 시작시간 값을빼서 경과 시간을 출력한다.
	CheckSort(a, N);									// CheckSort 값에 a와 N값을 보내 배열이 올바르게 정렬 되었는지 확인


	printf("아무키나 누르세요.\n");
	while (!_kbhit());									// 키보드 입력이 있을때 까지 반복한다.
	fflush(stdin);										// 입력된 버퍼를 제거한다
}