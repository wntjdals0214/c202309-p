#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AnewStarPoint.h"
void DnewStarPoint(int* restaurantCount, char(*review_task)[RESTAURANT_NAME], char(*D_review_task)[RESTAURANT_NAME], char(*D_newRecommend)[RESTAURANT_NAME], float* D_newStarPoint, int* D_starpoints, int* D_totalTastePoint, int* k, int* sameReview) {
	// D�� ���� ���
	printf("�̿��� D���� ��õ �Դϴ�.\n");
	for (int j = 0; j < RESTAURANT_NUM; j++) {
		*sameReview = 0;
		for (int i = 0; i < *restaurantCount; i++) {
			if (strcmp(review_task[i], D_review_task[j]) == 0) { // ���� ������ ������ �ߺ��� �н�
				*sameReview = 1;
			}
		}
		if (*sameReview == 0) { // ������ �ߺ��� �ƴҽ�(���ο� ������) ����ġ ���� ���
			strcpy_s(D_newRecommend[*k], sizeof(D_newRecommend[*k]), D_review_task[j]);
			*D_newStarPoint = (double)D_starpoints[j] * (double)*D_totalTastePoint / 10; //���ο� ����
			printf("%s:%f\n", D_newRecommend[*k], *D_newStarPoint);
			*k++;
		}
	}
}