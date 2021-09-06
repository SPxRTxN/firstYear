#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char clear(){
    while((getchar()) != '\n'){}
}

float numEnter(float num){
    
    printf("Enter num: ");
    scanf("%f", &num);
    clear();

    return num;
}

char actionEnter(char action){
    
    printf("Enter action: ");
    scanf("%c", &action);
    clear();

    return action;
}

float sum(float *numArray){
    float result = numArray[0] + numArray[1];
    return result;
}

float diff(float *numArray){
    
}

float mult(float *numArray){
    
}

float split(float *numArray){
    
}

float pow(float *numArray){
    
}

float calculator( char action, float *numArray){

    int N = 2;

    switch (action){
    case '+':
        printf("Sum: %f\n", sum(numArray[N]));
        break;
    case '-':
        break;
    case '*':
        break;
    case '/':
        break;
    case '^':
        break;
    default:
        break;
    }
}

int main(){

    char action;
    float numArray[2], result;

    numArray[0] = numEnter(numArray[0]);
    action = actionEnter(action);
    numArray[1] = numEnter(numArray[1]);

    calculator(action, numArray);

    return 0;
}