#include <stdio.h>
#pragma warning (disable : 4996)
#define MAX 100
typedef struct xy {
	int x;
	int y;
}xy;
int check(int x, int y, xy* history, int i, int a, int b);
int main() {
	int i = 1, a, b;
	xy history[MAX];
	history[0].x = 0;
	history[0].y = 0;

	while (1) {
		scanf("%d %d", &a, &b);
		if (a == -1 && b == -1)
			break;

		if (a == 0) { // 방향만큼 이동
			if (check(history[i - 1].x, history[i - 1].y, history, i, a, b)) {
				for (int q = 1; q <= b; q++) {
					history[i].y = history[i - 1].y + 1;
					history[i].x = history[i - 1].x;
					i++;
				}
				printf("%d %d\n", history[i-1].x, history[i-1].y);
			}
			else {
				printf("invalid move!\n");
				continue;
			}
		}
		else if (a == 1) {
			if (check(history[i - 1].x, history[i - 1].y, history, i, a, b)) {
				for (int q = 1; q <= b; q++) {
					history[i].x = history[i - 1].x + 1;
					history[i].y = history[i - 1].y;
					i++;
				}
				printf("%d %d\n", history[i-1].x, history[i-1].y);
			}
			else {
				printf("invalid move!\n");
				continue;
			}
		}
		else if (a == 2) {
			if (check(history[i - 1].x, history[i - 1].y, history, i, a, b)) {
				for (int q = 1; q <= b; q++) {
					history[i].y = history[i - 1].y - 1;
					history[i].x = history[i - 1].x;
					i++;
				}
				printf("%d %d\n", history[i-1].x, history[i-1].y);
			}
			else {
				printf("invalid move!\n");
				continue;
			}
		}
		else if (a == 3) {
			if (check(history[i - 1].x, history[i - 1].y, history, i, a, b)) {
				for (int q = 1; q <= b; q++) {
					history[i].x = history[i - 1].x - 1;
					history[i].y = history[i - 1].y;
					i++;
				}
				printf("%d %d\n", history[i-1].x, history[i-1].y);
			}
			else {
				printf("invalid move!\n");
				continue;
			}
		}


	}
}
int check(int x, int y, xy* history, int i, int a, int b) {

	if (a == 0) {
		for (int q = 1; q <= b; q++) { // 하나씩 늘려가며, 이동해가며
			for (int w = 0; w < i; w++) {
				if (x == history[w].x && y + q == history[w].y)
					return 0;
			}
		}
	}
	else if (a == 1) {
		for (int q = 1; q <= b; q++) { // 하나씩 늘려가며, 이동해가며
			for (int w = 0; w < i; w++) {
				if (x + q == history[w].x && y == history[w].y)
					return 0;
			}
		}
	}
	else if (a == 2) {
		for (int q = 1; q <= b; q++) { // 하나씩 늘려가며, 이동해가며
			for (int w = 0; w < i; w++) {
				if (x == history[w].x && y - q == history[w].y)
					return 0;
			}
		}

	}
	else if (a == 3) {
		for (int q = 1; q <= b; q++) { // 하나씩 늘려가며, 이동해가며
			for (int w = 0; w < i; w++) {
				if (x - q == history[w].x && y == history[w].y)
					return 0;
			}
		}
	}

	return 1;
}