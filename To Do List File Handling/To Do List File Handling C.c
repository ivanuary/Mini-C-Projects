#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"


struct Task{
	char title[80];
	char type[20];
	int status;
}tasks[99];

void StructTotxt(struct Task tasks[99], int count){
	int i;
	
	FILE *file = fopen("tasks.txt", "w");
	for(i=0;i<count;i++){
		if(tasks[i].status==0){
			fprintf(file, "%s,%s,%d\n", tasks[i].title,tasks[i].type,tasks[i].status);
		}
	}
	fclose(file);
	
	file = fopen("tasks.txt", "a");
	for(i=0;i<count;i++){
		if(tasks[i].status==1){
			fprintf(file, "%s,%s,%d\n", tasks[i].title,tasks[i].type,tasks[i].status);
		}
	}
	fclose(file);
	
	file = fopen("tasks.txt", "a");
	for(i=0;i<count;i++){
		if(tasks[i].status==2){
			fprintf(file, "%s,%s,%d\n", tasks[i].title,tasks[i].type,tasks[i].status);
		}
	}
	fclose(file);
}

void txtToStruct(struct Task tasks[99]){
	int count = 0;
	FILE *file = fopen("tasks.txt", "r");
	while(fscanf(file,"%[^,],%[^,],%d\n", tasks[count].title, tasks[count].type, &tasks[count].status) == 3){
		count++;
	}
	fclose(file);
}

int TaskCounter(){
	char title[80]; char type[20]; int status; int count = 0;
	FILE *file = fopen("tasks.txt", "r");
	while(fscanf(file,"%[^,],%[^,],%d\n", title, type, &status) == 3){
		count++;
	}
	fclose(file);
	
	return count;
}

void ViewTasks(){
	char title[80]; char type[20]; int status; int task_counter = 1;
	FILE *file = fopen("tasks.txt", "r");
	
	int count = TaskCounter();
	if(count == 0){
		printf("\nNO TASKS ADDED YET!");
		return;
	}
	fclose(file);

	printf("\n\n");
	
	
	//Prints by Status
	file = fopen("tasks.txt", "r");
	printf("CURRENT TASKS:\n");
	printf( "|---|-----------------|-----------------|-----------------|\n" );
	printf( "| # | TITLE           | TYPE            | STATUS          |\n" );
	printf( "|---|-----------------|-----------------|-----------------|\n" );
	while(fscanf(file,"%[^,],%[^,],%d\n",title,type, &status) == 3){
		if(status == 0){
			printf(RED "| %d | %-15s | %-15s | PENDING         |\n" RESET,task_counter,title, type);
			task_counter++;
		}
	}
	fclose(file);
	
	file = fopen("tasks.txt", "r");
	while(fscanf(file,"%[^,],%[^,],%d\n",title,type, &status) == 3){
		if(status == 1){
			printf(YELLOW "| %d | %-15s | %-15s | IN PROGRESS     |\n" RESET,task_counter,title, type);
			task_counter++;
		}
	}
	fclose(file);
	
	file = fopen("tasks.txt", "r");
	while(fscanf(file,"%[^,],%[^,],%d\n",title,type, &status) == 3){
		if(status == 2){
			printf(GREEN "| %d | %-15s | %-15s | DONE            |\n" RESET,task_counter,title, type);
			task_counter++;
		}
	}
	fclose(file);
	printf( "|---|-----------------|-----------------|-----------------|" );
	
	return;
}

