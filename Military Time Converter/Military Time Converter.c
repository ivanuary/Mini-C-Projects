#include <stdio.h>
#include <stdlib.h>
struct Time{
	int days;
	int hour;
	int minutes;
	int seconds;
}time[4];

int main(int argc, char *argv[]) {
	printf("===INPUT 4 INSTANCES OF TIME TO CONVERT TO MILITARY TIME===\n");

	for(int i=0; i<4; i++){
		printf("\nINSTANCE #%d\n", i+1);
		printf("Hours: "); scanf("%d", &time[i].hour);
		printf("Minutes: "); scanf("%d", &time[i].minutes);
		printf("Seconds: "); scanf("%d", &time[i].seconds);
	}
	
	for(int i=0; i<4; i++){
		int computed_seconds=0, manip_sec=0, manip_min=0, manip_hour=0;
		computed_seconds = (((time[i].hour*60)+time[i].minutes)*60) + time[i].seconds;
		manip_sec = computed_seconds;
		
		time[i].seconds = manip_sec%60;
		manip_min = manip_sec/60;
		
		time[i].minutes = manip_min%60;
		manip_hour = manip_min/60;
		
		time[i].hour = manip_hour%24;
		time[i].days = manip_hour/24;
	}
		
	
	printf("\n\nTIME CONVERSIONS:\n");
	for(int i=0; i<4; i++){
		printf("\nINSTANCE #%d\n", i+1);
		printf("DY : HR : MN : SC\n");
		printf("%02d : %02d : %02d : %02d\n", time[i].days, time[i].hour, time[i].minutes, time[i].seconds);
	}
	
	return 0;
}