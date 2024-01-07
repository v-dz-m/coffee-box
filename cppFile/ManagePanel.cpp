#include "../headerFile/ManagePanel.h"
#include "../headerFile/CoffeeMachine.h"
#include "iostream"
#include <windows.h>

using namespace std;

ManagePanel::ManagePanel() :
        PASSWORD(2024),
        passwordAttempts(3) {
}

void ManagePanel::enterManagePanel() {
    while (passwordAttempts) {
        int input = 0;
        cout << "Please, enter the password: ";
        cin >> input;
        if (input == PASSWORD) {
            passwordAttempts = 3;
            break;
        }
        cout << "Password is not correct. " << --passwordAttempts << " attempts left." << endl;
    }
    if (!passwordAttempts) {
        return;
    }
    showManagePanel();
}

void ManagePanel::showManagePanel() {
    int choice = 0;
    while (true) {
        printManageMenu();
        cin >> choice;
        if (choice == 0) {
            cout << "You leave manage menu..." << endl;
            break;
        } else if (choice == 1) {
            printRevenueBalance();
        } else if (choice == 2) {
            getRevenue();
        } else if (choice == 3) {
            printCupBalance();
        } else if (choice == 4) {
            addCups();
        } else {
            cout << "INVALID INPUT. Try again..." << endl;
        }
    }
}

void ManagePanel::printManageMenu() {
    Sleep(1000);
    CoffeeMachine::printPrettyLine();

    cout << "1: Cash balance" << endl;
    cout << "2: Take revenue" << endl;
    cout << "3: Cup balance" << endl;
    cout << "4: Add cups" << endl;
    cout << "0: Exit" << endl;

    CoffeeMachine::printPrettyLine();

    cout << "Please, choose an operation." << endl;

    CoffeeMachine::printPrettyLine();
    cout << "Your choice: ";
}

void ManagePanel::printRevenueBalance() {
    cout << "Function is in development" << endl;
}

void ManagePanel::getRevenue() {
    cout << "Function is in development" << endl;
}

void ManagePanel::printCupBalance() {
    cout << "Function is in development" << endl;
}

void ManagePanel::addCups() {
    cout << "Function is in development" << endl;
}