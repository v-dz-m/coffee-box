#include <iostream>
#include <windows.h>

using namespace std;

const int COFFEE_COUNT = 3;
const char* COFFEE_NAMES[COFFEE_COUNT] = { "Espresso", "Cappuccino", "Latte" };
const int COFFEE_PRICES[COFFEE_COUNT] = { 150, 180, 180 };
const int PROGRESS_BAR_COLUMNS = 25;
const int PROGRESS_BAR_COLUMN_TIME = 200;
const int BEFORE_ACTION_TIME = 1000;
const int PASSWORD = 2024;
const int MAX_CUP_COUNT = 700;
const int DEFAULT_PASSWORD_ATTEMPTS = 3;
int passwordAttempts = DEFAULT_PASSWORD_ATTEMPTS;
int balance = 0;
int revenue = 0;
int cupCount = 7;

void printNoAttempts();
void printNoCups();
void printMenu();
void printPrettyLine();
void printCoffeeWithPrices();
void printValue(int value);
int getRoubles(int value);
int getKopecks(int value);
void makeCoffee(int choice);
void printProgressBar();
bool isCoinCorrect(int inputValue);
void enterManagePanel();
void showManagePanel();
void printManageMenu();
void enterCashDeposit();
void printDepositMenu();
void printRevenueBalance();
void printCupBalance();
void getRevenue();
void addCups();

int main()
{
    while (true) {
        int choice = 0;
        if (!passwordAttempts) {
            printNoAttempts();
            return 1;
        }
        else if (!cupCount) {
            printNoCups();
            return 2;
        }
        printMenu();
        cin >> choice;
        if (choice == 1) {
            enterCashDeposit();
        }
        else if (choice >= 2 && choice < COFFEE_COUNT + 2) {
            if (balance < COFFEE_PRICES[choice - 2]) {
                cout << "NOT ENOUGH MONEY. Please, make a cash deposit and try again..." << endl;
                continue;
            }
            makeCoffee(choice - 1);
        }
        else if (choice == 5) {
            enterManagePanel();
        }
        else {
            cout << "INVALID INPUT. Try again..." << endl;
        }
    }

    return 0;
}

void printNoAttempts()
{
    printPrettyLine();
    cout << "ERROR. Sorry, but our coffee machine is blocked. We do our best to fix it quickly." << endl;
    printPrettyLine();
}

void printNoCups()
{
    printPrettyLine();
    cout << "ERROR. Sorry, but not enough cups. We do our best to fix it quickly." << endl;
    printPrettyLine();
}

void printMenu()
{
    Sleep(BEFORE_ACTION_TIME);
    printPrettyLine();
    cout << "Current balance: ";
    printValue(balance);
    cout << endl << "1. Insert coin" << endl;
    printCoffeeWithPrices();
    cout << "5. Service" << endl;
    printPrettyLine();
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
        int price = COFFEE_PRICES[i];
        cout << i + 2 << ". " << COFFEE_NAMES[i] << " - ";
        printValue(price);
        cout << endl;
    }
}

void printValue(int value)
{
    cout << getRoubles(value) << "." << getKopecks(value) << " BYN";
}

int getRoubles(int value)
{
    return value / 100;
}

int getKopecks(int value)
{
    return value - getRoubles(value) * 100;
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
        if (!isCoinCorrect(input)) {
            printPrettyLine();
            cout << "ERROR. Your coin is not accepted. Please, try again." << endl;
            printPrettyLine();
            continue;
        }

        balance += input;
    }
}

void printDepositMenu()
{
    cout << endl << "Current balance: ";
    printValue(balance);
    cout << "." << endl << "Only coins are accepted: 10, 20, 50 kopecks and 1, 2 roubles." << endl;
    cout << "Please, enter coin value (1 rouble = 100, 2 roubles = 200)." << endl;
    cout << "If you finished cash deposit, just enter 0." << endl;
    cout << "Your coin value: ";
}

bool isCoinCorrect(int inputValue)
{
    const int COIN_COUNT = 5;
    const int COIN_VALUES[COIN_COUNT] = { 10, 20, 50, 100, 200 };
    for (int i = 0; i < COIN_COUNT; i++) {
        if (inputValue == COIN_VALUES[i]) {
            return true;
        }
    }

    return false;
}

void enterManagePanel()
{
    while (passwordAttempts) {
        int input = 0;
        cout << endl << "Enter a pin-code:" << endl;
        cin >> input;
        if (input == PASSWORD) {
            passwordAttempts = DEFAULT_PASSWORD_ATTEMPTS;
            break;
        }
        cout << "Incorrect PIN-code!" << endl;
        passwordAttempts--;
    }
    if (!passwordAttempts) {
        cout << endl << "The PIN-code was entered incorrectly 3 times.";
        cout << endl << "The machine is blocked!" << endl;
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
        if (choice == 3) {
            cout << "You leave manage menu..." << endl;
            break;
        }
        else if (choice == 1) {
            getRevenue();
        }
        else if (choice == 2) {
            addCups();
        }
        else {
            cout << "INVALID INPUT. Try again..." << endl;
        }
    }
}

void printManageMenu()
{
    Sleep(BEFORE_ACTION_TIME);
    printPrettyLine();
    printRevenueBalance();
    printCupBalance();
    cout << "1. Withdraw revenue" << endl;
    cout << "2. Replenish the number of cups" << endl;
    cout << "3. Return to the main menu" << endl;
    printPrettyLine();
    cout << "Please, choose an operation." << endl;
    printPrettyLine();
    cout << "Your choice: ";
}

void printRevenueBalance()
{
    cout << "Current revenue: ";
    printValue(revenue);
    cout << endl;
}

void printCupBalance()
{
    cout << "Current number of cups: " << cupCount << endl;
}

void getRevenue()
{
    Sleep(BEFORE_ACTION_TIME);
    revenue = 0;
    cout << "The revenue was withdrawn. Current revenue: ";
    printValue(revenue);
    cout << endl;
}

void addCups()
{
    int cupsToAdd;
    cout << "Enter the number of cups to add: ";
    cin >> cupsToAdd;

    if (cupsToAdd > 0 && cupCount + cupsToAdd <= MAX_CUP_COUNT) {
        cupCount += cupsToAdd;
        cout << "Added " << cupsToAdd << " cups. The cup balance is now " << cupCount << "." << endl;
    }
    else {
        cout << "INVALID INPUT OR CUP LIMIT EXCEEDED. Number of cups to add must be a positive integer and should not exceed the cup limit of " << MAX_CUP_COUNT << "." << endl;
    }
}