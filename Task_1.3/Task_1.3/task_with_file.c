#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int main()
{
	// Открываем файл
	FILE* input = fopen("input.txt", "r");
	if (input == NULL)
	{
		return -1;
	}
	while (!feof(input))
	{
		char buffer[MAX];
		const int readBytes = fscanf(input, "%s", buffer);
		if (readBytes < 0)
		{
			break;
		}
		// Идем по строке и ищем ";"
		for (int i = 0; i < MAX; i++)
		{
			if (buffer[i] == ';')
			{
				for (int l = i; l < MAX; l++)
				{
					if (buffer[l] == 'М')
					{
						printf(" ");
					}
					
					else
					{
						printf("%c", buffer[l]);
					}
				}
				printf("\n");
			}
		}
		for (int i = 0; i < MAX; i++)
		{
			buffer[i] = ' ';
		}
	}
	fclose(input);
	return 0;
}