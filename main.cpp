#include<iostream>
#include<conio.h>
#include<string>

int createAcc(){
    printf("createAcc module");
}

int deleteAcc(){
    printf("deleteAcc module");
}

int login(){

    char userLoginPwd[10];
    int userLoginPwdIndex = 0;
    char userLoginPwdTyping;

    printf("\nenter your login pwd: ");

    //masking password while typing
    for(userLoginPwdIndex = 0; userLoginPwdIndex< 10; userLoginPwdIndex++){

             userLoginPwdTyping = getch();

                 if(userLoginPwdTyping == 13){
                      break;
                     }

              userLoginPwd[userLoginPwdIndex] = userLoginPwdTyping;
              userLoginPwdTyping = '*' ;
              printf("%c ", userLoginPwdTyping);
       }

    //printing password
    userLoginPwd[userLoginPwdIndex]='\0';
    printf("\nyour password is %s", userLoginPwd);
}

int main(){

int userMainChoice;

//welcome text
printf("   WELCOME TO THE\n"); 

//ascii art made using text to ascii art generator online

printf(" ___ _ _ _ _| |   _____ ___ ___ ___ ___ ___ ___\n");
printf("| . | | | | . |  |     | .'|   | .'| . | -_|  _|\n");
printf("|  _|_____|___|  |_|_|_|__,|_|_|__,|_  |___|_|  \n");
printf("|_|                                |___|      \n\n");

//displaying option
printf("1>create account\n");
printf("2>delete account\n");
printf("3>login\n");
printf("4>exit\n\n");

//taking user choice
printf("enter your choice (1/2/3/4): ");
scanf("%d", &userMainChoice);

//redirecting user according to their choice
switch(userMainChoice){
    case 1:
    createAcc();
    break;

    case 2:
    deleteAcc();
    break;

    case 3:
    login();
    break;
    
    case 4:
    exit(0); // exit(0) statement which means successful termination of the program
    break;

    default:
    printf("invalid choice!");
}

}
