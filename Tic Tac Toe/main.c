#include <stdio.h>
#include <stdlib.h>

int main() {
	int state, win, xturn, oturn, xwin, owin, turns;
	char one, two, three, four, five, six, seven, eight, nine;
	do{
		//Resetting Char Variables
		one =' '; two =' '; three =' '; four =' '; five =' '; six =' '; seven =' '; eight =' '; nine =' ';
		//Resets Turn Count
		turns = 0;
		//Resets Win Count
		xwin = 0; owin = 0;
		
		printf("------------------------------------\n");
		printf("Welcome to Tic Tac Toe!\n");
		printf("+---+---+---+\n");
		printf("| 1 | 2 | 3 |\n");
		printf("+---+---+---+\n");
		printf("| 4 | 5 | 6 |\n");
		printf("+---+---+---+\n");
		printf("| 7 | 8 | 9 |\n");
		printf("+---+---+---+\n");
		printf("\nPlease Choose a Box to Start!\n");
		
		//Start of the Tic Tac Toe Loop
		do{
			//X's Turn
			do{
			printf("\n\nIt's X's TURN: ");
			scanf("%d", &xturn);
			switch(xturn){
				case 1: one = 'X'; break;
				case 2: two = 'X'; break;
				case 3: three = 'X'; break;
				case 4: four = 'X'; break;
				case 5: five = 'X'; break;
				case 6:	six ='X'; break;
				case 7: seven = 'X'; break;
				case 8: eight = 'X'; break;
				case 9: nine = 'X'; break; }
			} while (xturn>9||xturn<1);
	
			//Print's the chosen box for X
			printf("\n+---+---+---+");
			printf("\n| %c | %c | %c |", one, two, three);
			printf("\n+---+---+---+");
			printf("\n| %c | %c | %c |", four, five, six);
			printf("\n+---+---+---+");
			printf("\n| %c | %c | %c |", seven, eight, nine);
			printf("\n+---+---+---+");
		
			//Adds an increment to the amount of turns
			turns++;
		
			//Checks the WIN or END conditions after X's turn
			if(one=='X'&&two=='X'&&three=='X'){ xwin = 1; break;
			} else if (four=='X'&&five=='X'&&six=='X') { xwin = 1; break;
			} else if (seven=='X'&&eight=='X'&&nine=='X'){ xwin = 1; break;
			} else if (one=='X'&&four=='X'&&seven=='X'){ xwin = 1; break;
			} else if (two=='X'&&five=='X'&&eight=='X'){ xwin = 1; break;
			} else if (three=='X'&&six=='X'&&nine=='X'){ xwin = 1; break;
			} else if (one=='X'&&five=='X'&&nine=='X'){ xwin = 1; break;
			} else if (three=='X'&&five=='X'&&seven=='X'){ xwin = 1; break;
			} else if (one=='O'&&two=='O'&&three=='O'){ owin = 1; break;
			} else if (four=='O'&&five=='O'&&six=='O') { owin = 1; break;
			} else if (seven=='O'&&eight=='O'&&nine=='O'){ owin = 1; break;
			} else if (one=='O'&&four=='O'&&seven=='O'){ owin = 1; break;
			} else if (two=='O'&&five=='O'&&eight=='O'){ owin = 1; break;
			} else if (three=='O'&&six=='O'&&nine=='O'){ owin = 1; break;
			} else if (one=='O'&&five=='O'&&nine=='O'){ owin = 1; break;
			} else if (three=='O'&&five=='O'&&seven=='O'){ owin = 1; break;
			} else if (turns==9){ break;
			} else { win = 0; }
		
			//O's Turn
			do{
			printf("\n\nIt's O's TURN: ");
			scanf("%d", &oturn);
			switch(oturn){
				case 1: one = 'O'; break;
				case 2: two = 'O'; break;
				case 3: three = 'O'; break;
				case 4: four = 'O'; break;
				case 5: five = 'O'; break;
				case 6:	six ='O'; break;
				case 7: seven = 'O'; break;
				case 8: eight = 'O'; break;
				case 9: nine = 'O'; break;}
			} while (oturn>9||oturn<1);
			
			//Print's the chosen box for O
			printf("\n+---+---+---+");
			printf("\n| %c | %c | %c |", one, two, three);
			printf("\n+---+---+---+");
			printf("\n| %c | %c | %c |", four, five, six);
			printf("\n+---+---+---+");
			printf("\n| %c | %c | %c |", seven, eight, nine);
			printf("\n+---+---+---+");
		
			//Adds and increment to the amount of turns
			turns++;
			
			//Checks the WIN or END conditions after O's turn
			if(one=='X'&&two=='X'&&three=='X'){ win = 1; xwin = 1;
			} else if (four=='X'&&five=='X'&&six=='X') { win = 1; xwin = 1;
			} else if (seven=='X'&&eight=='X'&&nine=='X'){ win = 1; xwin = 1;
			} else if (one=='X'&&four=='X'&&seven=='X'){ win = 1; xwin = 1;
			} else if (two=='X'&&five=='X'&&eight=='X'){ win = 1; xwin = 1;
			} else if (three=='X'&&six=='X'&&nine=='X'){ win = 1; xwin = 1;
			} else if (one=='X'&&five=='X'&&nine=='X'){ win = 1; xwin = 1;
			} else if (three=='X'&&five=='X'&&seven=='X'){ win = 1; xwin = 1;
			} else if (one=='O'&&two=='O'&&three=='O'){ win = 1; owin = 1;
			} else if (four=='O'&&five=='O'&&six=='O') { win = 1; owin = 1;
			} else if (seven=='O'&&eight=='O'&&nine=='O'){ win = 1; owin = 1;
			} else if (one=='O'&&four=='O'&&seven=='O'){ win = 1; owin = 1;
			} else if (two=='O'&&five=='O'&&eight=='O'){ win = 1; owin = 1;
			} else if (three=='O'&&six=='O'&&nine=='O'){ win = 1; owin = 1;
			} else if (one=='O'&&five=='O'&&nine=='O'){ win = 1; owin = 1;
			} else if (three=='O'&&five=='O'&&seven=='O'){ win = 1; owin = 1;
			} else if (turns==9){ break;
			} else { win = 0; }
		
			/* The program will loop while a WIN condition hasn't been reached,
			or if the game hasn't reached 9 turns*/
		
		} while (win==0);
		
		//Announcement statements for WINS or MAX turns
		if (xwin==1) {
			printf("\n\nCongratulations! X Won!");
		} else if (owin==1) {
			printf("\n\nCongratulations! O Won!"); 
		} else if (turns==9) {
			printf("\n\nYou have reached the maximum amount of turns!");
		}
		
		//Loop restart or program exit
		printf("\n\nEnter 0 to EXIT, and 1 to Try Again \n(If anything else is entered, the program will exit): ");
		scanf("%d", &state);
		
	} while (state==1);
	return 0;
}