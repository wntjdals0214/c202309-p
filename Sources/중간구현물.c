#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RESTAURANT_NUM 5 // 최대 리뷰가능 음식점 수
#define RESTAURANT_NAME 100

char review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { "" }; // 음식점 이름을 저장하기 위한 2차원 배열
int starpoints[RESTAURANT_NUM]; // 별점을 저장하기 위한 배열
int tastepoints[RESTAURANT_NUM]; // 가중치를 저장하기 위한 함수

int tastePoint = 0; // 취향점수를 저장하기 위한 변수

// 기능 구현을 위한 5명의 다른 이용자 리뷰
char A_review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { {"b"},{"c"},{"d"},{"e"},{"g"} }; // 음식점 이름
int A_starpoints[RESTAURANT_NUM] = { 2,1,4,4,4 }; // 별점
int A_totalTastePoint = 0; // 가중치 저장을 위한 변수

// 밑은 A와 구조가 동일한 다른 4명의 정보들 
char B_review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { {"b"},{"c"},{"d"},{"e"},{"g"} };
int B_starpoints[RESTAURANT_NUM] = { 4,5,4,4,3 };
int B_totalTastePoint = 0;

char C_review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { {"a"},{"b"},{"d"},{"f"},{"g"} };
int C_starpoints[RESTAURANT_NUM] = { 4,3,1,2,4 };
int C_totalTastePoint = 0;

char D_review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { {"a"},{"b"},{"c"},{"h"},{"f"} };
int D_starpoints[RESTAURANT_NUM] = { 3,5,5,4,5 };
int D_totalTastePoint = 0;

char E_review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { {"a"},{"c"},{"d"},{"e"},{"f"} };
int E_starpoints[RESTAURANT_NUM] = { 4,3,4,5,3 };
int E_totalTastePoint = 0;


int restaurantCount = 0; //리뷰 목록에 저장된 음식점의 수

// 1. 식당 별점 리뷰 함수
void addReview(char task[]) {
	if (restaurantCount == 5) { // 리뷰가 꽉 찼을 때
		printf("더 이상의 리뷰는 불가능 합니다.");
		return;
	}
	// 리뷰 작성 하기
	printf("음식점 이름을 입력하세요 (공백 없이 입력하세요): ");
	scanf_s("%s", task, (int)sizeof(task));
	strcpy_s(review_task[restaurantCount], sizeof(review_task[restaurantCount]), task); // 2차원 배열에 복사해 저장

	printf("음식점을 평가해 주세요 (별점 5점 만점): ");
	int starpoint = 0;
	scanf_s("%d", &starpoint);
	starpoints[restaurantCount] = starpoint; // 배열에 저장
	printf("%s에 대한 리뷰가 저장되었습니다. (별점: %d)\n\n", task, starpoint);
}
// 리뷰 목록 보기 함수
void printReview() {
	printf("----리뷰 목록----\n"); // for문을 통해 배열에 저장된 리뷰와 별점을 순서대로 출력
	for (int i = 0; i < restaurantCount; i++) {
		printf("%s : %d \n", review_task[i], starpoints[i]);
	}
	printf("\n");
}
// 같은 취향의 리뷰어를 찾고 가중치를 부여하는 함수
void searchTasteReview() {
	for (int i = 0; i < restaurantCount; i++) { // 사용자의 리뷰에 대한 for 문
		for (int j = 0; j < RESTAURANT_NUM; j++) { // 다른 5명의 이용자에 대한 for 문 
			if (strcmp(review_task[i], A_review_task[j]) == 0) { // 사용자와 A의 리뷰한 음식점의 이름이 같을시 실행
				tastePoint = 5 - abs(starpoints[i] - A_starpoints[j]); // 두 별점차가 적을수록 더 높은 취향점수를 부여
				A_totalTastePoint += tastePoint; // A의 최종 취향점수에 추가
				tastePoint = 0; // 취향점수를 초기화 시켜 다른 이용자의 취향점수를 구할 때 중복되지 않도록 함
			}
			// 밑은 구조가 동일한 다른 4명에 대한 if 문
			if (strcmp(review_task[i], B_review_task[j]) == 0) {
				tastePoint = 5 - abs(starpoints[i] - B_starpoints[j]);
				B_totalTastePoint += tastePoint;
				tastePoint = 0;
			}
			if (strcmp(review_task[i], C_review_task[j]) == 0) {
				tastePoint = 5 - abs(starpoints[i] - C_starpoints[j]);
				C_totalTastePoint += tastePoint;
				tastePoint = 0;
			}
			if (strcmp(review_task[i], D_review_task[j]) == 0) {
				tastePoint = 5 - abs(starpoints[i] - D_starpoints[j]);
				D_totalTastePoint += tastePoint;
				tastePoint = 0;
			}
			if (strcmp(review_task[i], E_review_task[j]) == 0) {
				tastePoint = 5 - abs(starpoints[i] - E_starpoints[j]);
				E_totalTastePoint += tastePoint;
				tastePoint = 0;
			}
		}

	}
}
int main() {
	while (1) {
		int choice = 0;
		printf("현재 리뷰한 음식점 수 : %d\n리뷰는 최대 5개 까지 가능합니다.\n", restaurantCount);
		printf("어떤 기능을 사용 하시겠습니까?\n");
		printf("1. 식당 별점 리뷰\n2. 리뷰 목록 보기\n3. 음식점 추천 받기\n4. 종료\n");
		printf("번호를 입력하세요: ");
		scanf_s("%d", &choice);


		int logout = 0; // 프로그램 종료를 위한 변수

		switch (choice) {
		case 1:
			addReview(review_task[restaurantCount]);
			restaurantCount++;
			break;
		case 2:
			printReview();
			break;
		case 3:
			searchTasteReview();
			// 5명의 취향점수 출력
			printf("%d\n", A_totalTastePoint);
			printf("%d\n", B_totalTastePoint);
			printf("%d\n", C_totalTastePoint);
			printf("%d\n", D_totalTastePoint);
			printf("%d\n", E_totalTastePoint);
			break;
		case 4:
			logout = 1;
			break;
		default:
			printf("다시 선택해 주세요.\n");
		}

		if (logout == 1) { // 종료변수가 1 일시 프로그램 종료
			printf("프로그램을 종료합니다.\n");
			break;
		}
		if (restaurantCount == 5) { // 리뷰가 5개 꽉 찼을시 경고
			printf("리뷰 목록이 가득 찼습니다.\n");
		}

	}
	return 0;
}