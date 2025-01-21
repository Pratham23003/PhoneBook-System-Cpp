#include<iostream>
#include<string>
#include<fstream>
#include<vector> // Needed for the deletion function
using namespace std;

class Phonebook {
    string phoneNum, name, address, search;
    fstream file;

public:
    void addContact();
    void showContacts();
    void searchContact();
    void deleteContact();
};

void Phonebook::addContact() { // Pratham's code
    cout << "Enter Phone number: ";
    cin.ignore();
    getline(cin, phoneNum);
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Address: ";
    getline(cin, address);

    file.open("info.csv", ios::out | ios::app);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    file << phoneNum << "," << name << "," << address << "\n";
    file.close();
}

void Phonebook::showContacts() { // Aryan's code
    file.open("info.csv", ios::in);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(file, phoneNum, ',') && getline(file, name, ',') && getline(file, address, '\n')) {
        cout << "Phone Number: " << phoneNum << endl;
        cout << "Phone Name: " << name << endl;
        cout << "Phone Address: " << address << endl;
        cout << "<----------------------------->" << endl;
    }

    file.close();
}

void Phonebook::searchContact() {  // Aarti's code
    cout << "Enter Name of the contact :";
    cin.ignore();
    getline(cin, search);

    file.open("info.csv", ios::in);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

    while (getline(file, phoneNum, ',') && getline(file, name, ',') && getline(file, address, '\n')) {
        if (name == search) {
            cout << "Phone Number: " << phoneNum << endl;
            cout << "Phone Name: " << name << endl;
            cout << "Phone Address: " << address << endl;
            file.close();
            return;
        }
    }

    cout << "Contact not found!" << endl;
    file.close();
}

void Phonebook::deleteContact() { // Saksham's code
    string phoneToDelete, line;
    vector<string> contacts;
    bool contactFound = false;

    cout << "Enter the phone number of the contact to delete: ";
    cin.ignore();
    getline(cin, phoneToDelete);

    file.open("info.csv", ios::in);
    if (!file) {
        cout << "Error opening file!" << endl;
        return;
    }

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
        if (!file) {
            cout << "Error opening file!" << endl;
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

int main() {
    Phonebook obj;
    char choice;

    do {
        cout << "\n1 --> Add Contact ";
        cout << "\n2 --> Show Contacts ";
        cout << "\n3 --> Search Contact ";
        cout << "\n4 --> Delete Contact ";
        cout << "\n5 --> Exit ";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': obj.addContact(); break;
            case '2': obj.showContacts(); break;
            case '3': obj.searchContact(); break;
            case '4': obj.deleteContact(); break;
            case '5': return 0;
            default: cout << "Invalid Selection!"; break;
        }
    } while (choice != '5');

    return 0;
}
