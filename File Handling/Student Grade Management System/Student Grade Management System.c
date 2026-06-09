#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Grade{
	char subject[20];
	float score;
};

struct Student{
	char studentID[20];
	char name[20];
	struct Grade grade;
};

void displayStudents(struct Student s[], int n){
	printf("\n\nALL STUDENT RECORDS:\n");
	for(int i=0; i<n;i++){
		printf("\n\nSTUDENT #%d:\n", i+1);
		printf("STUDENT ID: %s\n", s[i].studentID);
		printf("NAME: %s\n", s[i].name);
		printf("STUDENT NAME LENGTH: %d\n", strlen(s[i].name));
		printf("SUBJECT: %s\n", s[i].grade.subject);
		printf("SCORE: %.2f\n", s[i].grade.score);
	}
	return;
}

void updateScore(float *score, float newScore){
	*score = newScore;
	return;
}

int topStudent(struct Student s[], int n){
	int index = 0;
	for(int i=0; i<n; i++){
		if(s[i].grade.score > s[index].grade.score){
			index = i;
		}
	}
	return index;
}

void StructTotxt(struct Student s[], int n){
	FILE *file = fopen("students.txt", "w");
	for(int i=0; i<n; i++){
		fprintf(file, "%s,%s,%s,%f\n", s[i].studentID, s[i].name, s[i].grade.subject, s[i].grade.score);
	}
	fclose(file);
}

int txtToStruct(struct Student s[], int n){
	FILE *file = fopen("students.txt", "r");
	if(file == NULL){
		printf("\nNO RECORDS YET!, PLEASE INPUT RECORDS FIRST.\n");
		fclose(file);
		return -1;
	}
	
	file = fopen("students.txt", "r");
	for(int i=0; i<n; i++){
		fscanf(file, "%[^,],%[^,],%[^,],%f\n", s[i].studentID, s[i].name, s[i].grade.subject, &s[i].grade.score);
	}
	fclose(file);
	
	return 0;
}

int main() {
	struct Student students[3];
	char topName[50];
	
	while(1){
		printf("===STUDENT GRADE MANAGEMENT SYSTEM===\n");
		printf("[1]WRITE RECORDS\n");
		printf("[2]VIEW RECORDS\n");
		printf("[3]EDIT RECORD\n");
		printf("[4]VIEW TOP STUDENT\n");
		printf("[5]SEARCH STUDENT\n");
		printf("[6]EXIT\n");
		
		int menu_choice;
		printf("INPUT: ");
		scanf("%d", &menu_choice);
		
		if(menu_choice == 1){
			printf("\nWRITE RECORDS:\n");
			for(int i=0; i<3; i++){
				printf("\n\nSTUDENT #%d:\n", i+1);
				printf("ENTER STUDENT ID: ");
				scanf(" %s", students[i].studentID);
				printf("ENTER NAME: ");
				scanf(" %s", students[i].name);
				printf("ENTER SUBJECT: ");
				scanf(" %s", students[i].grade.subject);
				printf("ENTER SCORE: ");
				scanf("%f", &students[i].grade.score);
			}
			
			StructTotxt(students, 3);
		}else if(menu_choice == 2){
			int check = txtToStruct(students, 3);
			if(check != -1){
				displayStudents(students, 3);
			}
		}else if(menu_choice == 3){
			int check = txtToStruct(students, 3);
			if(check != -1){
				printf("\nSTUDENTS:\n");
				for(int i=0; i<3; i++){
					printf("\nSTUDENT #%d:\n", i+1);
					printf("STUDENT ID: %s\n", students[i].studentID);
					printf("STUDENT NAME: %s\n", students[i].name);
				}
				int stud_choice;
				while(1){
					printf("\nENTER STUDENT # TO EDIT: ");
					scanf("%d", &stud_choice);
					
					if(stud_choice > 3 || stud_choice < 1){
						printf("\nINVALID INPUT, TRY AGAIN!\n");
					}else{
						break;
					}
				}
				
				printf("ENTER NEW SCORE: ");
				float newScore;
				scanf("%f", &newScore);
				
				updateScore(&students[stud_choice-1].grade.score, newScore);
				StructTotxt(students, 3);
			}
		}else if(menu_choice == 4){
			int check = txtToStruct(students, 3);
			if(check != -1){
				int tp_index = topStudent(students, 3);
				strcpy(topName, students[tp_index].name);
				printf("\nTOP STUDENT\n");
				printf("NAME: %s\n", topName);
			}
		}else if(menu_choice == 5){
			int check = txtToStruct(students, 3);
			if(check != -1){
				char search_id[20];
				printf("ENTER STUDENT ID: ");
				scanf(" %s", search_id);
				
				int id_search = 0;
				for(int i=0; i<3; i++){
					if(strcmp(search_id, students[i].studentID)==0){
						printf("\n\nSTUDENT DATA:\n");
						printf("STUDENT ID: %s\n", students[i].studentID);
						printf("NAME: %s\n", students[i].name);
						printf("STUDENT NAME LENGTH: %d\n", strlen(students[i].name));
						printf("SUBJECT: %s\n", students[i].grade.subject);
						printf("SCORE: %.2f\n", students[i].grade.score);
						
						id_search = 1;
						break;
					}
				}
		
				if(id_search == 0){
					printf("\nSTUDENT NOT FOUND!\n");
				}
			}
		}else if(menu_choice == 6){
			return 0;
		}else{
			printf("\nINVALID INPUT, TRY AGAIN\n");
		}
		printf("\n\n");
	}
	return 0;
}