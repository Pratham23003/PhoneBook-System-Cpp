#include<iostream>
#include<string>
#include<fstream>
#include <vector> // Needed for the deletion function
using namespace std;
class Phonebook{
    string phoneNum,name,address,search;
    fstream file;
    public:
    void addContact();
    void showContacts();
    void searchContact();
    void deleteContact();
};
void Phonebook :: addContact(){
    cout << "Enter Phone number :";
    cin.ignore();
    getline(cin,phoneNum);
    cout << "\nEnter Name :";
    getline(cin,name);
    cout << "Enter Address :" << endl;
    getline(cin,address);
    file.open("info.csv",ios::out|ios::app);
    file<<phoneNum<<","<<name<<","<<address<<","<<"\n";
    file.close();
}
void Phonebook :: showContacts(){ 
    file.open("info.csv",ios :: in);
    getline(file,phoneNum,',');
    getline(file,name,',');
    getline(file,address,',');
    while(!file.eof()){
        cout<<"Phone Number: "<<phoneNum<<endl;
        cout<<"Phone Name: "<<name<<endl;
        cout<<"Phone Address: "<<address<<endl;
        getline(file,phoneNum,',');
        getline(file,name,',');
        getline(file,address,',');
    }
    file.close();
}

void Phonebook :: searchContact(){  //aarti's code
       cout<<"Enter Phone Number :"; 
       cin.ignore();
       getline(cin,search);
       file.open("info.csv",ios::in);

       getline(file,phoneNum,',');
       getline(file,name,',');
       getline(file,address,'\n');
       while(!file.eof()){
        if(phoneNum==search){
        cout<<"Phone Number :"<<phoneNum<<endl;
        cout<<"Phone Name :"<<name<<endl;
        cout<<"Phone Address :"<<address<<endl;
        }
        getline(file,phoneNum,',');
        getline(file,name,',');
        getline(file,address,',');
       }
       file.close();
}

void Phonebook::deleteContact() { //saksham's code
    string phoneToDelete, line;
    vector<string> contacts;
    bool contactFound = false;

    cout << "Enter the phone number of the contact to delete: ";
    cin.ignore();
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
    cout << "Enter your choice :";
    cin >> choice;

    Phonebook obj;
    switch(choice){
        case '1':
        obj.addContact();
        break;
        case '2':
        obj.showContacts();
        break;
        case '3':
        obj.searchContact();
        break;
        case '4':
        obj.deleteContact();
        break;
        case '5':
        return 0;
        break;
    default:
    cout << "Invalid Selection ";
    break;
    }
    return 0;
}