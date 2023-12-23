#define RESTAURANT_NUM 5 // 최대 리뷰가능 음식점 수
#define RESTAURANT_NAME 100
void DnewStarPoint(int* restaurantCount, char(*review_task)[RESTAURANT_NAME], char(*D_review_task)[RESTAURANT_NAME], char(*D_newRecommend)[RESTAURANT_NAME], float* D_newStarPoint, int* D_starpoints, int* D_totalTastePoint, int* k, int* sameReview);