//TEST PROJECT PATH = /home/ethanojede/Documents/Programming Projects/C_Build_Utility/test_project
//COMMAND TO LIST SPECIFIC FILES = ls | grep .c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	char cmd[] = "cd test_project && ls | grep .cpp"; //TODO: CHANGE THE COMMAND TO MAKE IT MODULAR 

	FILE *fp = popen(cmd, "r"); 
	char buf[256];
	char str[256]; 

	while(fgets(buf, sizeof(buf), fp) != 0)
	{
		strcat(str, buf); 	
	}
		
	pclose(fp);
	printf(str);

	///////////////////////////////////////////////////////////////////////////////////
	printf("---------------\n");

	int num_of_files = 0; 
	char **sub_strs;

	{
		int idx = 0; 
		char *sub_str;

		sub_str = strtok(str, "\n");
		sub_strs = (char**)realloc(sub_strs, sizeof(sub_strs) + sizeof(sub_str)); 
		*(sub_strs+idx) = sub_str; 

		while(sub_str != NULL) 
		{
			idx++; 
			printf("%s\n", sub_str);
			sub_str = strtok(NULL, "\n");
			sub_strs = (char**)realloc(sub_strs, sizeof(sub_strs) + sizeof(sub_str)); 
			*(sub_strs+idx) = sub_str; 
		}

		num_of_files = idx; 
	}

	////////////////////////////////////////////////////////////////////////////////////
	printf("---------------\n");	

	printf("%d\n", num_of_files); 

	////////////////////////////////////////////////////////////////////////////////////
	printf("---------------\n");	

	for(int i = 0; i < num_of_files; i++)
	{
		printf("%s\n", *(sub_strs+i));
	}

	////////////////////////////////////////////////////////////////////////////////////
	

	return 0; 
}

