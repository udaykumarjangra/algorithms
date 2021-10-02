#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct St {
	int first;
	int second;
};

typedef struct St st;

int main() 
{
	int N, i, j, min;
	printf("Enter the Number of elements:\n");
	
	scanf("%d", &N);

	st A[10000];
	st temp, key;
	srand(time(0));
	for (i = 0; i < N; i++) {
		//scanf("%d",&A[i]);
		A[i].first = rand() % 10000;
	}
	for (i = 0; i < N; i++) {
		//scanf("%d",&A[i]);
		A[i].second = rand() % 10000;
	}


	for (i = 0; i < N; i++) {
		printf("FIRST-%d | SECOND-%d\n", A[i].first, A[i].second);

	}
	//BASIC SELECTION SORT ACC TO FIRST:--

	//for (i = 0; i < N - 1; i++) {
	//	min = i;
	//	for (j = i + 1; j < N; j++) {
	//		if (A[min].first > A[j].first)
	//			min = j;
	//	}
	//	temp = A[i];
	//	A[i] = A[min];
	//	A[min] = temp;
	//}

	//printf("\nBASIC SELECTION SORT ACC TO FIRST PART OF STRUCT\n");
	//for (i = 0; i < N; i++) {
	//	printf("FIRST-%d | SECOND-%d\n", A[i].first, A[i].second);

	//}



	//STABLE SELECTION SORT ACC TO FIRST:--

	for (i = 0; i < N - 1; i++) {
		min = i;
		for (j = i + 1; j < N; j++) {
			if (A[min].second > A[j].second)
				min = j;
		}
		key = A[min];
		while (min > i) {
			A[min] = A[min - 1];
			min--;
		}
		A[i] = key;
	}

	printf("\nStable Selection sort applied to Second Section of the structure\n\n");
	for (i = 0; i < N; i++) {
		printf("FIRST-%d | SECOND-%d\n", A[i].first, A[i].second);

	}

}
