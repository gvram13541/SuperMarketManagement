#include "billingservices.h"

using namespace std;

void billingServices::addItems(const string &name, float quantity){
    item.name = name; 
    item.quantity = quantity;

    shoppedItems.push_back(item);
}

string billingServices::generateBill() {
    float total = 0;
    unordered_map<string, pair<float, float>> m = stockItems.stockInfo();

    string filename = "bill.txt";
    ofstream obj(filename);

    if(!obj.is_open()){
        cerr << RED << "ERROR WHILE OPENING THE FILE" << RESET << endl;
        return "";
    }

    obj << "Bill Information:\n";
    obj << "---------------------------------------\n";
    obj << std::left << std::setw(20) << "Item" 
        << std::setw(10) << "Quantity" 
        << std::setw(10) << "Cost" << "\n";
    obj << "---------------------------------------\n";

    for(const auto &item: shoppedItems) {
        auto it = m.find(item.name);

        if(it != m.end()){
            total += it->second.second * item.quantity;

            obj << std::left << std::setw(20) << item.name
                    << std::setw(10) << item.quantity 
                    << std::setw(10) << it->second.second * item.quantity << "\n";

            stockItems.updateQuantity(item.name, it->second.first - item.quantity);
        }
    }

    obj << "---------------------------------------\n";

    obj << "Total: " << total << endl;

    obj << "---------------------------------------\n";

    return filename;
}