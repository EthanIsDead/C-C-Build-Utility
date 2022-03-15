//TEST PROJECT PATH = /home/ethanojede/Documents/Programming Projects/C_Build_Utility/test_project
//COMMAND TO LIST SPECIFIC FILES = ls | grep \.c

#include <stdio.h>
#include <string.h>

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

	printf("---------------\n");	
	
	int num_of_files = 0; 
		
	{
		char tmp_str[256]; 
		strcpy(tmp_str, str); 

		char *sub_strs;
		sub_strs = strtok(tmp_str, "\n");

		while(sub_strs != NULL) 
		{
			num_of_files++; 
			sub_strs = strtok(NULL, "\n");
		}
	}

	char *sub_strs;
	sub_strs = strtok(str, "\n");

	while(sub_strs != NULL) 
	{
		printf("%s\n", sub_strs);
		sub_strs = strtok(NULL, "\n");
	}

	printf("---------------\n");	

	printf("%d\n", num_of_files); 

	return 0; 
}

