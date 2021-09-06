#include "stdio.h"

long int filesize( FILE *fp )
  {
    long int save_pos, size_of_file;

    save_pos = ftell( fp );
    fseek( fp, 0L, SEEK_END );
    size_of_file = ftell( fp );
    fseek( fp, save_pos, SEEK_SET );
    return( size_of_file );
  }

typedef struct {
	int x;
	int y;
}Point;

typedef struct{
	Point pt1;
	Point pt2;
	int k;
	int b;
	int eqtion[10];
}line;

int main(){

	FILE *Straight_data;
	FILE *fp;
	Straight_data = fopen("Straight_data.txt", "a+");

	line Fpt;
	line Spt;

	if(Straight_data != NULL){

		printf("input x1, y1: ");
		scanf("%d %d", &Fpt.pt1.x, &Fpt.pt1.y);

		printf("input x2, y2: ");
		scanf("%d %d", &Spt.pt2.x, &Spt.pt2.y);

		Fpt.k = (Spt.pt2.y - Fpt.pt1.y) / (Spt.pt2.x - Fpt.pt1.x);
		Fpt.b = ((Spt.pt2.x * Fpt.pt1.y) - (Spt.pt2.y * Fpt.pt1.x)) / (Spt.pt2.x - Fpt.pt1.x);
		Spt.k = Fpt.k;
		Spt.b = Fpt.b;

		/*for(int i = 0; i !=  ; i = i + 6){
			fseek(Straight_data, i, SEEK_SET);
			while(fgets())
		}*/
		fp = fopen( "Straight_data.txt", "r" );
		if( fp != NULL ) {
		printf( "File size=%ld\n", filesize( fp ) );
		fclose( fp );
	}

		if(Fpt.b >= 0){
			fprintf(Straight_data, "y=%dx+%d\n", Fpt.k, Fpt.b);
		}else if(Fpt.b < 0){
			fprintf(Straight_data, "y=%d x %d\n", Fpt.k, Fpt.b);
		}else if(Fpt.k == 0){
			fprintf(Straight_data, "y=%d\n", Fpt.k, Fpt.b);
		}

	}else{
		fprintf(stderr, "Error");
		return 1;
	}
	fclose(Straight_data);
	return 0;
}
