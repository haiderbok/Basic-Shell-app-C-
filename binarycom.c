// execution of binary commands using execvp
#include<stdio.h>
        #include<stdlib.h>
        #include<unistd.h>
        #include<sys/types.h>
        #include<sys/wait.h>
        #include<string.h>

        void binarycom(char*usercopy,char*print){

        int l;
        int status;
        char usercopycopy[20];
        char**commandtokens;
        strcpy(usercopycopy,usercopy);
        char*token2;
        int count=0;
        token2=strtok(usercopycopy," ");
        while(token2!=NULL){
        count++;
        token2=strtok(NULL," ");
        }
        printf("count : %d\n",count);
        commandtokens=(char**)malloc(count*sizeof(char*));
        printf("count : %d\n",count);
        l=fork();
        if(l==0){
        char*token1;
        int p=0;
        //spliting tokens and placing them in our 2d array after dynamic allocation
        token1=strtok(usercopy," ");
        while(token1!=NULL){
        commandtokens[p]=(char*)malloc(strlen(token1)*sizeof(char));
        for(int i=0;i<strlen(token1);i++){
        *(*(commandtokens+p)+i)=*(token1+i);
        }
        token1=strtok(NULL," ");
        p++;
        }
        commandtokens[p]=NULL;
        // child code
        // execvp to execute the command and if fails prints error message
        printf("I'm the child:<%s><%d>\n",print,getpid());
        if(execvp(commandtokens[0],commandtokens)==-1){
        printf("Command not found\n");
        exit(1);
        }
        }else if(l< 0){
        printf("Forking failed\n");
        }
        else{
        waitpid(l,&status,0);
        }

        }
