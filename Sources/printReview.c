#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printReview.h"


// ���� ��� ���� �Լ�
void printReview(int* restaurantCount, int* starpoints, char(*review_task)[RESTAURANT_NAME]) {
	printf("----���� ���----\n"); // for���� ���� �迭�� ����� ����� ������ ������� ���
	for (int i = 0; i < *restaurantCount; i++) {
		printf("%s : %d \n", review_task[i], starpoints[i]);
	}
	printf("\n");
}