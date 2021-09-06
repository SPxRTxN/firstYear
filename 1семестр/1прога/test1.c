#include <stdio.h> 
#include <math.h> 
void clear(){ 
    while ((getchar()) != '\n'){} 
} 

float sum(float n1,float n2){ 
    float res=n1+n2; 
    return (res); 
}

float diff(float n1, float n2){ 
    float res=n1-n2; 
    return(res);
} 

float mult(float n1, float n2){ 
    float res=n1*n2; 
    return(res);
} 

float div(float n1, float n2){ 
    float res=n1/n2; 
    return(res);
} 

float ere(float n1, float n2){ 
    float res = pow(n1,n2); 
    return(res);
} 

float calc(float n1, char sign, float n2){
    float result;
    switch(sign){ 
                case '+': 
                    result=sum(n1,n2); 
                    printf("Sum: %.2f\n", result); 
                    return result;
                    break; 
                case '-': 
                    result=diff(n1,n2); 
                    printf("Diff: %.2f\n", result); 
                    return result;
                    break; 
                case '*': 
                    result=mult(n1,n2); 
                    printf("Mult: %.2f\n", result); 
                    return result;
                    break; 
                case '/': 
                if (n2 != 0){ 
                    result=div(n1,n2); 
                    printf("Split: %.2f\n", result); 
                }else{ 
                    printf("I can not do this\n"); 
                    break; 
                    } 
                    return result;
                    break; 
                case '^': 
                    result=ere(n1,n2); 
                    printf("Ere: %.2f\n", result); 
                    return result;
                    break; 
               	default:
                    printf("invalid input");
                    break;
    }
}
    

int main(){ 
     
    float n1,n2,res,save; 
    char sign, press, choice1, reaction; 
    printf("Hello, My name calculator 2020!\n"); 
    do{ 
            printf("Enter '+, - , *, /, ^' or 'r' for using result\n");
            printf("Input sign "); 
            scanf("%с",&sign); 
            clear();            
            if(sign == 'r'){
			    int i = 0;
                printf("Input 1 - if res its num1, 2 - num2: ");
                scanf("%d", i);
                if(i == 1){
                    printf("Input second number "); 
                    scanf("%f",&n2); 
                    clear(); 
                    printf("Input sign "); 
                    scanf("%с",&sign); 
                    clear();
                    n1 = save;
                }else{
                    printf("Input first number "); 
                    scanf("%f",&n1); 
                    clear(); 
                    printf("Input sign "); 
                    scanf("%с",&sign); 
                    clear();
                    n2 = save;
                }
                }else{
                    printf("%s","Input first number "); 
                    scanf("%f",&n1); 
                    clear(); 
                    printf("%s","Input second number "); 
                    scanf("%f",&n2); 
                    clear();
                }
                    
            res = calc(n1, sign, n2);

            printf("Input 'y' if you need save result\n"); 
            scanf("%c", &choice1); 
            if(choice1=='y'){ 
                    save = res; 
                    printf ("Your saved results: %.2f\n", save);
                }else{
                    printf("Dont save result");
                    continue;
                }
                printf("Continue: (y/n)");
                scanf("%c", &reaction);
                clear();
                printf("\n");

            }while(reaction != 'n'); 
        
    return 0; 
}