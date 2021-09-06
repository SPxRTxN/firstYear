#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CounterOfObjects ()
{
  FILE *file;  
  char buffer[20];
  int count = 0;
  file = fopen("students.json", "r");
  while (fscanf(file, "%s", buffer) != EOF)
  {
      for (int i = 0; i <strlen(buffer); i++)
      {
          if (buffer[i] == '}')
          count++;
      }
  }
  fclose(file);
  return count;
}

void parser ()
{
    FILE *file;
    char buffer[20];
    struct Student *list = NULL;
    int counter = CounterOfObjects();
    file = fopen("table_of_hash.txt", "r");
    int CountFromStart = 0;
    while (fscanf(file, "%s", buffer) != EOF)
    {
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] == ':' && buffer[i+1] == '"')
            {
                char temp[sizeof(buffer)];
                i += 2;
                for (int c = 0; c < 20; c++)
                {
                    if (buffer[i] != '"')
                   {
                       temp[c] = buffer[i];
                       i++;
                   }
                   else break;
                }
                strcpy (list[CountFromStart].Name,temp);
                memset (temp,0,sizeof(temp));
                
            }
            // scan name
            if (buffer[i] == ':' && buffer[i+1] != '"' && buffer[i+1] != '[' )
            {
                int a = 0;
                i++;
                char temp[sizeof(buffer)];
                while (buffer[i] != ',')
                {
                    temp[a] = buffer[i];
                    a++;
                    i++;
                }
                list[CountFromStart].Group = atoi(temp);
                
            }
            
            if (buffer[i] == ':' && buffer[i+1] == '[')
            {
                i += 2;
                int a = 0;
                char temp;
                while (buffer[i] != ']')
                {
                    if (buffer[i] != ',' && buffer[i] != ']')
                    {
                    temp = buffer[i];
                    list[CountFromStart].Marks[a] = atoi(&temp);
                    i++;
                    a++;
                    }
                    else
                    i++;
                }
                CountFromStart++;
            }
            

        }

    }
    fclose(file);
    Bubble_sort(list,counter);
    shift (list);
}

 

int main()
{   
    parser();
    return 0;
}