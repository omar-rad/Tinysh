#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>                                  //this import is for handling the directory files


int main(){                                           // main method


int status = 1;                                       //i made it as a stopper for the loop when user enters exit it turn to 0

char command[50];                                     //takes user input

while(status != 0){                                   //loop that keeps asking Tinysh> untill you exit

printf("%s", "Tinysh > ");                            //prints prompt

gets(command);                                        //this gets function takes the whole string with spaces instead of (scanf) which stops when there is space



if(strcmp(command, "exit")==0){                       //the if statement checks if the command is equal to a specific command then it can excute
    status = 0;                                       //for this case when user enters exit the status becomes 0 and the loop stops
}


else if(strcmp(command, "help")== 0){                 //checks command
printf("cd pwd ls touch exit \n");                    //prints all possible

}

else if(strcmp(command, "cd")== 0){

char path[300];
printf("%s", "type the path you want to change to> ");
gets(path);                                                   //takes the new path
int ch = chdir(path);                                         //chdir function will change the directory to the given path

if(ch<0){                                                     //when chdir returns if its less than 0 it means the directory did not change
printf("directory did not changed \n");
}
else{                                                         //other wise chdir function changed directory
printf("directory has been changed successfully \n");
}
}


else if(strcmp(command, "pwd")== 0){                                   //checks command if its equal to pwd
char s[100];                                                          // setting size
printf("Current working dir: %s\n", getcwd(s, 100));                 // getcwd function returns current working directory
}


else if(strcmp(command, "ls")== 0){
DIR *d;                                                              //for the directory access
struct dirent *dir;                                                  // creating a struct class
d = opendir(".");                                                    // opens current directory function
if (d){
while ((dir = readdir(d)) != NULL){                                  //if the directory is not null it will keep reading until its null
printf("%s ", dir->d_name);                                          //prints file name
}
printf("\n");
closedir(d);                                                         //closes directory
}
}


else if(strcmp(command, "ls -l")== 0){
DIR *d;
struct dirent *dir;
d = opendir(".");
if (d){
while ((dir = readdir(d)) != NULL){
printf("%s \n", dir->d_name);                // all code is the same like the ls command put the differnce is in the print where \n makes the list pattern
}
closedir(d);
    }
}

else if(strcmp(command, "ls -la")== 0){
DIR *d;
struct dirent *dir;
d = opendir(".");
if (d){
while ((dir = readdir(d)) != NULL){
printf("%s \n", dir->d_name);                // all code is the same like the ls -l
}
closedir(d);
    }

}

else if(strcmp(command, "touch")== 0){

      char filename[33];                                 //storing filename that will be taken from the user
      FILE *fp;                                          //creating File

      printf("%s", "fileName > ");                       //prints
      gets(filename);                                    //takes filename from user



if( access( filename, F_OK ) == 0 ) {                     // checks if file exists

      char writes[200];
      fp =fopen(filename, "w");                           // if file exists it will overwrite it

      printf("write inside file \n");                     //prints
      gets(writes);                                       //i used gets functions since it will take user input even with spaces

      fprintf(fp,"%s \n" ,writes);                        //stores the user input inside the file if it was a .txt file
      fclose(fp);                                         //after opening a file we should close it
}
else {                                                    // if file does not exists it will create it
    fp = fopen(filename, "w");                            // since i did not specify a path it will be created in the same directory as this C file
    fclose(fp);                                           // closes the file
    printf("file created succesfully \n");                // prints
}
}

else{
        if(strstr(command, "pwd") != NULL) {                                // checks the substring of comannd bt strstr() function
        printf("%s,<- unknown command do you mean pwd \n ",command) ;
        }
        else if(strstr(command, "ls") != NULL){
        printf("%s,<- unknown command do you mean ls -la \n",command);
        }
        else if(strstr(command, "cd") != NULL) {
        printf("%s,<- unknown command do you mean cd \n",command);                   // all these checks for the substring of the command to help the user
        }
        else if(strstr(command, "exit") != NULL){
        printf("%s,<- unknown command do you mean exit \n",command);
        }
        else if(strstr(command, "help") != NULL){
        printf("%s,<- unknown command do you mean help \n",command);
        }
        else if(strstr(command, "touch") != NULL){
        printf("%s,<- unknown command do you mean touch \n,",command);
        }
        else{                                                                     //if none of commands are met it prints unsupported
        printf("unsupported command \n");
        }

}

}

return 0;

}
