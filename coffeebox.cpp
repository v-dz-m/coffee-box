#include <iostream>
#include <windows.h>

using namespace std;

const int COFFEE_COUNT = 3;
const char* COFFEE_NAMES[COFFEE_COUNT] = { "Espresso", "Cappuccino", "Latte" };
const double COFFEE_PRICES[COFFEE_COUNT] = { 1.50, 2.50, 3.00 };
const int PROGRESS_BAR_COLUMNS = 25;
const int PROGRESS_BAR_COLUMN_TIME = 200;
const int PASSWORD = 2024;
const int MAX_CUP_COUNT = 700;
int passwordAttempts = 3;
double balance = 0;
double revenue = 0;
int cupCount = 700;

void printMenu();
void printPrettyLine();
void printCoffeeWithPrices();
void printValue(double value);
int getRoubles(double value);
int getKopecks(double value);
void makeCoffee(int choice);
void printProgressBar();
void enterManagePanel();
void showManagePanel();
void printManageMenu();
void enterCashDeposit();
void printDepositMenu();
void printRevenueBalance();
void getRevenue();
void printCupBalance();
void addCups();

int main()
{
    while (true) {
        int choice = 0;
        if (!passwordAttempts) {
            printPrettyLine();
            cout << "ERROR. Sorry, but our coffee machine is blocked. We do our best to fix it quickly." << endl;
            printPrettyLine();
            return 1;
        }
        else if (!cupCount) {
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
        }
        else if (choice >= 1 && choice <= COFFEE_COUNT) {
            if (balance < COFFEE_PRICES[choice - 1]) {
                cout << "NOT ENOUGH MONEY. Please, make a cash deposit and try again..." << endl;
                continue;
            }
            makeCoffee(choice - 1);
        }
        else if (choice == 9) {
            enterCashDeposit();
        }
        else if (choice == 7) {
            enterManagePanel();
        }
        else {
            cout << "INVALID INPUT. Try again..." << endl;
        }
    }

    return 0;
}

void printMenu()
{
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

void printPrettyLine()
{
    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
}

void printCoffeeWithPrices()
{
    for (int i = 0; i < COFFEE_COUNT; i++) {
        double price = COFFEE_PRICES[i];
        cout << i + 1 << ": " << COFFEE_NAMES[i] << "\t\t";
        printValue(price);
        cout << endl;
    }
}

void printValue(double value)
{
    cout << getRoubles(value) << " roubles " << getKopecks(value) << " kopecks";
}

int getRoubles(double value)
{
    return (int)value;
}

int getKopecks(double value)
{
    return (value - getRoubles(value)) * 100;
}

void makeCoffee(int coffeeNumber)
{
    cupCount--;
    cout << "Please, wait a moment and do not try to take a cup. Water is very hot!" << endl;
    printProgressBar();
    cout << "Your fragrant coffee is ready!" << endl;
    balance -= COFFEE_PRICES[coffeeNumber];
    revenue += COFFEE_PRICES[coffeeNumber];
}

void printProgressBar()
{
    for (int i = 0; i < PROGRESS_BAR_COLUMNS; i++) {
        cout << "█▓█";
        Sleep(PROGRESS_BAR_COLUMN_TIME);
    }
    cout << endl;
}

void enterCashDeposit()
{
    while (true) {
        int input = 0;
        printDepositMenu();
        cin >> input;

        if (input == 0) {
            break;
        }
        if (!(input == 1 || input == 2 || input == 5 || input == 10 || input == 20 || input == 50 || input == 100 || input == 200)) {
            printPrettyLine();
            cout << "ERROR. Your coin is not accepted. Please, try again." << endl;
            printPrettyLine();
            continue;
        }

        balance += (double)input / 100.0;
    }
}

void printDepositMenu()
{
    cout << endl << "Only coins are accepted: 1, 2, 5, 10, 20, 50 kopecks and 1, 2 roubles." << endl;
    cout << "Please, enter coin value (1 rouble = 100, 2 roubles = 200)." << endl;
    cout << "If you finished cash deposit, just enter 0." << endl;
    cout << "Your coin value: ";
}

void enterManagePanel()
{
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

void showManagePanel()
{
    int choice = 0;
    while (true) {
        printManageMenu();
        cin >> choice;
        if (choice == 0) {
            cout << "You leave manage menu..." << endl;
            break;
        }
        else if (choice == 1) {
            printRevenueBalance();
        }
        else if (choice == 2) {
            getRevenue();
        }
        else if (choice == 3) {
            printCupBalance();
        }
        else if (choice == 4) {
            addCups();
        }
        else {
            cout << "INVALID INPUT. Try again..." << endl;
        }
    }
}

void printManageMenu()
{
    Sleep(1000);
    printPrettyLine();
    cout << "1: Cash balance" << endl;
    cout << "2: Take revenue" << endl;
    cout << "3: Cup balance" << endl;
    cout << "4: Add cups" << endl;
    cout << "0: Exit" << endl;
    printPrettyLine();
    cout << "Please, choose an operation." << endl;
    printPrettyLine();
    cout << "Your choice: ";
}

void printRevenueBalance()
{
    cout << "Function is in development" << endl;
}

void getRevenue()
{
    cout << "Function is in development" << endl;
}

void printCupBalance()
{
    cout << "Function is in development" << endl;
}

void addCups()
{
    cout << "Function is in development" << endl;
}