#include <stdio.h>

int sequence(int *massiveS[], int i){
	int S1 = massiveS[i-1];
	int S2 = massiveS[i-2];
	int result = 15*S1 - 7*S2;
  return result;
}

int maint(){
    int n;
    scanf("%d", &n);

    int massiveS[10];
    massiveS[0] = 0;
    massiveS[1] = 1;
    for(int i = 2; i <= 10; i++){
        massiveS[i] = sequence(massiveS[i], i);
    }
    for (int b = 0; b < 10; b++)
    {
       printf("%d\n", massiveS[b]);
    }

}
