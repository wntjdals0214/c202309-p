#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "printReview.h"
#include "searchATasteReview.h"
#include "searchBTasteReview.h"
#include "searchCTasteReview.h"
#include "searchDTasteReview.h"
#include "searchETasteReview.h"
#include "AnewStarPoint.h"
#include "BnewStarPoint.h"
#include "CnewStarPoint.h"
#include "DnewStarPoint.h"
#include "EnewStarPoint.h"

// �̿����� ����� ������ ������ ����ü
struct ReviewInfo {
	char* name;
	int starpoint;
};

char review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { "" }; // ������ �̸��� �����ϱ� ���� 2���� �迭
int starpoints[RESTAURANT_NUM]; // ������ �����ϱ� ���� �迭
int tastepoints[RESTAURANT_NUM]; // ����ġ�� �����ϱ� ���� �Լ�

int tastePoint = 0; // ���������� �����ϱ� ���� ����
int sameReview = 0; // ���䰡 ������ �ٸ����� �Ǵ��ϱ� ���� ����
int k = 0;

// ��� ������ ���� 5���� �ٸ� �̿��� ����
char A_review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { {"b"},{"c"},{"d"},{"e"},{"g"} }; // ������ �̸�
int A_starpoints[RESTAURANT_NUM] = { 2,1,4,4,4 }; // ����
int A_totalTastePoint = 0; // ����ġ ������ ���� ����
float A_newStarPoint; // ����ġ�� �����Ͽ� ������ ����
char A_newRecommend[RESTAURANT_NUM][RESTAURANT_NAME] = { "" }; // A�� ���ο� ������ ��õ �̸��� ������ �迭
float A_newStarPoints[RESTAURANT_NUM]; // A�� ���ο� ������ ��õ ������ ������ �迭

// ���� A�� ������ ������ �ٸ� 4���� ������ 
char B_review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { {"b"},{"c"},{"d"},{"e"},{"g"} };
int B_starpoints[RESTAURANT_NUM] = { 4,5,4,4,3 };
int B_totalTastePoint = 0;
float B_newStarPoint;
char B_newRecommend[RESTAURANT_NUM][RESTAURANT_NAME] = { "" };
float B_newStarPoints[RESTAURANT_NUM];

char C_review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { {"a"},{"b"},{"d"},{"f"},{"g"} };
int C_starpoints[RESTAURANT_NUM] = { 4,3,1,2,4 };
int C_totalTastePoint = 0;
float C_newStarPoint;
char C_newRecommend[RESTAURANT_NUM][RESTAURANT_NAME] = { "" };
float C_newStarPoints[RESTAURANT_NUM];

char D_review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { {"a"},{"b"},{"c"},{"h"},{"f"} };
int D_starpoints[RESTAURANT_NUM] = { 3,5,5,4,5 };
int D_totalTastePoint = 0;
float D_newStarPoint;
char D_newRecommend[RESTAURANT_NUM][RESTAURANT_NAME] = { "" };
float D_newStarPoints[RESTAURANT_NUM];

char E_review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { {"a"},{"c"},{"d"},{"e"},{"f"} };
int E_starpoints[RESTAURANT_NUM] = { 4,3,4,5,3 };
int E_totalTastePoint = 0;
float E_newStarPoint;
char E_newRecommend[RESTAURANT_NUM][RESTAURANT_NAME] = { "" };
float E_newStarPoints[RESTAURANT_NUM];


// 1. �Ĵ� ���� ���� �Լ�
void addReview(char task[], int* restaurantCount, int* starpoints, char(*review_task)[RESTAURANT_NAME], struct ReviewInfo* review, int i) {
	if (*restaurantCount == 5) { // ���䰡 �� á�� ��
		printf("�� �̻��� ����� �Ұ��� �մϴ�.");
		return;
	}
	// ���� �ۼ� �ϱ�
	printf("������ �̸��� �Է��ϼ��� (���� ���� �Է��ϼ���): ");
	scanf_s("%s", task, (int)sizeof(task));
	strcpy_s(review_task[*restaurantCount], sizeof(review_task[*restaurantCount]), task); // 2���� �迭�� ������ ����
	// ����ü�� �����ϱ� ���� �ѹ� �� �Է�
	printf("�ѹ� �� �Է����ּ���: ");
	char temp[100];
	scanf_s("%s", temp, (int)sizeof(temp));
	review->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy_s(review->name, strlen(temp) + 1, temp);

	printf("�������� ���� �ּ��� (���� 5�� ����): ");
	int starpoint = 0;
	scanf_s("%d", &starpoint);
	starpoints[*restaurantCount] = starpoint; // �迭�� ����
	// ����ü�� �����ϱ� ���� �ѹ� �� �Է�
	printf("�ѹ� �� �Է����ּ���: ");
	scanf_s("%d", &review->starpoint);
	printf("%s�� ���� ���䰡 ����Ǿ����ϴ�. (����: %d)\n\n", task, starpoint);

}


