#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product{
	char prod_code[11];
	char prod_description[26];
	int avail_qty;
}products[99];

int menu_verify_choice(char character);

void txt_to_array(struct Product products[99], int *count);

int main() {
	while(1){
		char menu_choice;
		while(1){
			printf("PRODUCT INVENTORY APP\n");
			printf("=====================\n");
			printf("[A]dd\n");
			printf("[E]dit\n");
			printf("[D]elete\n");
			printf("[V]iew\n");
			printf("E[X]it\n");
			printf("Please Select: ");
			
			scanf(" %c", &menu_choice);
			
			int menu_verify = menu_verify_choice(menu_choice);
	
			if(menu_verify==1){
				break;
			}else{
				printf("\nINCORRECT INPUT! TRY AGAIN\n\n\n");
			}
		}
		printf("\n");
		
		if(menu_choice == 'A' || menu_choice == 'a'){
			printf("\n===ADD===\n\n");
			FILE *file = fopen("C:\\1 Coding Projects\\Github Repositories\\C Repositories\\C Mini Projects For Github\\File Hadling To Do List\\product.txt", "a");
			
			if(file == NULL){
				printf("UNABLE TO READ FILE");
				return 0;
			}
			
			char prod_code[15], prod_desc[30];
			int avail_qty;
			
			while(1){
				printf("\nINPUT PRODUCT CODE (6 DIGITS MIN/MAX):\n");
				printf("prod");
				scanf(" %s", &prod_code);
				
				if(strlen(prod_code) > 6){
					printf("\nCODE IS TOO LONG!\n");
				}else if(strlen(prod_code) < 6){
					printf("\nCODE IS TOO SHORT!\n");
				}else{
					printf("\nCode Added Successfully!\n");
					break;
				}
			}
			
			while(1){
				printf("\nINPUT PRODUCT DESCRIPTION (25 CHARACTERS MAX, ONE WORD):\n");
				scanf(" %s", &prod_desc);
				
				if(strlen(prod_desc) > 25){
					printf("\nDESCRIPTION IS TOO LONG!\n");
				}else{
					printf("\nDescription Added Successfully!");
					break;
				}
			}
			
			while(1){
				printf("\nINPUT AVAILABLE QUANTITY IN NUMBERS:\n");
				scanf("%d", &avail_qty);
				
				printf("\nQuantity Added Successfully!");
				break;
			}
			
			fprintf(file, "prod%s,%s,%d\n", prod_code, prod_desc, avail_qty);
			fclose(file);
		}else if(menu_choice == 'E' || menu_choice == 'e'){
			printf("\n===EDIT===\n\n");
			int count;
			txt_to_array(products, &count);
			
			printf("ENTER PRODUCT CODE TO EDIT: ");
			char code_search[15];
			scanf(" %s", &code_search);
			
			int transac_verify=0;
			for(int i=0; i<count; i++){
				if(strcmp(code_search, products[i].prod_code) == 0){
					printf("Product Name: %s\n", products[i].prod_description);
					printf("Available Quantity: %d\n", products[i].avail_qty);
					
					printf("\nType of Transaction (PURCHASE/SOLD): ");
					char purchase_type[99];
					scanf(" %s", &purchase_type);
					if(strcmp(purchase_type, "PURCHASE") == 0 || strcmp(purchase_type, "purchase") == 0){
						int purchase_amount;
						printf("ENTER PURCHASE AMOUNT: ");
						scanf("%d", &purchase_amount);
						products[i].avail_qty = products[i].avail_qty + purchase_amount;
						printf("\nPRODUCT AMOUNT HAS BEEN MODIFIED!\n");
					}else if(strcmp(purchase_type, "SOLD") == 0 || strcmp(purchase_type, "sold") == 0){
						int sold_amount;
						printf("ENTER SOLD AMOUNT: ");
						scanf("%d", &sold_amount);
						products[i].avail_qty = products[i].avail_qty - sold_amount;
						printf("\nPRODUCT AMOUNT HAS BEEN MODIFIED!\n");	
					}else{
						printf("\nINVALID TRANSACTION TYPE\n");
					}
					transac_verify = 0;
					break;
				}else{
					transac_verify = 1;
				}
			}
			
			if(transac_verify == 1){
				printf("\nCODE NOT FOUND\n");
			}else{
				FILE *file = fopen("C:\\1 Coding Projects\\Github Repositories\\C Repositories\\C Mini Projects For Github\\File Hadling To Do List\\product.txt", "w");
				
				if(file == NULL){
					printf("UNABLE TO READ FILE");
					return 0;
				}
				
				for(int i=0; i<count; i++){
					fprintf(file, "%s,%s,%d\n",products[i].prod_code, products[i].prod_description, products[i].avail_qty);
				}
				fclose(file);
			}
		}else if(menu_choice == 'D' || menu_choice == 'd'){
			printf("\n===DELETE===\n\n"); 
			int count;
			txt_to_array(products, &count);
			
			printf("ENTER PRODUCT CODE TO DELETE: ");
			char code_search[15];
			scanf(" %s", &code_search);
			
			int init_search=0;
			for(int z=0; z<count; z++){
				if(strcmp(code_search, products[z].prod_code) == 0){
					init_search=1;
					break;
				}else{
					init_search=0;
				}
			}
			
			if(init_search==0){
				printf("\nCODE DOES NOT EXIST\n");
				continue;
			}
			printf("Are You Sure You Want to Delete?(Y/N): ");
			char del_choice;
			scanf(" %c", &del_choice);
			
			if(del_choice == 'Y' || del_choice == 'y'){
				int del_verify=0;
				for(int i=0; i<count; i++){
					if(strcmp(code_search, products[i].prod_code) == 0){
						for(int j=i; j<count-1; j++){
							strcpy(products[j].prod_code, products[j+1].prod_code);
							strcpy(products[j].prod_description, products[j+1].prod_description);
							products[j].avail_qty = products[j+1].avail_qty;
						}
						count--;
						del_verify = 0;
						break;
					}else{
						del_verify = 1;
					}
				}
				
				if(del_verify == 0){
					FILE *file = fopen("C:\\1 Coding Projects\\Github Repositories\\C Repositories\\C Mini Projects For Github\\File Hadling To Do List\\product.txt", "w");
					if(file == NULL){
						printf("UNABLE TO READ FILE");
						return 0;
					}
					
					for(int i=0; i<count; i++){
						fprintf(file, "%s,%s,%d\n",products[i].prod_code, products[i].prod_description, products[i].avail_qty);
					}
					fclose(file);
					printf("\nItem Has Been Deleted!\n");
					continue;
				}else{
					printf("\nCODE NOT FOUND ERROR\n");
				}
			}

			
		}else if(menu_choice == 'V' || menu_choice == 'v'){
			printf("\n===VIEW===\n\n");
			FILE *file = fopen("C:\\1 Coding Projects\\Github Repositories\\C Repositories\\C Mini Projects For Github\\File Hadling To Do List\\product.txt", "r");
			if(file == NULL){
				printf("UNABLE TO READ FILE");
				return 0;
			}
			
			char line[256];
			printf("|  PROD CODE  |  PROD DESC  |  AVAIL QTY  |\n");
			while(fgets(line, sizeof(line), file)){
				line[strcspn(line, "\n")] = 0;
				
				char *col = strtok(line, ",");
				while(col != NULL){
					printf("%-15s", col);
					col = strtok(NULL, ",");
				}
				printf("\n");
			}
			fclose(file);
			
		}else if(menu_choice == 'X' || menu_choice == 'x'){
			printf("\n===EXIT===\n\n");
			return 0;
			
		}else{
			printf("\n\nSOMETHING WENT WRONG\n\n");	
		}
		
		printf("\n\n");
	}
	return 0;
}

int menu_verify_choice(char character){
	int menu_verify=0;
	switch(character){
		case 'A':
		case 'a':
		case 'E':
		case 'e':
		case 'D':
		case 'd':
		case 'V':
		case 'v':
		case 'X':
		case 'x':
			menu_verify = 1;
			break;
		default:
			menu_verify = 0;
			break;	
		}
	return menu_verify;
}

void txt_to_array(struct Product products[99], int *count){
	FILE *file = fopen("C:\\1 Coding Projects\\Github Repositories\\C Repositories\\C Mini Projects For Github\\File Hadling To Do List\\product.txt", "r");

    if(file == NULL){
        printf("Error opening file!\n");
        return;
    }
    
	char line[256];
	int counter = 0;
	while(fgets(line, sizeof(line), file)){
		line[strcspn(line, "\n")] = 0;
		char *col = strtok(line, ",");
		
		strcpy(products[counter].prod_code, col);
		col = strtok(NULL, ",");
		
		strcpy(products[counter].prod_description, col);
		col = strtok(NULL, ",");
		
		products[counter].avail_qty = atoi(col);
		counter++;
		
	}
	*count = counter;
	fclose(file);
}