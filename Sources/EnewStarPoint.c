#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AnewStarPoint.h"
void EnewStarPoint(int* restaurantCount, char(*review_task)[RESTAURANT_NAME], char(*E_review_task)[RESTAURANT_NAME], char(*E_newRecommend)[RESTAURANT_NAME], float* E_newStarPoint, int* E_starpoints, int* E_totalTastePoint, int* k, int* sameReview) {
	// E에 대한 계산
	printf("이용자 E님의 추천 입니다.\n");
	for (int j = 0; j < RESTAURANT_NUM; j++) {
		*sameReview = 0;
		for (int i = 0; i < *restaurantCount; i++) {
			if (strcmp(review_task[i], E_review_task[j]) == 0) { // 내가 리뷰한 음식점 중복시 패스
				*sameReview = 1;
			}
		}
		if (*sameReview == 0) { // 음식점 중복이 아닐시(새로운 음식점) 가중치 별점 계산
			strcpy_s(E_newRecommend[*k], sizeof(E_newRecommend[*k]), E_review_task[j]);
			*E_newStarPoint = (double)E_starpoints[j] * (double)*E_totalTastePoint / 10; //새로운 별점
			printf("%s:%f\n", E_newRecommend[*k], *E_newStarPoint);
			*k++;
		}
	}
}