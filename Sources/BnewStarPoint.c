#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AnewStarPoint.h"
void BnewStarPoint(int* restaurantCount, char(*review_task)[RESTAURANT_NAME], char(*B_review_task)[RESTAURANT_NAME], char(*B_newRecommend)[RESTAURANT_NAME], float* B_newStarPoint, int* B_starpoints, int* B_totalTastePoint, int* k, int* sameReview) {
	// B에 대한 계산
	printf("이용자 B님의 추천 입니다.\n");
	for (int j = 0; j < RESTAURANT_NUM; j++) {
		*sameReview = 0;
		for (int i = 0; i < *restaurantCount; i++) {
			if (strcmp(review_task[i], B_review_task[j]) == 0) { // 내가 리뷰한 음식점 중복시 패스
				*sameReview = 1;
			}
		}
		if (*sameReview == 0) { // 음식점 중복이 아닐시(새로운 음식점) 가중치 별점 계산
			strcpy_s(B_newRecommend[*k], sizeof(B_newRecommend[*k]), B_review_task[j]);
			*B_newStarPoint = (double)B_starpoints[j] * (double)*B_totalTastePoint / 10; //새로운 별점
			printf("%s:%f\n", B_newRecommend[*k], *B_newStarPoint);
			*k++;
		}
	}
}