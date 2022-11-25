void QuickSort(int a[], int l, int r) {					// 퀵 정렬 알고리즘으로 배열 
	int i, j, v;										// 정수를 선언한다.
	
	if (r > l) {										// r이 l값보다 크면 if문 실행 처음 l값은 1이다.
		v = a[r];										// 현재 배열의 값을 v에 저장
		i = l - 1;										// i에 l - 1값을 저장
		j = r;											// j 에 r 저장
			
		for (;;) {										// 중간 if문에서 i>=j를 만족할때까지 무한 반복한다.
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