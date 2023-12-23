#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AnewStarPoint.h"
void CnewStarPoint(int* restaurantCount, char(*review_task)[RESTAURANT_NAME], char(*C_review_task)[RESTAURANT_NAME], char(*C_newRecommend)[RESTAURANT_NAME], float* C_newStarPoint, int* C_starpoints, int* C_totalTastePoint, int* k, int* sameReview) {
	// C에 대한 계산
	printf("이용자 C님의 추천 입니다.\n");
	for (int j = 0; j < RESTAURANT_NUM; j++) {
		*sameReview = 0;
		for (int i = 0; i < *restaurantCount; i++) {
			if (strcmp(review_task[i], C_review_task[j]) == 0) { // 내가 리뷰한 음식점 중복시 패스
				*sameReview = 1;
			}
		}
		if (*sameReview == 0) { // 음식점 중복이 아닐시(새로운 음식점) 가중치 별점 계산
			strcpy_s(C_newRecommend[*k], sizeof(C_newRecommend[*k]), C_review_task[j]);
			*C_newStarPoint = (double)C_starpoints[j] * (double)*C_totalTastePoint / 10; //새로운 별점
			printf("%s:%f\n", C_newRecommend[*k], *C_newStarPoint);
			*k++;
		}
	}
}