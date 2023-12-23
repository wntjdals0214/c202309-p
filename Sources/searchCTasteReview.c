#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchCTasteReview.h"


// ���� ������ ���� ã�� ����ġ�� �ο��ϴ� �Լ�
void searchCTasteReview(int* restaurantCount, char(*review_task)[RESTAURANT_NAME], char(*C_review_task)[RESTAURANT_NAME], int* tastePoint, int* starpoints, int* C_starpoints, int* C_totalTastePoint) {
	for (int i = 0; i < *restaurantCount; i++) { // ������� ���信 ���� for ��
		for (int j = 0; j < RESTAURANT_NUM; j++) { // C �̿��ڿ� ���� for �� 
			if (strcmp(review_task[i], C_review_task[j]) == 0) { // ����ڿ� C�� ������ �������� �̸��� ������ ����
				*tastePoint = 5 - abs(starpoints[i] - C_starpoints[j]); // �� �������� �������� �� ���� ���������� �ο�
				*C_totalTastePoint += *tastePoint; // C�� ���� ���������� �߰�
				*tastePoint = 0; // ���������� �ʱ�ȭ ���� �ٸ� �̿����� ���������� ���� �� �ߺ����� �ʵ��� ��
			}
		}
	}
}