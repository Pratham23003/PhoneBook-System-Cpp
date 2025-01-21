#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Phonebook{
    string phoneNum,name,address,search;
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
    

void Phonebook :: searchContact(){

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
    Phonebook obj1;
    obj1.addContact();
    return 0;
}