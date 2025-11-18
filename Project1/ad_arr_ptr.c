#include <stdio.h>
#include <conio.h>

#define ROWS 3
#define COLS 5

void printArr(char arr[ROWS][COLS]) {
	//printf("배열의 상태:\n");
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
}
int main(void) {
	char data[ROWS][COLS] = { 0 };
	char(*p)[COLS];

	p = data;
	printf("시작 전:\n");
	printArr(data);

	(*p)[1] = 3;
	(*(p + 1))[2] = 4;
	(*(p + 2))[4] = 5;

	printf("Press any key to continue...\n");
	getchar();
	printf("초기 배열 상태:\n");
	printArr(data);

	p = data;
	p++;
	(*p)[0] = 7;
	(*p)[4] = 8;
	(*(p-1))[3] = 9;

	printf("Press any key to continue...\n");
	getchar();
	printf("두번 째 배열 상태:\n");
	printArr(data);
	
	char* ptr = &data[0][0];
	*(ptr + 6) = 10;
	*(ptr + 10) = 11;
	*(ptr + 14) = 28;
	//*(ptr + 15) = 100;

	printf("포인터 산술 연산 후 배열 상태:\n");
	printArr(data);
	getchar();
	printf("Press any key to continue...\n");
	
	char temp[COLS];
	for (int i = 0; i < COLS; i++) {
		temp[i] = data[0][i];
		data[0][i] = data[2][i];
		data[2][i] = temp[i];
	}

	printf("첫 번쨰 행과 세 번째 행 교환 후 배열 상태 : \n");
	printArr(data);
	printf("Press any key to continue...\n");
	getchar();

	return 0;
}