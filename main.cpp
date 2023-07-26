#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<iostream>

using namespace std;

string masterPassword;
const std::string fileName = "password.txt";

string encryptPassword(string password){
    string cipherPassword;
    int lengthOfPassword = password.length(), loopIndex;

    for(loopIndex = 0; loopIndex<lengthOfPassword; loopIndex++){
        cipherPassword += ((password[loopIndex]+4)/2);                   //encryption formula, can be changed to something more complex
    }

    return cipherPassword;
}

string decryptPassword(string cipherPassword){
    string decryptedPassword;
    int lengthOfPassword = cipherPassword.length(), loopIndex;

    //decryption using the same encryption formula
    for(loopIndex = 0; loopIndex < lengthOfPassword; loopIndex++){
        decryptedPassword += ((cipherPassword[loopIndex]*2)-4);
    }

    return decryptedPassword;
}

int createPasswordFile(){

   fstream file;
    // Check if the file already exists
    file.open(fileName, std::ios::in);
    if (file) {
        file.close();
        return 0;
    }

    file.open(fileName, std::ios::out);

    if (!file) {
        std::cerr << "error creating the file " << fileName << ".\n";
        return 1;
    }

    file.close();
    return 0;

 }

string storeInPasswordFile(){
  ofstream outputFile(fileName, ios::app);

  if (!outputFile) {
        cerr << "Error opening the file " << fileName << " for writing.\n";
    }

    outputFile << masterPassword << endl;
    outputFile.close();
   }

int setMasterPassword(){
    string password, cipherPassword;
    cout<<"\nset master password:"<<endl;
    cin>>password;
   
   //calling encryption program
    cipherPassword = encryptPassword(password);

    masterPassword= "master:" + password; 
    cout<<masterPassword;
    createPasswordFile();
    storeInPasswordFile();
}

int createAcc(){
    setMasterPassword();
    
}

int deleteAcc(){
    cout<<"deleteAcc module";
}

int login(){
/*
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
    cout<<"\nyour password is "<<userLoginPwd;*/
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
