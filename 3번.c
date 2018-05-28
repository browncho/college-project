#include <stdio.h>
#pragma warning (disable : 4996)
#define MAX 100

typedef struct gyo {
	int x;
	int y;
}gyo;
typedef struct Su{
	int gojeong;
	int s;
	int e;
}Su;

int intersect(Su* supyung, Su* suzik, int i, int j);
int main() {
	Su supyung[MAX];
	Su suzik[MAX];
	gyo gyocha[MAX];
	int i=0, j=0, k=0;
	int x1, y1, x2, y2, N, tmp;
	FILE *fs = fopen("input3.txt", "r");

	fscanf(fs, "%d", &N);
	for(int q=1; q<=N; q++) {
		fscanf(fs, "%d", &x1);
		fscanf(fs, "%d", &y1);
		fscanf(fs, "%d", &x2);
		fscanf(fs, "%d", &y2);

		if (y1 == y2) { // 수평 성분
			supyung[i].gojeong = y1;
			if (x1 < x2) {
				supyung[i].s = x1;
				supyung[i].e = x2;
			}
			else {
				supyung[i].s = x2;
				supyung[i].e = x1;
			}
			i++;
			
		}
		else if (x1 == x2) { // 수직 성분
			suzik[j].gojeong = x1;
			if (y1 < y2) {
				suzik[j].s = y1;
				suzik[j].e = y2;
			}
			else {
				suzik[j].s = y2;
				suzik[j].e = y1;
			}
			j++;
			
		}

	}


	for (int q = 0; q < i; q++) { // 교차하는지 검사해서 배열에 넣어주기
		for (int w = 0; w < j; w++) {
			if (intersect(supyung, suzik, q, w) == 1) {
				gyocha[k].x = suzik[w].gojeong;
				gyocha[k].y = supyung[q].gojeong;
				k++;
			}

		}
	}

	for (int a = 1; a <= k; a++) {
		for (int u = 0; u < k-1; u++) { // 순서대로 정렬
			if (gyocha[u].x > gyocha[u + 1].x) {
				tmp = gyocha[u].x;
				gyocha[u].x = gyocha[u + 1].x;
				gyocha[u + 1].x = tmp;
				tmp = gyocha[u].y;
				gyocha[u].y = gyocha[u + 1].y;
				gyocha[u + 1].y = tmp;
			}
		}
	}


	
	for (int h = 0; h < k; h++) {
		printf("[%d, %d]\n", gyocha[h].x, gyocha[h].y);
			
	}
		
}
int intersect(Su* supyung, Su* suzik, int i, int j) {

	if (supyung[i].s <= suzik[j].gojeong && suzik[j].gojeong <= supyung[i].e) {
		if (suzik[j].s <= supyung[i].gojeong && supyung[i].gojeong <= suzik[j].e)
			return 1;
	}

	return 0;

}