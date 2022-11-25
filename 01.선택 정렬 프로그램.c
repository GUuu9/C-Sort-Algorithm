#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>					

#define N 10000											// N을 10000으로 정의
#define TRUE 1											// TRUE를 1로 정의
#define FALSE 0											// FALSE를 0으로 정의 

void swap(int a[], int i, int j) {						// swap 함수에서 배열과 i, j번재 값을 받아온다.
	int t = a[i];										// 해당 함수는 배열의 i번째의 값과 j번째 값의
														// 순서를 서로 바꾸어 주는 역할을 한다.
	a[i] = a[j];					
	a[j] = t;
}

void CheckSort(int a[], int n) {						// CheckSort 함수는 배열과 N값을 받아
	int i, Sorted;										// swap 함수를 통해 값이 순서대로 배열되었는지
														// 확인 하는 함수 이다.
	Sorted = TRUE;

	for (i = 1; i < n; i++) {							// i가 n보다 작다면 계속 반복 후 i값을 1씩 증가한다.
		if (a[i] > a[i + 1])							// 현재값이 다음값 보다 크다면
			Sorted = FALSE;								// 올바르지 않은 배열로 값을 FALSE로 변경한다.
		if (!Sorted)									// 배열이 올바르지 않아 FALSE로 변경됬다면
			break;										// !Sorted는 현재 0으로 참이 아니기에 반복을 그만둔다.
	}

	if (Sorted)											// 들어온 Sorted 값이 여전히 TRUE, 1값이라면 참이므로					
		printf("정렬완료.\n");							// 정렬 완료 출력
	else												// Sorted 값이 중간에 FALSE, 0값으로 변경됬다면 거짓으로
		printf("정렬 오류 발생.\n");					// 정렬 오류 발생을 출력 한다.

}

void SelectionSort(int a[], int n) {					// 선택 정렬 알고리즘으로 배열과 n값을 받는다.
	int i, j, min;										// 배열을 위한 정수를 선언한다.

	for (i = 1; i < n; i++) {							// i가 n보다 작다면 계속 반복 후 i값을 1씩 증가한다.
		min = i;										// 현재 i값을 min값에 복사

		for (j = i + 1; j <= n; j++) {					// j값은 i+1값이며 j가 n보다 작거나 같다면 반복후 j값을 1 증가
			if (a[j] < a[min])							// 만약 j번째값이 현재 i(min)번째 값보다 작다면
				min = j;								// 헌재 j값을 min값에 복사
		}
		swap(a, min, i);								// 배열 a와 현재 j(min)값과, i값을 swap함수로 전달하여 순서를 바꾼다.
	}													// for 문이 종료 될때까지 반복한다.
}

void main() {
	int i, a[N + 1];									// 메인함수에서 정수 i와 배열a를 생성한다.
	double start_time;									// 실행 시간을 확인하기 위한 실수 start_time을 생성한다.

	srand(time(NULL));									// 시간값을 사용하여 난수 생성
	for (i = 1; i <= N; i++)										
		a[i] = rand();									// 반복문으로 i가 N값보다 커질때까지 계속 난수값을 a[i]배열에 넣는다.

	start_time = clock();								// 시작 시간을 start_time에 기록한다.
	SelectionSort(a, N);								// Selection 함수에 a배열과 N값을 전달. 
	printf("선택 정렬의 실행 시간 (N = %d) : %.0f\n", N, clock() - start_time);	
														// 현재 시간값에서 시작시간 값을빼서 경과 시간을 출력한다.
	CheckSort(a, N);									// CheckSort 값에 a와 N값을 보내 배열이 올바르게 정렬 되었는지 확인


	printf("아무키나 누르세요.\n");
	while (!_kbhit());									// 키보드 입력이 있을때 까지 반복한다.
	fflush(stdin);										// 입력된 버퍼를 제거한다.
}