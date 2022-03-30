//TEST PROJECT PATH = /home/ethanojede/Documents/Programming Projects/C_Build_Utility/test_project
//COMMAND TO LIST SPECIFIC FILES = ls | grep .c

//INCLUDES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//FUNCTIONS
int main(void)
{
	
	char cmd[] = "cd test_project && ls | grep .cpp";
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
		int size = 0; 
		char *sub_str;

		sub_str = strtok(str, "\n");

		size += sizeof(sub_str); 
		sub_strs = (char**)realloc(sub_strs, size); 

		*(sub_strs+idx) = sub_str; 

		while(sub_str != NULL) 
		{
			idx++; 
			printf("%s\n", sub_str);
			sub_str = strtok(NULL, "\n");

			size += sizeof(sub_str); 
			sub_strs = (char**)realloc(sub_strs, size);

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
	 
 
	
	char *makefile_text; 

	{
		int size = 0; 
		const char* output_text = "output: "; 
		const char* obj_file_exten_txt = ".o"; 

		size += sizeof(output_text); 
		makefile_text = (char*)realloc(makefile_text, size);

		strcat(makefile_text, output_text);
	}

	printf(makefile_text); 
	printf("\n"); 
	
	return 0; 
}


