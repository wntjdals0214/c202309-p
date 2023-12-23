#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "searchETasteReview.h"


// ���� ������ ���� ã�� ����ġ�� �ο��ϴ� �Լ�
void searchETasteReview(int* restaurantCount, char(*review_task)[RESTAURANT_NAME], char(*E_review_task)[RESTAURANT_NAME], int* tastePoint, int* starpoints, int* E_starpoints, int* E_totalTastePoint) {
	for (int i = 0; i < *restaurantCount; i++) { // ������� ���信 ���� for ��
		for (int j = 0; j < RESTAURANT_NUM; j++) { // E �̿��ڿ� ���� for �� 
			if (strcmp(review_task[i], E_review_task[j]) == 0) { // ����ڿ� E�� ������ �������� �̸��� ������ ����
				*tastePoint = 5 - abs(starpoints[i] - E_starpoints[j]); // �� �������� �������� �� ���� ���������� �ο�
				*E_totalTastePoint += *tastePoint; // E�� ���� ���������� �߰�
				*tastePoint = 0; // ���������� �ʱ�ȭ ���� �ٸ� �̿����� ���������� ���� �� �ߺ����� �ʵ��� ��
			}
		}
	}
}