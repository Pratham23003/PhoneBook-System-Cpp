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

}
void Phonebook :: searchContact(){  //aarti's code
       cout<<"Enter Phone Number::"; 
       getline(cin,search);
       file.open("info.csv",ios::in);
       
       getline(file,phoneNum,',');
       getline(file,name,',');
       getline(file,address,'\n');
       while(!file.eof()){
        if(phoneNum==search){
        cout<<"Phone Number::"<<phoneNum<<endl;
        cout<<"Phone Name::"<<name<<endl;
        cout<<"Phone Address::"<<address<<endl;
        }
        getline(file,phoneNum,',');
        getline(file,name,',');
        getline(file,address,',');
       }
       file.close();

}

int main(){
    Phonebook obj1;

    obj1.addContact();
    obj1.searchContact();
    return 0;
}