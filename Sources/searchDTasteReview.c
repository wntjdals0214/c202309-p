#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchDTasteReview.h"


// ���� ������ ���� ã�� ����ġ�� �ο��ϴ� �Լ�
void searchDTasteReview(int* restaurantCount, char(*review_task)[RESTAURANT_NAME], char(*D_review_task)[RESTAURANT_NAME], int* tastePoint, int* starpoints, int* D_starpoints, int* D_totalTastePoint) {
	for (int i = 0; i < *restaurantCount; i++) { // ������� ���信 ���� for ��
		for (int j = 0; j < RESTAURANT_NUM; j++) { // D �̿��ڿ� ���� for �� 
			if (strcmp(review_task[i], D_review_task[j]) == 0) { // ����ڿ� D�� ������ �������� �̸��� ������ ����
				*tastePoint = 5 - abs(starpoints[i] - D_starpoints[j]); // �� �������� �������� �� ���� ���������� �ο�
				*D_totalTastePoint += *tastePoint; // D�� ���� ���������� �߰�
				*tastePoint = 0; // ���������� �ʱ�ȭ ���� �ٸ� �̿����� ���������� ���� �� �ߺ����� �ʵ��� ��
			}
		}
	}
}