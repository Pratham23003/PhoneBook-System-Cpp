#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Phonebook{
    string phoneNum,name,address;
    fstream file;
    public:
    void addContact();
    void showContacts();
    void searchContact();
};
void Phonebook :: addContact(){
    cout << "Enter Phone number :";
    getline(cin,phoneNum);
    cout << "Enter Name :";
    getline(cin,name);
    cout << "Enter Address :";
    getline(cin,address);
    file.open("info.csv",ios::out|ios::app);
    file<<phoneNum<<","<<name<<","<<address<<","<<"\n";
    file.close();
}
<<<<<<< HEAD
void Phonebook :: showContacts(){ // Fucked by Aryan
    file.open("info.csv",ios :: in);
    getline(file,phoneNum,',');
    getline(file,name,',');
    getline(file,address,',');
    //  // Check if the file is empty
    // file.seekg(0, ios::end); // Move to the end of the file
    // if (file.tellg() == 0) { // Check if the position is 0 (empty file)
    //     cout << "The file is empty." << endl;
    //     file.close();
    //     return;
    // }
    //  // Reset file pointer to the beginning
    // file.seekg(0, ios::beg);
    
    while(!file.eof()){
        cout<<"Phone Number: "<<phoneNum<<endl;
        cout<<"Phone Name: "<<name<<endl;
        cout<<"Phone Address: "<<address<<endl;
        getline(file,phoneNum,',');
        getline(file,name,',');
        getline(file,address,',');
    }
    file.close();

=======
void Phonebook :: showContacts(){
//aarti da code
>>>>>>> b59cf6acff42afd9923e4bed3ec29e158507aeaf
}


void Phonebook :: searchContact(){
//aarti da code
}

int main(){
<<<<<<< HEAD
    Phonebook obj1;
    //obj1.addContact();
    obj1.showContacts();
=======
    char choice;
    cout << "1 --> Add Contact ";
    cout << "2 --> Show Contacts ";
    cout << "3 --> Search Contact ";
    cout << "4 --> Delete Contact ";
    cout << "5 --> Exit ";

    switch(choice){
        case '1':

        break;
        case '2':
        //aarti da code
        break;
        case '3':
        //aryan da code
        break;
        case '4':
        //saksham da code
        break;
        case '5':
        //exit ala
        break;
    default:

    }
>>>>>>> b59cf6acff42afd9923e4bed3ec29e158507aeaf
    return 0;
}