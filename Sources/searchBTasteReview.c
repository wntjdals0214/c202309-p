#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchBTasteReview.h"


// 같은 취향의 리뷰어를 찾고 가중치를 부여하는 함수
void searchBTasteReview(int* restaurantCount, char(*review_task)[RESTAURANT_NAME], char(*B_review_task)[RESTAURANT_NAME], int* tastePoint, int* starpoints, int* B_starpoints, int* B_totalTastePoint) {
	for (int i = 0; i < *restaurantCount; i++) { // 사용자의 리뷰에 대한 for 문
		for (int j = 0; j < RESTAURANT_NUM; j++) { // B 이용자에 대한 for 문 
			if (strcmp(review_task[i], B_review_task[j]) == 0) { // 사용자와 B의 리뷰한 음식점의 이름이 같을시 실행
				*tastePoint = 5 - abs(starpoints[i] - B_starpoints[j]); // 두 별점차가 적을수록 더 높은 취향점수를 부여
				*B_totalTastePoint += *tastePoint; // B의 최종 취향점수에 추가
				*tastePoint = 0; // 취향점수를 초기화 시켜 다른 이용자의 취향점수를 구할 때 중복되지 않도록 함
			}
		}
	}
}