int main() {

	char review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { "" }; // ������ �̸��� �����ϱ� ���� 2���� �迭
	int starpoints[RESTAURANT_NUM]; // ������ �����ϱ� ���� �迭
	int restaurantCount = 0; //���� ��Ͽ� ����� �������� ��

	while (1) {
		int choice = 0;
		printf("���� ������ ������ �� : %d\n����� �ִ� 5�� ���� �����մϴ�.\n", restaurantCount);
		printf("� ����� ��� �Ͻðڽ��ϱ�?\n");
		printf("1. �Ĵ� ���� ����\n2. ���� ��� ����\n3. ������ ��õ �ޱ�\n4. ����\n");
		printf("��ȣ�� �Է��ϼ���: ");
		scanf_s("%d", &choice);


		int logout = 0; // ���α׷� ���Ḧ ���� ����

		switch (choice) {
		case 1: {
			struct ReviewInfo* reviews = (struct ReviewInfo*)malloc(RESTAURANT_NUM * sizeof(struct ReviewInfo));
			if (reviews == NULL) {
				return 1;
			}
			addReview(review_task[restaurantCount], &restaurantCount, starpoints, review_task, &reviews[restaurantCount], restaurantCount);
			restaurantCount++;
			break;
		}
		case 2:
			printReview(&restaurantCount, starpoints, review_task);
			break;
		case 3:
			searchATasteReview(&restaurantCount, review_task, A_review_task, &tastePoint, starpoints, A_starpoints, &A_totalTastePoint);
			searchBTasteReview(&restaurantCount, review_task, B_review_task, &tastePoint, starpoints, B_starpoints, &B_totalTastePoint);
			searchCTasteReview(&restaurantCount, review_task, C_review_task, &tastePoint, starpoints, C_starpoints, &C_totalTastePoint);
			searchDTasteReview(&restaurantCount, review_task, D_review_task, &tastePoint, starpoints, D_starpoints, &D_totalTastePoint);
			searchETasteReview(&restaurantCount, review_task, E_review_task, &tastePoint, starpoints, E_starpoints, &E_totalTastePoint);
			printf("%d\n", A_totalTastePoint);
			printf("%d\n", B_totalTastePoint);
			printf("%d\n", C_totalTastePoint);
			printf("%d\n", D_totalTastePoint);
			printf("%d\n", E_totalTastePoint);
			AnewStarPoint(&restaurantCount, review_task, A_review_task, A_newRecommend, &A_newStarPoint, A_starpoints, &A_totalTastePoint, &k, &sameReview);
			BnewStarPoint(&restaurantCount, review_task, B_review_task, B_newRecommend, &B_newStarPoint, B_starpoints, &B_totalTastePoint, &k, &sameReview);
			CnewStarPoint(&restaurantCount, review_task, C_review_task, C_newRecommend, &C_newStarPoint, C_starpoints, &C_totalTastePoint, &k, &sameReview);
			DnewStarPoint(&restaurantCount, review_task, D_review_task, D_newRecommend, &D_newStarPoint, D_starpoints, &D_totalTastePoint, &k, &sameReview);
			EnewStarPoint(&restaurantCount, review_task, E_review_task, E_newRecommend, &E_newStarPoint, E_starpoints, &E_totalTastePoint, &k, &sameReview);
			break;
		case 4:
			logout = 1;
			break;
		default:
			printf("�ٽ� ������ �ּ���.\n");
		}

		if (logout == 1) { // ���ắ���� 1 �Ͻ� ���α׷� ����
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		if (restaurantCount == 5) { // ���䰡 5�� �� á���� ���
			printf("���� ����� ���� á���ϴ�.\n");
		}

	}
	return 0;
}