int main() {
	//Creates the file if it doesn't exist yet in the folder
	FILE *file = fopen("tasks.txt", "r");
	if(file==NULL){
		file = fopen("tasks.txt", "w");
		fprintf(file, "");
		fclose(file);
	}else{
		fclose(file);
	}
	
	//Main Menu
	while(1){
		printf("======================\n");
		printf("TO DO LIST CONSOLE APP\n");
		printf("======================\n");
		printf("What would you like to do?\n");
		printf("[1] View All Tasks\n");
		printf("[2] Add a Task\n");
		printf("[3] Edit Task Status\n");
		printf("[4] Delete a Task\n");
		printf("[5] Exit App\n");
		
	
		int menu_loop = 1;
		while(menu_loop){
			printf("Enter Number of Choice: ");
			int menu_choice = 0;
			scanf("%d", &menu_choice);
			
			char task_title[80]; char str_type[20]; char exit_choice;
			int num_type; int task_edit; int status_num; int count; int task_del;
			
			switch(menu_choice){
				case 1: //View
					ViewTasks();
					menu_loop = 0;
					break;
				case 2: //Add
					printf("ENTER TASK NAME: ");
					scanf(" %[^\n]", task_title);
					
					while(1){
						printf("\nENTER TASK TYPE:\n");
						printf("[1] CHORES\n");
						printf("[2] HOMEWORK\n");
						printf("[3] TRAVEL\n");
						printf("[4] HOBBIES\n");
						printf("[5] RANDOM\n");
						printf("ENTER TYPE: ");
						scanf("%d", &num_type);
						
						if(num_type==1){
							strcpy(str_type,"CHORES");
							break;
						}else if(num_type==2){
							strcpy(str_type,"HOMEWORK");
							break;
						}else if(num_type==3){
							strcpy(str_type,"TRAVEL");
							break;
						}else if(num_type==4){
							strcpy(str_type,"HOBBIES");
							break;
						}else if(num_type==5){
							strcpy(str_type,"RANDOM");
							break;
						}else{
							printf("\nINVALID INPUT, TRY AGAIN\n");
						}
					}
					
					file = fopen("tasks.txt", "a");
					fprintf(file, "%s,%s,0\n", task_title, str_type);
					fclose(file);
					
					printf("TASK ADDED!");
					
					txtToStruct(tasks);
					count = TaskCounter();
					StructTotxt(tasks, count);
					
					menu_loop = 0;
					break;
					
				case 3: //Edit
					ViewTasks();
					txtToStruct(tasks);
					
					count = TaskCounter();
					while(1){
						printf("\nENTER TASK TO EDIT STATUS: ");
						scanf("%d", &task_edit);	
						if(task_edit > count || task_edit < 1){
							printf("\nINVALID INPUT, TRY AGAIN\n");
						}else{
							break;
						}
					}
					
					while(1){
						printf("\nPICK NEW STATUS:\n");
						printf("[1] PENDING\n");
						printf("[2] IN PROGRESS\n");
						printf("[3] DONE\n");
						printf("INPUT: ");
						scanf("%d", &status_num);
						
						if(status_num < 1 || status_num > 3){
							printf("\nINVALID INPUT, TRY AGAIN\n");
						}else{
							status_num--;
							break;
						}
					}
					
					tasks[task_edit-1].status = status_num;
					
					StructTotxt(tasks, count);
					printf("\nTASK HAS BEEN EDITED!");
					menu_loop = 0;
					break;
				case 4: //Delete
					ViewTasks();
					txtToStruct(tasks);
					count = TaskCounter();
					
					while(1){
						printf("\nENTER TASK DELETE: ");
						scanf("%d", &task_del);	
						if(task_del > count || task_del < 1){
							printf("\nINVALID INPUT, TRY AGAIN\n");
						}else{
							break;
						}
					}
					
					for(int i=0; i<count; i++){
						if(i == task_del-1){
							for(int j=i; j<count-1; j++){
								tasks[j].status = tasks[j+1].status;
								strcpy(tasks[j].title, tasks[j+1].title);
								strcpy(tasks[j].type, tasks[j+1].type);
							}
						}
					}
					count--;
					StructTotxt(tasks, count);
					printf("\nTASK HAS BEEN DELETED!");
					menu_loop = 0;
					break;
				case 5: //Exit
					while(1){
						printf("\nDO YOU REALLY WANT TO EXIT?(Y/N): ");
						scanf(" %c", &exit_choice);
						if(exit_choice == 'Y' || exit_choice == 'y'){
							return 0;
						}else if(exit_choice == 'N' || exit_choice == 'n'){
							break;
						}else{
							printf("\nINVALID INPUT, TRY AGAIN\n");
						}
					}

					menu_loop = 0;
					break;
				default:
					printf("\nINVALID INPUT, TRY AGAIN\n");
			}
		}
		printf("\n\nPRESS ENTER TO CONTINUE: ");
		getchar();
		getchar();
		system("cls");
	}
	return 0;
}