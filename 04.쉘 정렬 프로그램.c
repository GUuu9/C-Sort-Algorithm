#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include <conio.h>

#define N 10000											// N을 10000으로 정의


void ShellSort(int a[], int n) {						// 쉘 정렬 알고리즘이며 배열a와 n값을 받아온다
	int i, j, h, v;										// 정수 생성
	for (h = 1; h < n; h = 3 * h + 1);					// h 값이 n보다 커질때 까지 반복하며 h값은 3h+1만큼씩 커진다.
	for (; h>0;h/=3)									// h 값이 0보다 작아질때 까지 반족하며 h/3씩 줄어든다.
		for (i = h + 1; i <= n; i++) {					// 현재 값부터 계속 크기를 비교한다.
			v = a[i];									// v에 현재 배열값을 복사
			j = i;										// 현 위지 값을 j에 저장한다.
			while (j > h && a[j - h] > v) {				// j값이 h값보다 크고 a[j-h]가 v보다 큰경우에 
				a[j] = a[j - h];						// a[j-h]값을 a[j]에 저장한다.
				j -= h;									// j값을 h값만큼 뺀 값을 j에 저장한다.
			}
			a[j] = v;									// 원래의 값을 j의 값에 저장해준다.
		}
}
void main() {
	int i, a[N + 1];									// 메인함수에서 정수 i와 배열a를 생성한다.
	double start_time;									// 실행 시간을 확인하기 위한 실수 start_time을 생성한다.

	a[0] = -1;											// 감시 키 : 이후 배열의 값보다 작은 값
	srand(time(NULL));									// 시간값을 사용하여 난수 생성
	for (i = 1; i <= N; i++)
		a[i] = rand();									// 반복문으로 i가 N값보다 커질때까지 계속 난수값을 a[i]배열에 넣는다.

	start_time = clock();								// 시작 시간을 start_time에 기록한다.
	ShellSort(a, N);									// ShellSort 함수에 a배열과 N값을 전달. 
	printf("쉘 정렬의 실행 시간 (N = %d) : %.0f\n", N, clock() - start_time);
														// 현재 시간값에서 시작시간 값을빼서 경과 시간을 출력한다.
	CheckSort(a, N);									// CheckSort 값에 a와 N값을 보내 배열이 올바르게 정렬 되었는지 확인


	printf("아무키나 누르세요.\n");
	while (!_kbhit());									// 키보드 입력이 있을때 까지 반복한다.
	fflush(stdin);										// 입력된 버퍼를 제거한다.
}