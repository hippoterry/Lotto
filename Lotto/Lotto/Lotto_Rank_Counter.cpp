#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 10000000
#define WIN1 6
#define WIN2 11
#define WIN3 15
#define WIN4 24
#define WIN5 32
#define WIN6 39
#define BOUNS 28
// 996회 로또 번호

void main() {
	int Rank[5] = { 0,0,0,0,0 }; // 등수 카운트 변수
	srand(time(NULL));
	printf("Simulating...\n\n");
	for (long long int a = 1; a <= COUNT; a++)
	{
		int i = 0, n = 0;
		char k = 0, m = 0;
		char lotto[6] = { 0, };
		// 로또 자동 추첨기
		while (1)
		{
			char r = rand() % 45 + 1;
			for (i = 0; i < n; i++)
				if (lotto[i] == r) break;

			if (n == i) lotto[n++] = r;
			if (n >= 6) break;
		}
		// 로또 번호 비교
		for (char j = 0; j <= 5; j++)
		{
			if (lotto[j] == WIN1 || lotto[j] == WIN2 || lotto[j] == WIN3
				|| lotto[j] == WIN4 || lotto[j] == WIN5 || lotto[j] == WIN6) k++;
			if (lotto[j] == BOUNS) m++;
		}
		// 등수 카운트
		switch (k)
		{
		case 6: Rank[0]++; break;
		case 5: if (m == 1) Rank[1]++;
			  else Rank[2]++;
			break;
		case 4: Rank[3]++; break;
		case 3: Rank[4]++; break;
		}
	}
	for (int b = 0; b <= 4; b++) printf("%d 등 : %d\n", b + 1, Rank[b]);
}