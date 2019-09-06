#include<stdio.h>
        #include<stdlib.h>
        #include<unistd.h>
        #include<sys/types.h>
        #include<sys/wait.h>
        #include<string.h>

        extern int j;
        void command(char*a,char*prompt,char*prompt1,char*token);
        void binarycom(char*usercopy,char*print);
        void input()
        {
//Declaring variables
        char usercommand[30];
        char usercopy[30];
        char print[30];
        int len;
        char*token;
        char prompt[50];
        char*prompt1;
        int l;
        int i=0;


        while(1){
        // Prompt for newprt command
        if(j==1)
        fprintf(stdout,"<%d %s>",getpid(),prompt);
        if(j==2)
        fprintf(stdout,"<%d>",getpid());
        fgets(usercommand,31,stdin);
        len=strlen(usercommand);
        // if user enter more than 30 characters then reprompt
        if(strlen(usercommand)>30){
        usercommand[0]='\0';
        continue;
        }
// if User press enter 3 times consectively prints Be Cool
        if(len==1){
        i++;
        if(i==3){
        fprintf(stdout,"Be Cool\n");
        i=0;
        }
        continue;
        }
        if(len>1){
        i=0;
        }
        usercommand[len-1]='\0';
//        printf ("In here\n");

        strcpy(usercopy,usercommand);
        strcpy(print,usercommand);
        token=strtok(usercommand," ");
        //              printf ("Hello\n");

        // Non binary commands
        if((strcmp(token,"newprt")==0)||(strcmp(token,"defprt")==0)||(strcmp(token,"lo")==0)||(strcmp(token,"lock")==0)||(strcmp(token,"b")==0)||(strcmp(token,"bye")==0)){
// Calling command function
        command(usercommand,prompt,prompt1,token);
        }
        else{
        //calling binarycom function
        binarycom(usercopy,print);
        }
        }

        }
