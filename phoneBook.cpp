#include<iostream>
#include<string>
#include<fstream>
#include <vector> // Needed for the deletion function
using namespace std;
class Phonebook{
    string phoneNum,name,address;
    fstream file;
    public:
    void addContact();
    void showContacts();
    void searchContact();
    void deleteContact();
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

void Phonebook::deleteContact() {
    string phoneToDelete, line;
    vector<string> contacts;
    bool contactFound = false;

    cout << "Enter the phone number of the contact to delete: ";
    getline(cin, phoneToDelete);

    file.open("info.csv", ios::in);

    while (getline(file, line)) {
        size_t pos = line.find(",");
        string phoneNumInFile = line.substr(0, pos);

        if (phoneNumInFile == phoneToDelete) {
            contactFound = true;
        } else {
            contacts.push_back(line);
        }
    }
    file.close();

    if (contactFound) {
        file.open("info.csv", ios::out | ios::trunc);
        if (!file.is_open()) {
            cout << "Error: Unable to write to file!" << endl;
            return;
        }

        for (const string &contact : contacts) {
            file << contact << "\n";
        }
        file.close();
        cout << "Contact deleted successfully!" << endl;
    } else {
        cout << "Contact not found!" << endl;
    }
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
    cout << "Invalid Selection ";
    break;
    }
    return 0;
}