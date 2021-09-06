#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Revers(char *output_str, int start, int end)
{
	char c;
	while(start < end)
	{
		c = output_str[start];
		output_str[start] = output_str[end];
		output_str[end] = c;
		start++;
		end--;
	}
}

int main()
{
	char input_str[64];
	printf("Enter string: \n");
	fgets(input_str,64,stdin);
	char *output_str = NULL;
	output_str = (char *) malloc((strlen(input_str)) * sizeof(char));
	strcpy(output_str, input_str);

	int start = 0, end = 0;
	for(int i = 0; i < strlen(input_str); i++)
	{
		if(output_str[i] == '\n' || output_str[i] == '\0' || output_str[i] == '-' || output_str[i] == '.' || output_str[i] == ',' || output_str[i] == ';' || output_str[i] == ':' || output_str[i] == ' ' || output_str[i] == '!' || output_str[i] == '?')
		{
			end = i -1;
			Revers(output_str, start, end);
			start = i +1;
		}
	}

	printf("End string: %s\n", output_str);

	free(output_str);
	return 0;
}
