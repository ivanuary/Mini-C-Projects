#include <stdio.h>
#include <stdlib.h>

struct player {
	char username[80];
	int user_id;
	int acc_age;
}players[5];

int main() {
	char start;
	printf("This is a simple program to record the information of 5 players in an array\n");
	while(1){
		printf("\nWould you like to start? (Y/N): ");
		scanf(" %c", &start);
		if(start=='Y' || start =='y'){
			for(int i=0;i<5;i++){
				printf("\nENTER USERNAME OF PLAYER #%d: ", i+1);
				scanf(" %s", &players[i].username);
				printf("ENTER USER ID OF PLAYER #%d: ", i+1);
				scanf("%d", &players[i].user_id);
				printf("ENTER ACCOUNT AGE OF PLAYER #%d: ", i+1);
				scanf("%d", &players[i].acc_age);
				printf("\n");
			}
			printf("\nPrinting Player Data...\n");
			for(int j=0;j<5;j++){
				printf("PLAYER #%d:",j+1);
				printf("\n	USERNAME: %s", players[j].username);
				printf("\n	USER ID: %d", players[j].user_id);
				printf("\n	ACCOUNT AGE: %d", players[j].acc_age);
				printf("\n\n");
			}
			break;
		}else if(start=='N' || start =='n'){
			return 0;
		}else{
			printf("INVALID INPUT, TRY AGAIN\n");
		}
	}

	return 0;
}