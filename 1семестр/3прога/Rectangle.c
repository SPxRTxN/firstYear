#include <stdio.h>
#include <math.h>

typedef struct {
	int x;
	int y;
	int z;
}Point;

typedef struct{
	Point fpt;
	Point stp;
	Point tpt;
	Point foutpt;
}Dots;

int main(){

	Dots Fpt;
	Dots Stp;
	Dots Tpt;
	Dots Fourpt;

	FILE *Rectangle_data;
	Rectangle_data = fopen("Rectangle_data.txt", "a+");

	if(Rectangle_data != NULL){
		printf("input x1, y1, z1: ");
		scanf("%d %d %d", &Fpt.fpt.x, &Fpt.fpt.y, &Fpt.fpt.z);
		Clear();

		printf("input x2, y2, z2: ");
		scanf("%d %d %d", &Spt.spt.x, &Spt.spt.y, &Spt.spt.z);
		Clear();

		printf("input x3, y3, z3: ");
		scanf("%d %d %d", &Tpt.tpt.x, &Tpt.tpt.y, &Tpt.tpt.z);
		Clear(); 
	}else{
		fprintf(stderr, "Error");
		return 1;
	}

	fclose(Rectangle_data);
}
