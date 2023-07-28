#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void renderMenu();
void renderAddPassword();

string masterPassword;

const std::string fileName = "password.txt";

string encryptPassword(string password){
    string cipherPassword;
    int lengthOfPassword = password.length(), loopIndex;

    for(loopIndex = 0; loopIndex<lengthOfPassword; loopIndex++){
        //encryption formula, can be changed to something more complex
        cipherPassword += ((password[loopIndex]+4)); 
    }

    return cipherPassword;
}

string decryptPassword(string cipherPassword){
    string decryptedPassword;
    int lengthOfPassword = cipherPassword.length(), loopIndex;

    //decryption using the same encryption formula
    for(loopIndex = 0; loopIndex < lengthOfPassword; loopIndex++){
        decryptedPassword += ((cipherPassword[loopIndex])-4);
    }
    return decryptedPassword;
}

int createPasswordFile(){

   fstream file;
    // Check if the file already exists
    file.open(fileName, std::ios::in);
    if (file) {
        file.close();
        exit(0);
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
     renderMenu();
   }

int setMasterPassword(){
    string password, cipherPassword;

      fstream file;
    // Check if the file already exists
    file.open(fileName, std::ios::in);
    if (file) {
        file.close();
        cout<<"\nmaster password already exits!\n"<<endl;
        renderMenu();
        exit(0);
    }

    cout<<"\nset master password: ";
    cin>>password;

   //calling encryption program
    cipherPassword = encryptPassword(password);

    masterPassword= "master:" +  cipherPassword; 
   // cout<<masterPassword;
    createPasswordFile();
    storeInPasswordFile();
   
}

int createAcc(){
    setMasterPassword();

}

int deleteAcc(){
    const char* fileName = "password.txt";

    // Check if the file exists before removing it
    if (remove(fileName) != 0) {
        perror("error deleting account");
        renderMenu();
    } 
    
        else {
            cout<<"\naccount deleted successfully.\n\n";
            renderMenu();
        }

    return 0;
}

int addNewPassword(){

    string passPrefix, subPass, passMainEncrypted, passMain;
    cout<<"password for: ";
    cin>>passPrefix;
    cout<<"password: ";
    cin>>subPass;

    passMain = passPrefix + ":" + subPass;
    passMainEncrypted = encryptPassword(passMain);

    fstream file;
    file.open(fileName, ios::app);
    file<<passMainEncrypted;
    file<<"\n";
    file.close();
    renderAddPassword();
}

void renderAddPassword(){
    /*asking for new passcodes*/
    int userChoiceSub;
    cout<<"\ndo you want to add new password? (0/1):"<<endl;
    cin>>userChoiceSub;

    switch(userChoiceSub){

        case 1:
        addNewPassword();
        break;

        case 0:
        renderMenu();
        break;
    
        default:
        cout<<"invalid choice!";
    }
}

int showPasswordList(){


    // bring master password from file
    fstream file(fileName);
    string line;
    string tempPassList;
    string masterPrefix = "master:";
   cout<<"\nyour password database: \n\n";
    while (getline(file, line)) { //stores each line to line variable one by one
 
        
        if (line.find(masterPrefix) != 0) { //searched master: prefix in each line
            // Extract the password from the line
            
           cout<<decryptPassword(line)<<endl;
        }
    }
    renderAddPassword();
}

int login(){
string tempMasterPassword;
string tempDecryptedPassword;
string tempExtractedPassword;

fstream file;
// Check if the file exists or not
    file.open(fileName, ios::in);
    if (!file) {
        file.close();
        cout<<"account does not exist"<<endl;
        exit(0);
    }

    //ask for master password
    cout<<"\nenter your master password: ";
    cin>>tempMasterPassword;

    // bring master password from file
    ifstream fileTwo(fileName);
    string line;
    string masterPrefix = "master:";
   
    while (getline(fileTwo, line)) { //stores each line to line variable one by one
 
        
        if (line.find(masterPrefix) == 0) { //searched master: prefix in each line
            // Extract the password from the line
            tempExtractedPassword = line.substr(masterPrefix.length());
            break; // Stop searching after finding the first password
        }
    }

     // decrypt the master password
    tempDecryptedPassword = decryptPassword(tempExtractedPassword);
    
  //compare with temp master password
    if(tempMasterPassword==tempDecryptedPassword){
        cout<<"\npassword matched\n";
        showPasswordList();
        
    }

    else{
        cout<<"wrong passcode";
    }

}

void renderMenu(){

int userMainChoice;
    //displaying option
cout<<"\nmenu: \n";
cout<<"\n1>create account\n";
cout<<"2>delete account\n";
cout<<"3>login\n";
cout<<"4>exit\n\n";

//taking user choice
cout<<"enter your choice (1/2/3/4): ";
cin>>userMainChoice;
top:
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

int main(){

//welcome text
cout<<"   WELCOME TO THE\n"; 

//ascii art made using text to ascii art generator online

cout<<" ___ _ _ _ _| |   _____ ___ ___ ___ ___ ___ ___\n";
cout<<"| . | | | | . |  |     | .'|   | .'| . | -_|  _|\n";
cout<<"|  _|_____|___|  |_|_|_|__,|_|_|__,|_  |___|_|  \n";
cout<<"|_|                                |___|      \n\n";

renderMenu();

}
