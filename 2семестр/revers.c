#include <stdio.h>
int strLength(char *input) {
int i = 0;
while(input[i++]!='\0');
return --i;
}

int main()
{
char input[] = "impossible";

int len = strLength(input);
char output[len];

int index = 0;
while(len >= 0) {
output[index++] = input[--len];
}

printf("%s\n",input);
printf("%s\n",output);
return 0;
}
