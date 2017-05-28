#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int redactfile(char* argv[])
{
	char c;
	
	FILE *TEXT;
	TEXT = fopen(argv[1],"r");
	if(TEXT == NULL)
	{
		printf("ERROR: file doesn't exist!");
		return 0;
	}

	size_t capacity = 0;
	char* buff = NULL;
	buff = malloc(capacity * sizeof(char));

	int i = 0;
	while(!feof(TEXT))
	{
		if(i > capacity)
		{
			capacity+=1;
			buff = realloc(buff, (capacity + 1) * sizeof(char));
		}

		if((c = fgetc(TEXT)) != ',' && 
			c != ';' && 
			c != ':' && 
			c != '-'
		  )
		{
			buff[i] = c;
			i++;
		}			
	}
	buff[capacity] = '\0';
	
	TEXT = freopen(argv[1], "w", TEXT);
	fputs(buff, TEXT);
	free(buff);
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
	char c;
	size_t capofsentence = 0;
	char* sentence = NULL;
	
	sentence = malloc(capofsentence * sizeof(char));
	
	redactfile(argv[1]);
	
	FILE *TEXT;
	
	TEXT = fopen(argv[1], "r");
	
	int i = 0;
	while((c = fgetc(TEXT)) != '.')
	{
		if(i > capofsentence)
		{
			capofsentence+=1;
			sentence = realloc(sentence, (capofsentence + 1) * sizeof(char));

		}
		sentence[i] = c;
		i++;
	}
	sentence[capofsentence+1] = '\0';
	fclose(TEXT);
}
