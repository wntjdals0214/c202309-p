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

// 이용자의 리뷰와 별점을 저장할 구조체
struct ReviewInfo {
	char* name;
	int starpoint;
};

char review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { "" }; // 음식점 이름을 저장하기 위한 2차원 배열
int starpoints[RESTAURANT_NUM]; // 별점을 저장하기 위한 배열
int tastepoints[RESTAURANT_NUM]; // 가중치를 저장하기 위한 함수

int tastePoint = 0; // 취향점수를 저장하기 위한 변수
int sameReview = 0; // 리뷰가 같은지 다른지를 판단하기 위한 변수
int k = 0;

// 기능 구현을 위한 5명의 다른 이용자 리뷰
char A_review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { {"b"},{"c"},{"d"},{"e"},{"g"} }; // 음식점 이름
int A_starpoints[RESTAURANT_NUM] = { 2,1,4,4,4 }; // 별점
int A_totalTastePoint = 0; // 가중치 저장을 위한 변수
float A_newStarPoint; // 가중치를 적용하여 재계산한 별점
char A_newRecommend[RESTAURANT_NUM][RESTAURANT_NAME] = { "" }; // A의 새로운 음식점 추천 이름을 저장할 배열
float A_newStarPoints[RESTAURANT_NUM]; // A의 새로운 음식점 추천 별점을 저장할 배열

// 밑은 A와 구조가 동일한 다른 4명의 정보들 
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


// 1. 식당 별점 리뷰 함수
void addReview(char task[], int* restaurantCount, int* starpoints, char(*review_task)[RESTAURANT_NAME], struct ReviewInfo* review, int i) {
	if (*restaurantCount == 5) { // 리뷰가 꽉 찼을 때
		printf("더 이상의 리뷰는 불가능 합니다.");
		return;
	}
	// 리뷰 작성 하기
	printf("음식점 이름을 입력하세요 (공백 없이 입력하세요): ");
	scanf_s("%s", task, (int)sizeof(task));
	strcpy_s(review_task[*restaurantCount], sizeof(review_task[*restaurantCount]), task); // 2차원 배열에 복사해 저장
	// 구조체에 저장하기 위해 한번 더 입력
	printf("한번 더 입력해주세요: ");
	char temp[100];
	scanf_s("%s", temp, (int)sizeof(temp));
	review->name = (char*)malloc((strlen(temp) + 1) * sizeof(char));
	strcpy_s(review->name, strlen(temp) + 1, temp);

	printf("음식점을 평가해 주세요 (별점 5점 만점): ");
	int starpoint = 0;
	scanf_s("%d", &starpoint);
	starpoints[*restaurantCount] = starpoint; // 배열에 저장
	// 구조체에 저장하기 위해 한번 더 입력
	printf("한번 더 입력해주세요: ");
	scanf_s("%d", &review->starpoint);
	printf("%s에 대한 리뷰가 저장되었습니다. (별점: %d)\n\n", task, starpoint);

}


int main() {

	char review_task[RESTAURANT_NUM][RESTAURANT_NAME] = { "" }; // 음식점 이름을 저장하기 위한 2차원 배열
	int starpoints[RESTAURANT_NUM]; // 별점을 저장하기 위한 배열
	int restaurantCount = 0; //리뷰 목록에 저장된 음식점의 수

	while (1) {
		int choice = 0;
		printf("현재 리뷰한 음식점 수 : %d\n리뷰는 최대 5개 까지 가능합니다.\n", restaurantCount);
		printf("어떤 기능을 사용 하시겠습니까?\n");
		printf("1. 식당 별점 리뷰\n2. 리뷰 목록 보기\n3. 음식점 추천 받기\n4. 종료\n");
		printf("번호를 입력하세요: ");
		scanf_s("%d", &choice);


		int logout = 0; // 프로그램 종료를 위한 변수

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