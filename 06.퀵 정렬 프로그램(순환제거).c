#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"
#include <conio.h>

#define N 100000										// N을 100000으로 정의
#define MAX_STACK_SIZE 100								// MAX_STACK_SIZE을 100으로 정의

int stack[MAX_STACK_SIZE];								// stack[] 전역 배열을 생성
int top = -1;											// -1값을 가지는 top생성

void push(int *top, int item) {							// push함수 top 포인터 과 item값을 받는다
	stack[++*top] = item;								// 들어온 top값보다 1증가한 위치에 item의 값을 넣는다.
}

int pop(int *top) {										// top 포인터값을 받는다.
	return stack[(*top)--];								// 현재 top값에서 1 감소한 값을 반환한다.
}

int partition(int a[], int l, int r) {					// 배열 a와 정수 l,r값을 받아온다.
	int i, j, v;										// 정수 생성

	v = a[r];											// 현재 a[r]위치의 값을 v에 저장
	i = l - 1;											// l-1값을 i에 저장
	j = r;												// j에 r 값을 저장

	for (;;) {								
		while (a[++i] < v);							// a[i]가 v값보다 커질때까지 i값을 증가한다.
		while (a[--j] > v);							// a[j]가 v값보다 작아질때까지 j값을 감소한다.

		if (i >= j)									// i가 j보다 크거나 같아지면 for문을 탈출한다.
			break;

		swap(a, i, j);								// 헤더 파일 속 swap 기능 사용으로 i,j위치 변경
	}

	swap(a, i, r);									// 헤더 파일 속 swap 기능 사용으로 i,r위치 변경
	return i;										// i값을 반환한다.
}

void QuickSort(int a[], int l, int r) {				// 배얄 a와 정수 l,r을 받아온다
	int i, j, v;									// 정수 생성

	for (;;) {										// 무한 반복문
		while (r > l) {								// r값이 l보다 큰 동안에 반복
			i = partition(a, l, r);					// i에 파티션 함수값 을 저장

			if (i - l > r - i) {					// 만약 i - l > r - i이라면 if문 실행
				push(&top, l);						// push함수에 데이터 전달
				push(&top, i - 1);					// push함수에 데이터 전달
				l = i + 1;							// l에 i+1값 저장
			}

			else {									// 만약 i - l > r - i이 아니라면 else문 실행
				push(&top, i+1);					// push함수에 데이터 전달
				push(&top, r);						// push함수에 데이터 전달
				r = i - 1;							// r에 i-1값 저장
			}
		}

		if (top < 0)								// 만약 top값이 0보다 작으면 반복문 탈출후 기능 종료
			break;

		r = pop(&top);								// r에 pop 함수값 을 저장
		l = pop(&top);								// l에 pop 함수값 을 저장

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
	printf("순환을 제거한 퀵 정렬의 실행 시간 (N = %d) : %.0f\n", N, clock() - start_time);
	CheckSort(a, N);

	printf("아무키나 누르세요.\n");
	while (!_kbhit());
	fflush(stdin);
}