#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AnewStarPoint.h"
void AnewStarPoint(int* restaurantCount, char(*review_task)[RESTAURANT_NAME], char(*A_review_task)[RESTAURANT_NAME], char(*A_newRecommend)[RESTAURANT_NAME], float* A_newStarPoint, int* A_starpoints, int* A_totalTastePoint, int* k, int* sameReview) {
	// A�� ���� ���
	printf("�̿��� A���� ��õ �Դϴ�.\n");
	for (int j = 0; j < RESTAURANT_NUM; j++) {
		*sameReview = 0;
		for (int i = 0; i < *restaurantCount; i++) {
			if (strcmp(review_task[i], A_review_task[j]) == 0) { // ���� ������ ������ �ߺ��� �н�
				*sameReview = 1;
			}
		}
		if (*sameReview == 0) { // ������ �ߺ��� �ƴҽ�(���ο� ������) ����ġ ���� ���
			strcpy_s(A_newRecommend[*k], sizeof(A_newRecommend[*k]), A_review_task[j]);
			*A_newStarPoint = (double)A_starpoints[j] * (double)*A_totalTastePoint / 10; //���ο� ����
			printf("%s:%f\n", A_newRecommend[*k], *A_newStarPoint);
			*k++;
		}
	}
}