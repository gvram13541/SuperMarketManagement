#include "services.h"

void services(){
    int choice = 0;

    cout << YELLOW << " ------------------------------------------------------------------------------------\n" << RESET;
    cout << "|" << RED << "\t|| " << GREEN << "WELCOME TO SUPER MARKET BILLING AND STOCK MANAGEMENT SYSTEM" << RED << " ||" << RESET << "\t     |" << endl;
    cout << YELLOW << " ------------------------------------------------------------------------------------\n" << RESET;

    cout << GREEN << "\t\t\t 1. MANAGE THE STOCK\n \t\t\t 2. SERVE THE CUSTOMER\n \t\t\t 3. EXIT\n" << RESET << endl;
    cout << BLUE << "Enter the choice(1-3): " << RESET;
    cin >> choice;

    if(choice == 1){
        managerServices();
    }
    else if(choice == 2){
        customerServices();
    }
    else if(choice == 3){
        cout << BLUE << "\t\t\t\t\tEXITING THE PROGRAM\n" << RESET;
    }
    else{
        cout << RED << "INCORRECT CHOICE MADE\n" << RESET << endl;
    }
}