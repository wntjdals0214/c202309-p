#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AnewStarPoint.h"
void BnewStarPoint(int* restaurantCount, char(*review_task)[RESTAURANT_NAME], char(*B_review_task)[RESTAURANT_NAME], char(*B_newRecommend)[RESTAURANT_NAME], float* B_newStarPoint, int* B_starpoints, int* B_totalTastePoint, int* k, int* sameReview) {
	// B�� ���� ���
	printf("�̿��� B���� ��õ �Դϴ�.\n");
	for (int j = 0; j < RESTAURANT_NUM; j++) {
		*sameReview = 0;
		for (int i = 0; i < *restaurantCount; i++) {
			if (strcmp(review_task[i], B_review_task[j]) == 0) { // ���� ������ ������ �ߺ��� �н�
				*sameReview = 1;
			}
		}
		if (*sameReview == 0) { // ������ �ߺ��� �ƴҽ�(���ο� ������) ����ġ ���� ���
			strcpy_s(B_newRecommend[*k], sizeof(B_newRecommend[*k]), B_review_task[j]);
			*B_newStarPoint = (double)B_starpoints[j] * (double)*B_totalTastePoint / 10; //���ο� ����
			printf("%s:%f\n", B_newRecommend[*k], *B_newStarPoint);
			*k++;
		}
	}
}