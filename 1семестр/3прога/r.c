#include <stdio.h>

void clear()
{
	while (getchar() != '\n')
{}
}

struct point
{
	int x,y;
};

struct line
{
	struct point pt1;
	struct point pt2;
};

struct point makepoint (int x, int y)
{
	struct point temp;
	temp.x = x;
	temp.y = y;
	return temp;
}

struct line makeline (struct point p1, struct point p2)
{
	struct line ray;
	int k,b;
	k = (p2.y - p1.y) / (p2.x - p1.x);
	b = ((p2.x * p1.y) - (p2.y * p1.x)) / (p2.x - p1.x);
	printf ("k = %d\n", k);
	printf ("b = %d\n", b);
	return ray;

}



int main()
{
	char var;
	int choice,x,y;
	do
	{
	printf("Input\n 1 - Straight\n 2 - Triangle\n 3 - Rectangle \n");
	scanf("%d", &choice);
	clear();

		switch (choice)
		{
			case 1:
				printf("Enter x1\n");
				scanf("%d",&x);
				clear();
				printf("Enter y1\n");
				scanf("%d",&y);
				clear();
				struct point first;
				first = makepoint (x,y);
				printf("Enter x2\n");
				scanf("%d",&x);
				clear();
				printf("Enter y2\n");
				scanf("%d",&y);
				clear();
				struct point second;
				second = makepoint (x,y);
				makeline (first,second);

		}

		printf("Continue? y/n\n");
		scanf("%c", &var);
		clear();
	}
	while(var != 'n');
return 0;
}
