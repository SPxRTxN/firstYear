#include <stdio.h>
#include <math.h>

char Clear(){
	while((getchar()) != '\n'){}
}

typedef struct {
	int x;
	int y;
	int z;
	float S;
}Points;

int main(){
	FILE *Triangle_data;
	Triangle_data = fopen("Triangle_data.txt", "a+");

	Points Fpt;
	Points Spt;
	Points Tpt;

	float c = 0;

	if(Triangle_data != NULL){
		printf("input x1, y1, z1: ");
		scanf("%d %d %d", &Fpt.x, &Fpt.y, &Fpt.z);

		printf("input x2, y2, z2: ");
		scanf("%d %d %d", &Spt.x, &Spt.y, &Spt.z);

		printf("input x3, y3, z3: ");
		scanf("%d %d %d", &Tpt.x, &Tpt.y, &Tpt.z);

		if(Fpt.z == 0 && Spt.z == 0 && Tpt.z == 0){
			c = (Stp.x - Fpt.x)*(Tpt.y - Fpt.y) - (Tpt.x - Fpt.x)*(Spt.y - Fpt.y);
			Spt.S = c/2;
			fprintf(Triangle_data, "%.2f\n", Spt.S);
		}else{
			c = sqrt(pow((Spt.y - Fpt.y)*(Tpt.z - Fpt.z)-(Tpt.y - Fpt.y)*(Spt.z - Fpt.z),2) + pow((Spt.x - Fpt.x)*(Tpt.z - Fpt.z)-(Tpt.x - Fpt.x)*(Spt.z - Fpt.z),2) + pow((Spt.x - Fpt.x)*(Tpt.y - Fpt.y)-(Tpt.x - Fpt.x)*(Spt.y - Fpt.y),2));
			Fpt.S = c / 2;
			fprintf(Triangle_data, "%.2f\n", Fpt.S);
	}

	}else{
		fprintf(stderr, "Error");
		return 1;
	}

	fclose(Triangle_data);
	return 0;
}
