#include "managingmethods.h"   

using namespace std;

void managerServices() {
    int serve = 1, serviceNo;
    ItemManagement obj;

    cout << YELLOW << " ------------------------------------------------------------------------------------\n" << RESET;
    cout << "|" << RED << "\t\t\t     || " << GREEN << "WELCOME TO MANAGER SERVICES" << RED << " ||" << RESET << "\t\t\t     |" << endl;
    cout << YELLOW << " ------------------------------------------------------------------------------------\n" << RESET;

    cout << "\t\t\t\t" << YELLOW << "1. Stock Information\n";
    cout << "\t\t\t\t" << YELLOW << "2. Add Items to the Stock\n";
    cout << "\t\t\t\t" << YELLOW << "3. Update Cost\n";
    cout << "\t\t\t\t" << YELLOW << "4. Update Quantity\n";
    cout << "\t\t\t\t" << YELLOW << "5. Update Name\n";
    cout << "\t\t\t\t" << YELLOW << "6. Exit\n" << RESET << endl;

    while (serve) {
        cout << BLUE << "Enter the service number (1-6): " << RESET;
        cin >> serviceNo;

        switch (serviceNo) {
            case 1: {
                auto stock = obj.stockInfo();
                
                if (stock.empty()) {
                    cout << RED << "No items available in the stock.\n" << RESET;
                } else {
                    cout << GREEN << "Stock Information:\n" << RESET;
                    cout << "---------------------------------------\n";
                    cout << std::left << std::setw(20) << "Item" 
                        << std::setw(10) << "Quantity" 
                        << std::setw(10) << "Cost" << "\n";
                    cout << "---------------------------------------\n";

                    for (const auto& item : stock) {
                        cout << std::left << std::setw(20) << item.first 
                            << std::setw(10) << item.second.first 
                            << std::setw(10) << item.second.second << "\n";
                    }

                    cout << "---------------------------------------\n";
                }
                break;
            }
            case 2: {
                string name;
                float quantity, cost;

                cout << "Enter the name of the item: ";
                cin >> name;

                cout << "Enter the quantity of the item: ";
                cin >> quantity;

                cout << "Enter the cost of the item: ";
                cin >> cost;

                obj.addItems(name, quantity, cost);
                cout << GREEN << "Item added successfully\n" << RESET;
                break;
            }
            case 3: {
                string name;
                float cost;

                cout << "Enter the name of the item: ";
                cin >> name;

                if(!obj.findItem(name)){
                    cout << RED << "NO SUCH ITEM, TRY AGAIN!" << RESET << endl;
                    break;
                }

                cout << "Enter the new cost of the item: ";
                cin >> cost;

                obj.updateCost(name, cost);
                cout << GREEN << "Cost updated successfully\n" << RESET;
                break;
            }
            case 4: {
                string name;
                float quantity;

                cout << "Enter the name of the item: ";
                cin >> name;

                if(!obj.findItem(name)){
                    cout << RED << "NO SUCH ITEM, TRY AGAIN!" << RESET << endl;
                    break;
                }

                cout << "Enter the new quantity of the item: ";
                cin >> quantity;

                obj.updateQuantity(name, quantity);
                cout << GREEN << "Quantity updated successfully\n" << RESET;
                break;
            }
            case 5: {
                string oldName, newName;

                cout << "Enter the old name of the item: ";
                cin >> oldName;

                if(!obj.findItem(oldName)){
                    cout << RED << "NO SUCH ITEM, TRY AGAIN!" << RESET << endl;
                    break;
                }

                cout << "Enter the new name of the item: ";
                cin >> newName;

                obj.updateName(oldName, newName);
                cout << GREEN << "Name updated successfully\n" << RESET;
                break;
            }
            case 6: {
                serve = 0;
                cout << BLUE << "\t\t\t\t\tEXITING FROM MANAGER SERVICES\n" << RESET << endl;
                services();
                break;
            }
            default: {
                cout << RED << "Invalid service number. Please try again.\n" << RESET;
                break;
            }
        }
    }
}
