#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User {
    string username,password;
    public:
        User(string username, string password) {
            this->username = username;
            this->password = password;
        }
        string getUsername() {
            return username;
        }
        string getPassword() {
            return password;
        }
};


class UserManager {
    vector<User> users; // create object of vector
    public:
        void RegisterUser() {
            string username,password;
            cout << "Enter username: "<<endl;
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            User newUser(username,password);
            users.push_back(newUser);

            cout << endl << "User registered successfully .....!" << endl;
        }
        bool loginUser() {
            string username,password;
            cout << "Enter username: "<<endl;
            cin >> username;
            cout << "Enter password: ";
            cin >> password;
            for(int i = 0; i < users.size(); i++) {
                if(users.at(i).getUsername() == username && users.at(i).getPassword() == password) {
                    cout << endl << "User Login successfully .....!" << endl;
                    return true;
                }
            }
            cout << endl << "Invalid Username and Password is used \n" << endl;
            return false;
        }
        void showAllUsers() {
            cout << "-----Users List-----" << endl;
            if(users.empty()) {
                cout << endl << "There are no users in the list." << endl;
            }else {
                for(int i = 0; i < users.size(); i++) {
                    cout << users.at(i).getUsername() << endl;
                }
            }

            cout << endl << "--------------------" << endl;
        }
        void searchUser() {
            string username;
            bool isNotFound = true;
            cout << "Enter username of the user you want : "<<endl;
            cin >> username;
            for(int i = 0; i < users.size(); i++) {
                if(users.at(i).getUsername() == username ) {
                    cout << "---- Users is found ----" << endl;
                    cout << users.at(i).getPassword() << endl;
                    cout << "------------------------" << endl;
                    isNotFound = false;
                    break;

                }
            }
            if(isNotFound) {
                cout << endl << "Invalid Username \n\n\n" << endl;
            }


        }
        void deleteUser() {
            string username;
            bool isNotFound = true;
            cout << "Enter username of the user you want to delete : "<<endl;
            cin >> username;
            for(int i = 0; i < users.size(); i++) {
                if(users.at(i).getUsername() == username ) {
                    users.erase(users.begin() + i);
                    cout << username << " is deleted successfully.\n" << endl;
                    isNotFound = false;
                    break;
                }
            }
            if(isNotFound) {
                cout << endl << "Invalid Username \n" << endl;
            }
        }

};


int main() {

    UserManager manager;
    while (true) {
        int option;
        cout << "1. Register user\n2. Login\n3. Show User List\n4. Search User\n5. Delete User\n6. Exit\nEnter your option: ";
        cin >> option;
        if(option == 6) {
            break;
        }
        switch (option) {
            case 1:
                manager.RegisterUser();
                break;
            case 2:
                manager.loginUser();
                break;
            case 3:
                manager.showAllUsers();
                break;
            case 4:
                manager.searchUser();
                break;
            case 5:
                manager.deleteUser();
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
    }


    return 0;
}
