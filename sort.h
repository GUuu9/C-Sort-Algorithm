#include <stdio.h>

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