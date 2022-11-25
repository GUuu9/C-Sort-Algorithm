#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include <conio.h>

#define N 10000												// N을 10000으로 정의


void BubbleSort(int a[], int n) {							// 버블 정렬 알고리즘으로 배열과 n값을 받는다.
	int i, j;												// 배열을 위한 정수 선언

	for (i = n; i >= 1; i--) {								// i가 1보다작아질때 까지 반복한다.
		for (j = 1; j < i; j++)								// j가 i값보다 커질때 까지 반복한다.
			if (a[j] > a[j + 1])							// 만약 j번째 값이 j+1값보다 크다면 
				swap(a, j, j + 1);							// sort 헤더 함수에 포함된 swap함수에  각 값들을 넣어 위치를 바꿈
	}
}
void main() {
	int i, a[N + 1];										// 메인함수에서 정수 i와 배열a를 생성한다.
	double start_time;										// 실행 시간을 확인하기 위한 실수 start_time을 생성한다.

	srand(time(NULL));										// 시간값을 사용하여 난수 생성
	for (i = 1; i <= N; i++)
		a[i] = rand();										// 반복문으로 i가 N값보다 커질때까지 계속 난수값을 
															// a[i]배열에 넣는다.

	start_time = clock();									// 시작 시간을 start_time에 기록한다.
	BubbleSort(a, N);										// BubbleSort 함수에 a배열과 N값을 전달. 
	printf("버블 정렬의 실행 시간 (N = %d) : %.0f\n", N, clock() - start_time); 
															// 현재 시간값에서 시작시간 값을빼서 경과 시간을 출력한다.
	CheckSort(a, N);										// CheckSort 값에 a와 N값을 보내 배열이 올바르게 정렬 되었는지
															// 확인


	printf("아무키나 누르세요.\n");
	while (!_kbhit());										// 키보드 입력이 있을때 까지 반복한다.
	fflush(stdin);											// 입력된 버퍼를 제거한다.
}