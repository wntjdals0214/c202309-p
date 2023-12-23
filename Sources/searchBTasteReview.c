#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchBTasteReview.h"


// ���� ������ ���� ã�� ����ġ�� �ο��ϴ� �Լ�
void searchBTasteReview(int* restaurantCount, char(*review_task)[RESTAURANT_NAME], char(*B_review_task)[RESTAURANT_NAME], int* tastePoint, int* starpoints, int* B_starpoints, int* B_totalTastePoint) {
	for (int i = 0; i < *restaurantCount; i++) { // ������� ���信 ���� for ��
		for (int j = 0; j < RESTAURANT_NUM; j++) { // B �̿��ڿ� ���� for �� 
			if (strcmp(review_task[i], B_review_task[j]) == 0) { // ����ڿ� B�� ������ �������� �̸��� ������ ����
				*tastePoint = 5 - abs(starpoints[i] - B_starpoints[j]); // �� �������� �������� �� ���� ���������� �ο�
				*B_totalTastePoint += *tastePoint; // B�� ���� ���������� �߰�
				*tastePoint = 0; // ���������� �ʱ�ȭ ���� �ٸ� �̿����� ���������� ���� �� �ߺ����� �ʵ��� ��
			}
		}
	}
}