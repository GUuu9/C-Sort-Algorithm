#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include <conio.h>

#define N 10000											// N을 10000으로 정의


void InsertionSort(int a[], int n) {					// 삽입 정렬 알고리즘이며 배열과 N값을 받아온다.	
	int i, j, v;										// 정수 i, j, v 생성

	for (i = 2; i <= n; i++) {							// i는 2부터 n값보다 커질때까지 반복하며 i는 1씩 증가
		v = a[i];										// v에 현재 배열값 삽입
		j = i;											// 배열 번호인 i값을 j에 삽입.

		while (a[j - 1] > v) {							// 현재 배열보다 1만큼 작은 값이 현재 배열값보다 큰동안 반복
			a[j] = a[j - 1];							// 현재 위치의 배열값에  현 위치보다 하나 작은 배열의 값을 저장.
			j--;										// j값 1만큼 감소 자리가 한칸씩 이동되서 저장되는 형식이다.
		}
		a[j] = v;										// 원래 있던 v값을 a[j]에 저장한다.
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
	InsertionSort(a, N);
	printf("삽입 정렬의 실행 시간 (N = %d) : %.0f\n", N, clock() - start_time);
														// 현재 시간값에서 시작시간 값을빼서 경과 시간을 출력한다.
	CheckSort(a, N);									// CheckSort 값에 a와 N값을 보내 배열이 올바르게 정렬 되었는지 확인


	printf("아무키나 누르세요.\n");
	while (!_kbhit());									// 키보드 입력이 있을때 까지 반복한다.
	fflush(stdin);										// 입력된 버퍼를 제거한다.
}