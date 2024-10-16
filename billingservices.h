#ifndef BILLINGSERVICES_H
#define BILLINGSERVICES_H

#include "ItemManagement.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

#define RED "\033[31m"     
#define GREEN "\033[32m"    
#define YELLOW "\033[33m"   
#define BLUE "\033[34m"     
#define RESET "\033[0m" 

class billingServices {
private:
    itemDetails item;
    ItemManagement stockItems;
    vector<itemDetails> shoppedItems;

public:
    void addItems(const string &name, float quantity);
    string generateBill();
};

#endif
