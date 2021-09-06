#include <stdio.h>
#include <math.h>
#include <stdlib.h>

char Clear(){
	while((getchar()) != '\n'){}
}
// структура для 2х точек
typedef struct {
	int x;
	int y;
	int z;
}Point;
//структура для линии
typedef struct{
	Point pt1;
	Point pt2;
	int eqtion1[10] = {pt1.y, k, pt1.x, b};
	int eqtion2[10] = {pt2.y, k, pt2.x, b};
}line;
//структура для точек треугольника
typedef struct {
	Point fpt;
	Point spt;
	Point tpt;
	float S;
}Points;

//прямая y=kx+b
void Straight(){
	//создание имени файла для прямой
	FILE *Straight_data;
	Straight_data = fopen("Straight_data.txt", "a+"); // открытие файла для чтения и добавления записи в конец
	//объявляем структуру line для использования 2х пар точек
	line Fpt;
	line Spt;
	// если файл создан/открыт успешно
	if(Straight_data != NULL){
		//считываем первую пару точек
		printf("input x1, y1: ");
		scanf("%d %d", &Fpt.pt1.x, &Fpt.pt1.y);
		Clear();
		//считываем вторую пару точек
		printf("input x2, y2: ");
		scanf("%d %d", &Spt.pt2.x, &Spt.pt2.y);
		Clear();
		//по формулам вычисляем к и б
		Fpt.k = (Spt.pt2.y - Fpt.pt1.y) / (Spt.pt2.x - Fpt.pt1.x);
		Fpt.b = ((Spt.pt2.x * Fpt.pt1.y) - (Spt.pt2.y * Fpt.pt1.x)) / (Spt.pt2.x - Fpt.pt1.x);
		Spt.k = Fpt.k;
		Spt.b = Fpt.b;
		// y=kx + b
		//пока проверочная запись данных в файл
		fprintf(Straight_data, "%d= %d(%d) + (%d)\n%d= %d(%d) + (%d)", Fpt.pt1.y, Fpt.k, Fpt.pt1.x, Fpt.b, Spt.pt2.y, Spt.k, Spt.pt2.x, Spt.b);

	}else{//если файл не создался/открылся выходиим из программы
		fprintf(stderr, "Error");
		return 1;
	}

	fclose(Straight_data);//закрываем файл
}
// треугольник
void Triangle(){
	// создание имени файла для треугольника
	FILE *Triangle_data;
	Triangle_data = fopen("Triangle_data.txt", "a+");//открытие файла для треугольника
	// структуры для точек треугольника
	Points Fpt;
	Points Spt;
	Points Tpt;
	//промежуточная переменная для площади
	float c = 0;
	// если файл создан/открыт успешно
	if(Triangle_data != NULL){
		//считываем точки
		printf("input x1, y1, z1: ");
		scanf("%d %d %d", &Fpt.fpt.x, &Fpt.fpt.y, &Fpt.fpt.z);
		Clear();

		printf("input x2, y2, z2: ");
		scanf("%d %d %d", &Spt.spt.x, &Spt.spt.y, &Spt.spt.z);
		Clear();

		printf("input x3, y3, z3: ");
		scanf("%d %d %d", &Tpt.tpt.x, &Tpt.tpt.y, &Tpt.tpt.z);
		Clear();
		// если оси z нет то считаем по формуле для плоскости 2D
		if(Fpt.fpt.z == 0 && Spt.spt.z == 0 && Tpt.tpt.z == 0){
			c = (Stp.spt.x - Fpt.fpt.x)*(Tpt.tpt.y - Fpt.fpt.y) - (Tpt.tpt.x - Fpt.fpt.x)*(Spt.spt.y - Fpt.fpt.y); // формула для плоскости 2D
			Spt.S = c/2; // площадь
			fprintf(Triangle_data, "%.2f\n", Spt.S); // запись в файл
		}else{ // иначе для 3х мерного пространства
			//фармула для 3D пространства
			c = sqrt(pow((Spt.spt.y - Fpt.fpt.y)*(Tpt.tpt.z - Fpt.fpt.z)-(Tpt.tpt.y - Fpt.fpt.y)*(Spt.spt.z - Fpt.fpt.z),2) + pow((Spt.spt.x - Fpt.fpt.x)*(Tpt.tpt.z - Fpt.ftp.z)-(Tpt.tpt.x - Fpt.fpt.x)*(Spt.spt.z - Fpt.fpt.z),2) + pow((Spt.spt.x - Fpt.fpt.x)*(Tpt.tpt.y - Fpt.fpt.y)-(Tpt.tpt.x - Fpt.fpt.x)*(Spt.spt.y - Fpt.fpt.y),2));
			Fpt.S = c / 2;//площадь
			fprintf(Triangle_data, "%.2f\n", Fpt.S);//запись в файл
	}
	}else{//если файл не создался/открылся выходиим из программы
		fprintf(stderr, "Error");
		return 1;
	}

	fclose(Triangle_data);
}
//недописал для прямоугольника
void Rectangle(){
	
	FILE *Rectangle_data;
	Rectangle_data = fopen("Rectangle_data.txt", "a+");

	if(Rectangle_data != NULL){
		printf("Rectangle\n");
		//code
	}else{
		fprintf(stderr, "Error");
		return 1;
	}

	fclose(Rectangle_data);
}

int main(){
	char reaction;
	int choice;

	printf("Hi, I'm your math assistant!\n");

	do{

	printf("Input 1 - Straight, 2 - Triangle, 3 - Rectangle: ");
	scanf("%d", &choice);
	Clear();

		switch (choice) {
			case 1:
				Straight();
				break;
			case 2:
				Triangle();
				break;
			case 3:
				Rectangle();
				break;
			default:
				printf("Input error!\n");
				continue;
		}

		printf("Continue:(y/n) ");
		scanf("%c", &reaction);
		Clear();

	}while(reaction != 'n');

	return 0;
}
