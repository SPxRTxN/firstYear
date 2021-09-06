#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

char clear(){
  while ((getchar()) != '\n') {}
}

float Num(float num){
  printf("Input num: ");
  scanf("%f", &num);
  clear();
  return (num);
}

char Action(char action){
  printf("Enter action: ");
  scanf ("%c", &action);
  clear();
  return (action);
}

float sum(float num1, float num2){
	float res = num1 + num2;
	return (res);
}

float diff(float num1, float num2){
	float res = num1 - num2;
	return (res);
}

float split(float num1, float num2){
	float res = num1 / num2;
	return (res);
}

float mult(float num1, float num2){
  float res = num1 * num2;
	return (res);
}

float calc(float num1, char action, float num2){
  float res;
  switch(action){
  case '+':
      res = sum(num1, num2);
      printf("%.2f + %.2f = %.2f\n", num1, num2, res);
      return (res);
      break;
  case '-':
      res = diff(num1, num2);
      printf("%.2f - %.2f = %.2f\n", num1, num2, res);
      return (res);
      break;
  case '*':
      res = mult(num1, num2);
      printf("%.2f * %.2f = %.2f\n", num1, num2, res);
      return (res);
      break;
  case '/':
      if (num2 != 0) {
        res = split(num1, num2);
        printf("%.2f / %.2f = %.2f\n", num1, num2, res);
      }else{
        printf("Warning: num2 = 0\n");
    }
      return (res);
      break;
  case '^':
      res = pow(num1, num2);
      printf("%.2f ^ %.2f = %.2f\n", num1, num2, res);
      return (res);
      break;
  }

}

int main(){
  char action, reaction, q_result;
  float num1, num2], result, last_result;

  do {
		 printf("Enter '+, - , *, /, ^' or 'r' for using result\n");
     action = Action(action);
		 if(action == 'r'){
			 int s = 0;
       printf("Input 1 - if res its num1, 2 - num2: ");
       scanf("%d", &s);
       clear();
       if(s == 1 || s == 2){
         if(s == 1){
					 	 num2 = Num(num2);
             action = Action(action);
						 num1 = last_result;
         }else{
             num1 = Num(num1);
             action = Action(action);
             num2 = last_result;
           }
       }else{
         continue;
       }
         }else{
           if(action == '+'|| action == '-'|| action == '*'|| action == '/' || action == '^'){
           	 num1 = Num(num1);
             num2 = Num(num2);
           }else{
             printf("invalid input\n");
             continue;
           }
         }

		result = calc(num1, action, num2);

        printf("Save result:(y/n) ");
        scanf("%c", &q_result);
        clear();

        if(q_result == 'y'){
           last_result = result;
           printf("result = %.2f\n", last_result);
         }else{
           printf("Dont save!\n");
         }

     printf("Continue: (y/n)");
     scanf("%c", &reaction);
     clear();
		 printf("\n");

   } while( reaction != 'n' );
   printf("Good luck!");
  return 0;
}
