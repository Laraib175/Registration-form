#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Address {
private:
    string street, city, state, zipCode;
public:
    Address(string street, string city, string state, string zip) {
        this->street = street;
        this->city = city;
        this->state = state;
        this->zipCode = zip;
    }
    string getAddress() {
        return street + ", " + city + ", " + state + " " + zipCode;
    }
};

class User {
private:
    string username, password;
    Address address; // composition: User has an Address
public:
    User(string name, string pass, Address addr) : address(addr) {
        username = name;
        password = pass;
    }
    string getUsername() {
        return username;
    }
    string getPassword() {
        return password;
    }
    string getAddress() {
        return address.getAddress();
    }
};

class UserManager {
private:
    vector<User> users;
public:
    void RegisterUser() {
        string username, password, street, city, state, zip;
        cout << "\t\tEnter user name:";
        cin >> username;
        cout << "\t\tEnter password:";
        cin >> password;
        cout << "\t\tEnter street:";
        cin >> street;
        cout << "\t\tEnter city:";
        cin >> city;
        cout << "\t\tEnter state:";
        cin >> state;
        cout << "\t\tEnter zip code:";
        cin >> zip;

        Address newAddress(street, city, state, zip);
        User newUser(username, password, newAddress);
        users.push_back(newUser);

        cout << "\t\t User Registered Successfully ....." << endl;
    }
    bool LoginUser(string name, string pass) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getUsername() == name && users[i].getPassword() == pass) {
                cout << "\t\tLogin successfully...." << endl;
                return true;
            }
        }
        cout << "\t\t Invalid Username or Password..." << endl;
        return false;
    }
    void showUser() {
        cout << "\t\t---Users List---" << endl;
        for (int i = 0; i < users.size(); i++) {
            cout << "\t\t" << users[i].getUsername() << " - " << users[i].getAddress() << endl;
        }
    }
    void searchUser(string username) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getUsername() == username) {
                cout << "\t\t User Found: " << users[i].getAddress() << endl;
                return;
            }
        }
        cout << "\t\t User Not Found" << endl;
    }
    void deleteUser(string username) {
        for (int i = 0; i < users.size(); i++) {
            if (users[i].getUsername() == username) {
                users.erase(users.begin() + i);
                cout << "\t\t Removed Successfully..." << endl;
                return;
            }
        }
        cout << "\t\t User Not Found" << endl;
    }
};

int main() {
    UserManager usermanage;

    int op;
    char choice;
    do {
        system("cls");
        cout << "\n\n\t\t1. Register User" << endl;
        cout << "\t\t2. Login" << endl;
        cout << "\t\t3. Show User List" << endl;
        cout << "\t\t4. Search User" << endl;
        cout << "\t\t5. Delete User" << endl;
        cout << "\t\t6. Exit" << endl;
        cout << "\t\tEnter Your Choice:";
        cin >> op;
        switch (op) {
        case 1: {
            usermanage.RegisterUser();
            break;
        }
        case 2: {
            string username, password;
            cout << "\t\tEnter Username:";
            cin >> username;
            cout << "\t\tEnter Password:";
            cin >> password;
            usermanage.LoginUser(username, password);
            break;
        }
        case 3: {
            usermanage.showUser();
            break;
        }
        case 4: {
            string username;
            cout << "\t\tEnter Username:";
            cin >> username;
            usermanage.searchUser(username);
            break;
        }
        case 5: {
            string username;
            cout << "\t\tEnter user name:";
            cin >> username;
            usermanage.deleteUser(username);
            break;
        }
        case 6:
            exit(1);
        }
        cout << "\t\tDo You Want TO Continue[Yes/No] ? :";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}



