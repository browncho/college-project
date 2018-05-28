#include <stdio.h>
#pragma warning (disable : 4996)
#define MAX 100
int find(int n, int* arr, int endline);
void insert(int n, int* arr, int endline);
int main() {
	int arr[MAX];
	int endline = 0;
	int tmp;
	while (1) {
		scanf("%d", &tmp);
		if (tmp == -1)
			break;

		if (find(tmp, arr, endline) == -1) {
			insert(tmp, arr, endline);
			endline++;
			for (int i = 0; i < endline; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
		}
		else {
			printf("Duplicate error! 해당값은 배열의 %d인덱스에 있습니다.\n", find(tmp, arr, endline));
		}

	}


}
int find(int n, int* arr, int endline) {

	for (int i = 0; i < endline; i++) {
		if (n == arr[i])
			return i;
	}

	return -1;
}
void insert(int n, int* arr, int endline) {

	if (endline == 0) {
		arr[0] = n;
		return;
	}


	for (int i = endline - 1; i >= 0; i--) {
		if (arr[i] < n) {
			arr[i + 1] = n;
			break;
		}
		else {
			arr[i + 1] = arr[i];
			if (i == 0)
				arr[0] = n;

		}

	}

	int* Arr;
}