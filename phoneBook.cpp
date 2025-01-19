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
void Phonebook :: showContacts(){
//aarti da code
}
void Phonebook :: searchContact(){
//aarti da code
}

int main(){
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
    return 0;
}