#ifndef ITEMMANAGEMENT_H
#define ITEMMANAGEMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <algorithm>

#define RED "\033[31m"     
#define GREEN "\033[32m"    
#define YELLOW "\033[33m"   
#define BLUE "\033[34m"     
#define RESET "\033[0m"

using namespace std;

struct itemDetails {
    string name;
    float quantity;
    float cost;
};

class ItemManagement {
public:
    bool findItem(const string &name);
    void addItems(const string &name, float quantity, float cost);
    void updateName(const string &oldName, const string &newName);
    void updateQuantity(const string &name, float quantity);
    void updateCost(const string &name, float cost);
    unordered_map<string, pair<float, float>> stockInfo();

private:
    itemDetails item;
    vector<itemDetails> readFile();
    void writeFile(const vector<itemDetails> &items);
};

#endif
