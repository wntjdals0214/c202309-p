#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AnewStarPoint.h"
void CnewStarPoint(int* restaurantCount, char(*review_task)[RESTAURANT_NAME], char(*C_review_task)[RESTAURANT_NAME], char(*C_newRecommend)[RESTAURANT_NAME], float* C_newStarPoint, int* C_starpoints, int* C_totalTastePoint, int* k, int* sameReview) {
	// C�� ���� ���
	printf("�̿��� C���� ��õ �Դϴ�.\n");
	for (int j = 0; j < RESTAURANT_NUM; j++) {
		*sameReview = 0;
		for (int i = 0; i < *restaurantCount; i++) {
			if (strcmp(review_task[i], C_review_task[j]) == 0) { // ���� ������ ������ �ߺ��� �н�
				*sameReview = 1;
			}
		}
		if (*sameReview == 0) { // ������ �ߺ��� �ƴҽ�(���ο� ������) ����ġ ���� ���
			strcpy_s(C_newRecommend[*k], sizeof(C_newRecommend[*k]), C_review_task[j]);
			*C_newStarPoint = (double)C_starpoints[j] * (double)*C_totalTastePoint / 10; //���ο� ����
			printf("%s:%f\n", C_newRecommend[*k], *C_newStarPoint);
			*k++;
		}
	}
}