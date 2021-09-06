#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

void * malloc(size_t size);
int *massive = NULL;
int n,x;

char clear()
{
    while ((getchar()) !='\n'){} //Функция очистки поля ввода
}

int massiv() // создание динамического массива и рандомайз
{
    int i=0;
    printf("Please enter number of array elements\n");
    scanf("%d",&n);
    clear();
    srand(time(NULL));
    massive=malloc(2*n*sizeof(int)); //Создание одномерного динамического массива размером 2n
    printf("Generated array:\n");
  for(int i = 0; i < 2*n-1; i++){
    massive[i] = rand() % (2*n);
    printf("%d ",massive[i]);
  }
   putchar('\n');
}

int bouble(int *massive, int n)  //Сортировка массива пузырьковым методом
{
  int c = 0;
printf("\nSorted array: \n");
for (int i=0; i < (2* n) -1; i++) {
  for (int j=0; j < (2* n)-i-1; j++) {
    if (massive[j] > massive[j+1]) {
      c = massive[j];
      massive[j] = massive[j+1];
      massive[j+1] = c;
        }
      }
    }
    for(int z = 0; z < (2*n); z++){
      printf("%d ", massive[z]);
    }
    printf("\n");
}
int search() //Выявление искомых чисел в массиве и вывод диапазона с правой и левой сторон по индексам

/*int left,right,l,r,res,mid;
res=-1;
while (l<=r)
{
  mid=(l+r);
  mid=mid/2;
  if (massive[mid]=x)
  {
    res=mid;
    printf("Number Founded");
    break;
  }
  if (massive[mid]<x)
  {
    r=mid-1;
  }
  if (massive[mid]>x)
  l=mid+1;
}
if (res=-1)
{
  printf("\n Fuuuck");
}*/
{
int l,r;
int left = 0;
int right = 2*n;
int search = -1;
while (left <= right){
int mid = (left + right) / 2;
if (x == massive[mid]) {
search = mid;
break;
}
if (x < massive[mid])
right = mid - 1;
else
left = mid + 1;
}
if (search == -1)
printf("Dont find!\n");
else
printf("massive[%d, %d]", left, right);
}


void main()             //Запрос длины массива,а так же искомого числа икс,реализация всех функций программы и вывод результата работы программы
{
    printf("Please enter number 'x' \n");
    scanf("%d",&x);
    clear();
    massiv();
    bouble(massive, n);
    search();
    free(massive);
    system("pause");
}
