#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int redactfile(char* filename)
{
	int i = 0;
	char c;
	size_t capacity = 0;
	char* buff = NULL;
	buff = malloc(capacity * sizeof(char));

	FILE *TEXT;
	TEXT = fopen(filename,"r");
	
	if(TEXT == NULL)
	{
		printf("ERROR: file doesn't exist!");
		return 0;
	}

	while(!feof(TEXT))
	{
		if(i > capacity)
		{
			capacity+=1;
			buff = realloc(buff, (capacity + 1) * sizeof(char));
		}

		if( (c = fgetc(TEXT)) != ',' && c != ';' && 
			 c != ':' && c != '-')
		{
			buff[i] = c;
			i++;
		}			
	}
	buff[capacity] = '\0';
	
	TEXT = freopen(filename, "w", TEXT);
	fputs(buff, TEXT);
	fclose(TEXT);
	free(buff);
	return 0;
}

int palindrom(char* string) 
{ 
    int left_index = 0;
    int right_index = strlen(string)-1;
 
 
    while( left_index <= right_index )
    {
        if( string[left_index++] != string[right_index--])
        { 
            return 0;
 		}
 	}

 	return 1;
}

int takethesentence(char* filename)
{
	char cymbol;
	

	FILE *TEXT;

	TEXT = fopen(filename, "r");

	if(TEXT == NULL)
	{
		printf("ERROR: file doesn't exist!");
		return 1;
	}
	
	while(feof(TEXT) != 0)
	{
		int i = 0;
		size_t capofsentence = 0;
		char* sentence = malloc(capofsentence * sizeof(char));
		
		if(!sentence)
		{
			printf("\nMemory allocation error");
			return -1;
		}
		
		while((cymbol = fgetc(TEXT)) != '.')
		{
			if(i > capofsentence)
			{
				capofsentence+=1;
				sentence = realloc(sentence, (capofsentence + 1) * sizeof(char));

			}
			sentence[i] = cymbol;
			i++;
		}
		sentence[capofsentence+1] = '\0';

		if (palindrom(sentence) == 1)
		{
			printf("\n%s", sentence);
		}
	}	


	fclose(TEXT);

	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("you forgot to enter the filename");
		return 1;
	}
	

	
	

	char *filename = NULL;
	filename = malloc(sizeof(char) * (strlen(argv[1])+1));

	if(!(filename))
	{
		printf("Memory allocation error");
	}
	
	filename = argv[1];

	redactfile(filename);

	takethesentence(filename);
	
	return 0;
}

