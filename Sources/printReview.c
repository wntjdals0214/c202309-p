#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printReview.h"


// 리뷰 목록 보기 함수
void printReview(int* restaurantCount, int* starpoints, char(*review_task)[RESTAURANT_NAME]) {
	printf("----리뷰 목록----\n"); // for문을 통해 배열에 저장된 리뷰와 별점을 순서대로 출력
	for (int i = 0; i < *restaurantCount; i++) {
		printf("%s : %d \n", review_task[i], starpoints[i]);
	}
	printf("\n");
}