#include <stdio.h>
#define RESTAURANT_NUM 5 // �ִ� ���䰡�� ������ ��
#define RESTAURANT_NAME 100

char review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { "" }; // ������ �̸��� �����ϱ� ���� 2���� �迭
int starpoints[RESTAURANT_NUM];

int restaurantCount = 0; //���� ��Ͽ� ����� �������� ��

void addReview(char task[]) {
	if (restaurantCount == 5) {
		printf("�� �̻��� ����� �Ұ��� �մϴ�.");
		return;
	}
	printf("������ �̸��� �Է��ϼ��� (���� ���� �Է��ϼ���): ");
	scanf_s("%s", task, (int)sizeof(task));
	strcpy_s(review_task[restaurantCount], sizeof(review_task[restaurantCount]), task);
	
	printf("�������� ���� �ּ��� (���� 5�� ����): ");
	int starpoint = 0;
	scanf_s("%d", &starpoint);
	starpoints[restaurantCount] = starpoint;
	printf("%s�� ���� ���䰡 ����Ǿ����ϴ�. (����: %d)\n\n", task, starpoint);
}
void printReview(int restaurantCount) {
	printf("----���� ���----\n");
	for (int i = 0; i < restaurantCount; i++) {
		printf("%s : %d \n", review_task[i], starpoints[i]);
	}
	printf("\n");
}
int main() {
	while (1) {
		int choice = 0;
		printf("���� ������ ������ �� : %d\n����� �ִ� 5�� ���� �����մϴ�.\n", restaurantCount);
		printf("� ����� ��� �Ͻðڽ��ϱ�?\n");
		printf("1. �Ĵ� ���� ����\n2. ���� ��� ����\n3. ������ ��õ �ޱ�\n4. ����\n");
		printf("��ȣ�� �Է��ϼ���: ");
		scanf_s("%d", &choice);


		int logout = 0;

		switch (choice) {
		case 1:
			addReview(review_task[restaurantCount]);
			restaurantCount++;
			break;
		case 2:
			printReview(restaurantCount);
			break;
		case 3:

		case 4:
			logout = 1;
			break;
		default:
			printf("�ٽ� ������ �ּ���.\n");
		}

		if (logout == 1) {
			printf("���α׷��� �����մϴ�.\n");
			break;
		}
		if (restaurantCount == 5) {
			printf("���� ����� ���� á���ϴ�.\n");
		}

	}
	return 0;
}