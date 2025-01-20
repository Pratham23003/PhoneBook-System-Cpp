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

}


void Phonebook :: searchContact(){

}

int main(){
    Phonebook obj1;
    //obj1.addContact();
    obj1.showContacts();
    return 0;
}