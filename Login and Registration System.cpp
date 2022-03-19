#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

string username;
string password;

void signup(){
    
    cout << "What will your username be: ";
    cin >> username;

    ofstream f(username + ".txt");

    cout << "Create a password: ";
    cin >> password;
    f << password;

    f.close();
}

void login() {

    cout << "Please insert your username: ";
    cin >> username;

    ifstream f(username + ".txt");
    
    char verifpass[16];
    char pass[16];

    f >> verifpass;

    f.close();

    cout << "Please insert your password: ";
    cin >> pass;

    do{
        if (strcmp(pass, verifpass) == 0)
            cout << "Log In succesfully!";
       
        else
            {
            cout << "Password incorrect, please try again: " << endl;
            cin >> pass;
            }
        } while (strcmp(pass, verifpass) != 0);
}

int main()
{
    int choice;

    cout << "Hello!"<<endl;
    cout << "What would you like to do?"<<endl;
    cout << "1. Sign Up" << endl;
    cout << "2. Log In" << endl;
    cout << "3. Exit" << endl;

    cin >> choice;

    do {

        while (choice < 1 || choice >3) {
            cout << "Wrong action, please choose a correct one!" << endl;
            cout << "1. Sign Up" << endl;
            cout << "2. Log In" << endl;
            cout << "3. Exit" << endl;
            cin >> choice;
        }

        switch (choice) {

        case 1: {
            signup();
            break;
        }

        case 2: {
            login();
            break;
        }

        case 3: {
            return 0;
            break;
        }
            
        }
    }while (choice >= 1 && choice <= 3);

    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
