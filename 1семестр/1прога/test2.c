#include <stdio.h>                                     

int main(){   
	char action = '+';                                    
    long long n1, n2, sum, diff, mult, split;                                          

    while (action != '0') { 
		printf("%s", "input first num , action, second num:");               
		scanf("%d%s%d", &n1, &action, &n2);                           

		switch (action) {                                     
            case '*':                                       
			mult = n1 * n2;                             
			printf("%s %d\n", "Mult:", mult);           
			break;                                     
		case '+':                                       
			sum = n1 + n2;                              
			printf("%s %d\n", "Sum:", sum);             
			break;                                      
		case '/':                                       
			split = n1 / n2;                            
			printf("%s %d\n", "Split:", split);         
			break;                                      
		case '-':                                                                      
			diff = n1 - n2;                             
			printf("%s %d\n", "Diff:", diff);          
			break;                                      
		}                                               

        n1 = 0;                                          
        n2 = 0;
	}                                                   
	return 0;                                                           
}                                                       
	


	