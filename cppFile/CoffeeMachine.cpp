#include "../headerFile/CoffeeMachine.h"
#include "iostream"
#include "../headerFile/ManagePanel.h"
#include <windows.h>

using namespace std;

CoffeeMachine::CoffeeMachine() :
        COFFEE_COUNT(3),
        COFFEE_NAMES(new const char *[COFFEE_COUNT]{"Espresso", "Cappuccino", "Latte"}),
        COFFEE_PRICES(new const double[COFFEE_COUNT]{1.50, 2.50, 3.00}),
        PROGRESS_BAR_COLUMNS(25),
        PROGRESS_BAR_COLUMN_TIME(200),
        MAX_CUP_COUNT(700),
        passwordAttempts(3),
        balance(0),
        revenue(0),
        cupCount(700) {
}

int CoffeeMachine::run() {
    while (true) {
        int choice = 0;

        if (!passwordAttempts) {
            printPrettyLine();
            cout << "ERROR. Sorry, but our coffee machine is blocked. We do our best to fix it quickly." << endl;
            printPrettyLine();
            return 1;
        } else if (!cupCount) {
            printPrettyLine();
            cout << "ERROR. Sorry, but not enough cups. We do our best to fix it quickly." << endl;
            printPrettyLine();
            return 2;
        }
        printMenu();
        cin >> choice;
        if (choice == 0) {
            cout << "Have a nice day!" << endl;
            break;
        } else if (choice >= 1 && choice <= COFFEE_COUNT) {
            if (balance < COFFEE_PRICES[choice - 1]) {
                cout << "NOT ENOUGH MONEY. Please, make a cash deposit and try again..." << endl;
                continue;
            }
            makeCoffee(choice - 1);
        } else if (choice == 9) {
            enterCashDeposit();
        } else if (choice == 7) {
            ManagePanel managePanel;
            managePanel.enterManagePanel();
        } else {
            cout << "INVALID INPUT. Try again..." << endl;
        }
    }
}

void CoffeeMachine::printMenu() {
    Sleep(1000);
    printPrettyLine();

    cout << "COFFEE BOX" << endl;
    printPrettyLine();

    printCoffeeWithPrices();
    cout << "9: Cash deposit" << endl;
    cout << "0: Exit" << endl;
    printPrettyLine();

    cout << "Your balance: ";
    printValue(balance);
    cout << "." << endl;
    cout << "Please, choose an operation." << endl;
    printPrettyLine();

    cout << "Your choice: ";
}

void CoffeeMachine::printPrettyLine() {
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
}

void CoffeeMachine::printCoffeeWithPrices() {
    for (int i = 0; i < COFFEE_COUNT; i++) {
        double price = COFFEE_PRICES[i];
        cout << i + 1 << ": " << COFFEE_NAMES[i] << "\t\t";
        printValue(price);
        cout << endl;
    }
}

void CoffeeMachine::printValue(double value) {
    cout << getRoubles(value) << " roubles " << getKopecks(value) << " kopecks";
}

int CoffeeMachine::getRoubles(double value) {
    return (int) value;
}

int CoffeeMachine::getKopecks(double value) {
    return (value - getRoubles(value)) * 100;
}

void CoffeeMachine::makeCoffee(int choice) {
    cupCount--;

    cout << "Please, wait a moment and do not try to take a cup. Water is very hot!" << endl;
    printProgressBar();
    cout << "Your fragrant coffee is ready!" << endl;

    balance -= COFFEE_PRICES[choice];
    revenue += COFFEE_PRICES[choice];
}

void CoffeeMachine::printProgressBar() {
    for (int i = 0; i < PROGRESS_BAR_COLUMNS; i++) {
        cout << "█▓█";
        Sleep(PROGRESS_BAR_COLUMN_TIME);
    }
    cout << endl;
}

void CoffeeMachine::enterCashDeposit() {
    while (true) {
        int input = 0;

        printDepositMenu();
        cin >> input;

        if (input == 0) {
            break;
        }
        if (!(input == 1 || input == 2 || input == 5 || input == 10 || input == 20 || input == 50 || input == 100 ||
              input == 200)) {
            printPrettyLine();

            cout << "ERROR. Your coin is not accepted. Please, try again." << endl;
            printPrettyLine();
            continue;
        }
        balance += (double) input / 100.0;
    }
}

void CoffeeMachine::printDepositMenu() {
    cout << endl << "Only coins are accepted: 1, 2, 5, 10, 20, 50 kopecks and 1, 2 roubles." << endl;
    cout << "Please, enter coin value (1 rouble = 100, 2 roubles = 200)." << endl;
    cout << "If you finished cash deposit, just enter 0." << endl;
    cout << "Your coin value: ";
}