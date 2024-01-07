#ifndef COFFEE_BOX_COFFEEMACHINE_H
#define COFFEE_BOX_COFFEEMACHINE_H

class CoffeeMachine {
public:
    CoffeeMachine();

    int run();

    static void printPrettyLine();

private:
    const int COFFEE_COUNT;
    const char **COFFEE_NAMES;
    const double *COFFEE_PRICES;
    const int PROGRESS_BAR_COLUMNS;
    const int PROGRESS_BAR_COLUMN_TIME;
    const int MAX_CUP_COUNT;
    int passwordAttempts;
    double balance;
    double revenue;
    int cupCount;

    void printMenu();

    void printCoffeeWithPrices();

    void printValue(double value);

    int getRoubles(double value);

    int getKopecks(double value);

    void makeCoffee(int choice);

    void printProgressBar();

    void enterCashDeposit();

    void printDepositMenu();
};

#endif //COFFEE_BOX_COFFEEMACHINE_H