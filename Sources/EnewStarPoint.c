#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AnewStarPoint.h"
void EnewStarPoint(int* restaurantCount, char(*review_task)[RESTAURANT_NAME], char(*E_review_task)[RESTAURANT_NAME], char(*E_newRecommend)[RESTAURANT_NAME], float* E_newStarPoint, int* E_starpoints, int* E_totalTastePoint, int* k, int* sameReview) {
	// E�� ���� ���
	printf("�̿��� E���� ��õ �Դϴ�.\n");
	for (int j = 0; j < RESTAURANT_NUM; j++) {
		*sameReview = 0;
		for (int i = 0; i < *restaurantCount; i++) {
			if (strcmp(review_task[i], E_review_task[j]) == 0) { // ���� ������ ������ �ߺ��� �н�
				*sameReview = 1;
			}
		}
		if (*sameReview == 0) { // ������ �ߺ��� �ƴҽ�(���ο� ������) ����ġ ���� ���
			strcpy_s(E_newRecommend[*k], sizeof(E_newRecommend[*k]), E_review_task[j]);
			*E_newStarPoint = (double)E_starpoints[j] * (double)*E_totalTastePoint / 10; //���ο� ����
			printf("%s:%f\n", E_newRecommend[*k], *E_newStarPoint);
			*k++;
		}
	}
}