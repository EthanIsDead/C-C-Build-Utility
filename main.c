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
	char *sub_strs[256]; 
    
    int num_of_files = 0;

	while(fgets(buf, sizeof(buf), fp) != 0)
	{
        sub_strs[num_of_files] = (char*)malloc(strlen(buf)+1); 
		strcat(sub_strs[num_of_files], buf); 
        
        num_of_files++; 
	}
		
	pclose(fp);

    printf("---------------\n");

    for(int i = 0; i < num_of_files; i++)
	    printf("%s",sub_strs[i]);

    printf("---------------\n");
	printf("%d\n", num_of_files);
	printf("---------------\n");	

	char makefile_txt[1000] = ""; 

    {
        const char* output_txt = "output: "; 
        const char* obj_file_exten_txt = ".o"; 
        const char* cpp_file_exten_txt = ".cpp"; 
    
        strcat(makefile_txt, output_txt);
    
        for(int i = 0; i < num_of_files; i++)
        {
            char tmp_str[256] = ""; 
            
            for(int j = 0; j < strlen(sub_strs[i])-5; j++)
            {
                tmp_str[j] = *(sub_strs[i]+j);  
            }
                
            strcat(makefile_txt, tmp_str); 
            strcat(makefile_txt, obj_file_exten_txt); 
            strcat(makefile_txt, " "); 
        }
    
        strcat(makefile_txt, "\n\tg++ -Wall -g "); 

        for(int i = 0; i < num_of_files; i++)
        {
            char tmp_str[256] = ""; 
            
            for(int j = 0; j < strlen(sub_strs[i])-5; j++)
            {
                tmp_str[j] = *(sub_strs[i]+j);  
            }
                
            strcat(makefile_txt, tmp_str); 
            strcat(makefile_txt, obj_file_exten_txt); 
            strcat(makefile_txt, " "); 
        }

        strcat(makefile_txt, "-o output\n");

        for(int i = 0; i < num_of_files; i++)
        {
            char tmp_str[256] = ""; 
            
            for(int j = 0; j < strlen(sub_strs[i])-5; j++)
            {
                tmp_str[j] = *(sub_strs[i]+j);  
            }

            strcat(makefile_txt, tmp_str); 
            strcat(makefile_txt, obj_file_exten_txt); 
            strcat(makefile_txt, ": "); 
            strcat(makefile_txt, tmp_str); 
            strcat(makefile_txt, cpp_file_exten_txt); 
            strcat(makefile_txt, "\n\tg++ -c "); 
            strcat(makefile_txt, tmp_str); 
            strcat(makefile_txt, cpp_file_exten_txt);
			
			if(i < num_of_files-1)
				strcat(makefile_txt, "\n"); 
        }

		FILE *fptr;

		if ((fptr = fopen("test_project/Makefile","w")) == NULL)
		{
			printf("error opening file");
			exit(1);
		}

		fprintf(fptr,"%s", makefile_txt);
		fclose(fptr); 
	}

	printf("%s", makefile_txt); 
    printf("\n"); 
	
	return 0; 
}
