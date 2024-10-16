#include "billingmethods.h"

using namespace std;

void customerServices() {
    int serve = 1, serviceNo;
    billingServices obj;
    ItemManagement itemobj;

    cout << YELLOW << " ------------------------------------------------------------------------------------\n" << RESET;
    cout << "|" << RED << "\t\t\t     || " << GREEN << "WELCOME TO BILLING SERVICES" << RED << " ||" << RESET << "\t\t\t     |" << endl;
    cout << YELLOW << " ------------------------------------------------------------------------------------\n" << RESET;

    cout << "\t\t\t\t" << YELLOW << "1. Add Items to the Cart\n";
    cout << "\t\t\t\t" << YELLOW << "2. Generate Bill\n";
    cout << "\t\t\t\t" << YELLOW << "3. Pleae click on Exit\n";
    cout << "\t\t\t\t" << RED << "(PLEASE EXIT TO SERVE NEW CUSTOMER)" << RESET << endl;

    while (serve) {
        cout << BLUE << "Enter the service number (1-3): " << RESET;
        cin >> serviceNo;

        if (serviceNo == 1) {
            string name;
            float quantity;

            cout << "Enter the name of the item: ";
            cin >> name;

            if(!itemobj.findItem(name)){
                cout << RED << "NO SUCH ITEM, TRY AGAIN!" << RESET << endl;
                continue;
            }

            cout << "Enter the quantity of the item: ";
            cin >> quantity;

            obj.addItems(name, quantity);

            string filename = obj.generateBill();

            ifstream live(filename);

            if(!live.is_open()){
                cerr << RED << "ERROR WHILE OPENING THE FILE" << RESET << endl;
            }

            string line;

            while(getline(live, line)){
                cout << line << endl;
            }

            cout << GREEN << "Item added successfully\n" << RESET << endl;
        } 
        else if (serviceNo == 2) {
            string filename = obj.generateBill();
            cout << GREEN << "Bill generated: " << filename << RESET << endl;
        } 
        else if (serviceNo == 3) {
            serve = 0;
            cout << BLUE << "\t\t\t\t\tEXITING FROM CUSTOMER SERVICES\n" << RESET << endl;
            services();
        } 
        else {
            cout << RED << "Invalid service number. Please try again.\n" << RESET;
        }
    }
}
