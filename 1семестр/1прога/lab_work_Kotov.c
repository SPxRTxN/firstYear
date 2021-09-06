#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

char clear(){
  while ((getchar()) != '\n') {}
}

float numEnter(float num)
{
  printf("Input num: ");
  scanf("%f", &num);
  clear();
  return (num);
}

char actionEnter(char action)
{
  printf("Enter action: ");
  scanf ("%c", &action);
  clear();
  return (action);
}

float sum(float num1, float num2)
{
	float res = num1 + num2;
	return (res);
}

float subtract(float num1, float num2)
{
	float res = num1 - num2;
	return (res);
}

float division(float num1, float num2)
{
	float res = num1 / num2;
	return (res);
}

float multiplication(float num1, float num2)
{
  float res = num1 * num2;
	return (res);
}

float calculator(float num1, char action, float num2)
{
  float res;
  switch(action)
  {
  // sum function
  case '+':
      res = sum(num1, num2);
      printf("\t%.2f + %.2f = %.2f\t\n", num1, num2, res);
      return (res);
      break;
  // subtraction function
  case '-':
      res = subtract(num1, num2);
      printf("\t%.2f - %.2f = %.2f\t\n", num1, num2, res);
      return (res);
      break;
  //multiplication function
  case '*':
      res = multiplication(num1, num2);
      printf("\t%.2f * %.2f = %.2f\t\n", num1, num2, res);
      return (res);
      break;
  // division function
  case '/':
      if (num2 != 0) {
        res = division(num1, num2);
        printf("\t%.2f / %.2f = %.2f\t\n", num1, num2, res);
      }else{
        printf("Warning: num2 = 0\n");
    }
      return (res);
      break;
  //exponentiation function
  case '^':
      res = pow(num1, num2);
      printf("\t%.2f ^ %.2f = %.2f\t\n", num1, num2, res);
      return (res);
      break;
  }

}

int main()
{
  char action, reaction, q_result;
  float num1, num2, result, last_result;

  do 
  {
    printf("Enter '+, - , *, /, ^' or 'r'(when used for the first time, r is 0) for using last result\n");
    action = actionEnter(action);
    //if for using last result or using the remaining actions
		if(action == 'r')
    {
		  int s = 0;
      printf("Input 1 - if res its num1, 2 - num2: ");
      scanf("%d", &s);
      clear();
      // checking the entered data for correctness
      if(s == 1 || s == 2)
      {
        // last result it's first num
        if(s == 1)
        {
				 	num2 = numEnter(num2);
          action = actionEnter(action);
					num1 = last_result;
        }else // last result it's second num
          {
            num1 = numEnter(num1);
            action = actionEnter(action);
            num2 = last_result;
          }
      }else // incorrect data entry for using last result
      {
        printf("incorrect data entry");
        continue;
      }
    }else // if don't using result
      {
        // checking the entered data for correctness
        if(action == '+'|| action == '-'|| action == '*'|| action == '/' || action == '^'){
          num1 = numEnter(num1);
          num2 = numEnter(num2);
        }else // incorrect data entry for action
          {
            printf("incorrect data entryt\n");
            continue;
          }
      }

    // if the data is entered correctly, we use the function
		result = calculator(num1, action, num2);

    printf("Save result:(y/n) ");
    scanf("%c", &q_result);
    clear();

    if(q_result == 'y')
    {
      last_result = result;
      printf("result = %.2f\n", last_result);
    }else
      {
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
