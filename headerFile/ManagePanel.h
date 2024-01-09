#ifndef COFFEE_BOX_MANAGEPANEL_H
#define COFFEE_BOX_MANAGEPANEL_H

#include "CoffeeMachine.h"

class ManagePanel {
public:
    ManagePanel();

    void enterManagePanel();

private:
    const int PASSWORD;
    int passwordAttempts;

    void showManagePanel();

    void printManageMenu();

    //void printRevenueBalance();

    void getRevenue();

    void printCupBalance();

    void addCups();

    void printRevenueBalance();
};

#endif //COFFEE_BOX_MANAGEPANEL_H