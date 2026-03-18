#include <stdio.h>
#include <stdlib.h>
struct question{
	char q[80];
	int answer;
	int point;
};

int main() {
	int score, ans = 0;
	struct question questions[5] ={
	{"1+1 = ", 2, 1}, {"2+2 = ", 4, 1}, {"3+3 = ", 6, 1}, {"4+4 = ", 8, 1}, {"5+5 = ", 10, 1}};
	
	printf("SHORT QUIZ OF 5 SIMPLE QUESTIONS:\n");
	for (int i=0; i<5; i++){
		printf("=============\n");
		printf("%s", questions[i].q);
		scanf("%d", &ans);
		if (ans == questions[i].answer){
			score += questions[i].point;
		}
	}
	printf("=============\n");
	printf("Your Score: %d", score);
	return 0;
}