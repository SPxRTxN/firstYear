#include "stdio.h"

char Clear(){
	while((getchar()) != '\n'){}
}

typedef struct{
	char *name[50];
	int group;
	int mark[5];
}Student;

int main(){

	Student St;

	printf("Enter name: ");
	scanf("%s", &St.name);
	Clear();

	printf("Enter num group: ");
	scanf("%d", &St.group);
	Clear();

	for(int i = 0; i < 5; i++){
		printf("Input mark %d: ", i+1);
		scanf("%d", &St.mark[i]);
		Clear();
	}

	printf("Student name: %s\n", St.name);
	printf("Group num: %d\n", St.group);
	printf("Mark: %d, %d, %d, %d, %d", St.mark[0], St.mark[1], St.mark[2], St.mark[3], St.mark[4]);

	return 0;
}
