#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

int createAcc(){
    cout<<"createAcc module";
}

int deleteAcc(){
    cout<<"deleteAcc module";
}

int login(){

    char userLoginPwd[10];
    int userLoginPwdIndex = 0;
    char userLoginPwdTyping;

    cout<<"\nenter your login pwd: ";

    //masking password while typing
    for(userLoginPwdIndex = 0; userLoginPwdIndex< 10; userLoginPwdIndex++){

             userLoginPwdTyping = getch();

                 if(userLoginPwdTyping == 13){
                      break;
                     }

              userLoginPwd[userLoginPwdIndex] = userLoginPwdTyping;
              userLoginPwdTyping = '*' ;
              cout<<userLoginPwdTyping; 
       }

    //printing password
    userLoginPwd[userLoginPwdIndex]='\0';
    cout<<"\nyour password is "<<userLoginPwd;
}

int main(){

int userMainChoice;

//welcome text
cout<<"   WELCOME TO THE\n"; 

//ascii art made using text to ascii art generator online

cout<<" ___ _ _ _ _| |   _____ ___ ___ ___ ___ ___ ___\n";
cout<<"| . | | | | . |  |     | .'|   | .'| . | -_|  _|\n";
cout<<"|  _|_____|___|  |_|_|_|__,|_|_|__,|_  |___|_|  \n";
cout<<"|_|                                |___|      \n\n";

//displaying option
cout<<"1>create account\n";
cout<<"2>delete account\n";
cout<<"3>login\n";
cout<<"4>exit\n\n";

//taking user choice
cout<<"enter your choice (1/2/3/4): ";
cin>>userMainChoice;

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
    cout<<"invalid choice!";
}

}
