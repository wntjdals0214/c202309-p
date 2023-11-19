#include <stdio.h>
#define RESTAURANT_NUM 5 // 최대 리뷰가능 음식점 수
#define RESTAURANT_NAME 100

char review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { "" }; // 음식점 이름을 저장하기 위한 2차원 배열
int starpoints[RESTAURANT_NUM];

int restaurantCount = 0; //리뷰 목록에 저장된 음식점의 수

void addReview(char task[]) {
	if (restaurantCount == 5) {
		printf("더 이상의 리뷰는 불가능 합니다.");
		return;
	}
	printf("음식점 이름을 입력하세요 (공백 없이 입력하세요): ");
	scanf_s("%s", task, (int)sizeof(task));
	strcpy_s(review_task[restaurantCount], sizeof(review_task[restaurantCount]), task);
	
	printf("음식점을 평가해 주세요 (별점 5점 만점): ");
	int starpoint = 0;
	scanf_s("%d", &starpoint);
	starpoints[restaurantCount] = starpoint;
	printf("%s에 대한 리뷰가 저장되었습니다. (별점: %d)\n\n", task, starpoint);
}
void printReview(int restaurantCount) {
	printf("----리뷰 목록----\n");
	for (int i = 0; i < restaurantCount; i++) {
		printf("%s : %d \n", review_task[i], starpoints[i]);
	}
	printf("\n");
}
int main() {
	while (1) {
		int choice = 0;
		printf("현재 리뷰한 음식점 수 : %d\n리뷰는 최대 5개 까지 가능합니다.\n", restaurantCount);
		printf("어떤 기능을 사용 하시겠습니까?\n");
		printf("1. 식당 별점 리뷰\n2. 리뷰 목록 보기\n3. 음식점 추천 받기\n4. 종료\n");
		printf("번호를 입력하세요: ");
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
			printf("다시 선택해 주세요.\n");
		}

		if (logout == 1) {
			printf("프로그램을 종료합니다.\n");
			break;
		}
		if (restaurantCount == 5) {
			printf("리뷰 목록이 가득 찼습니다.\n");
		}

	}
	return 0;
}