// Non binary command execution
#include<stdio.h>
        #include<stdlib.h>
        #include<unistd.h>
        #include<sys/types.h>
        #include<sys/wait.h>
        #include<string.h>

        extern int j;
        void command(char*usercommand,char*prompt,char*prompt1,char*token){
        char com[30];
        int k=0;
        if((strcmp(token,"newprt")==0)){
        prompt1=&usercommand[7];
        // storing prompt to be printined        
        for(int i=0;i<strlen(prompt1);i++){
        prompt[i]=usercommand[7+i];
        }
        prompt[strlen(prompt1)]='\0';
        j=1;
        }
        // other wise print the default prompt
        if((strcmp(token,"defprt")==0)){
        j=2;
        }
        // check if the user locked the screen
        if((strcmp(usercommand,"lock")==0)||((strcmp(usercommand,"lo")==0))){
        com[0]='\0';
        while(strcmp(com,"ilovecs")!=0){
        fprintf(stdout,"EnterKey: ");
        fgets(com,31,stdin);
        com[strlen(com)-1]='\0';
        k++;
        // if user enter wrong passcode exit.
        if(k==5){
        exit(1);
        }
        }

        }
        // if user enters b or bye close the shell 
        if((strcmp(usercommand,"bye")==0)||(strcmp(usercommand,"b")==0)){
        exit(0);
        }
        }
