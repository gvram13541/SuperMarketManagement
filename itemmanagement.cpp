#include "itemmanagement.h" 

using namespace std;

vector<itemDetails> ItemManagement::readFile(){
    ifstream obj("stock.txt");

    if(!obj.is_open()){
        cerr << RED << "ERROR WHILE OPENING THE FILE" << RESET << endl;
        return {};
    }

    vector<itemDetails> items;
    string line;

    while(getline(obj, line)){
        istringstream iss(line);
        iss >> item.name >> item.quantity >> item.cost;
        items.push_back(item);
    }

    return items;
}

void ItemManagement::writeFile(const vector<itemDetails> &items){
    ofstream obj("stock.txt");

    if(!obj.is_open()){
        cerr << RED << "ERROR WHILE OPENING THE FILE" << RESET << endl;
        return;
    }

    for(const auto &item:items){
        obj << item.name << " " << item.quantity << " " << item.cost << endl;
    }
}

void ItemManagement::addItems(const string &name, float quantity, float cost){
        ofstream obj("stock.txt", ios_base::app | ios_base::out);

        if(!obj.is_open()){
            cerr << RED << "ERROR WHILE OPENING THE FILE" << RESET << endl;
            return;
        }

        obj << name << " " << quantity << " " << cost << endl;
}

void ItemManagement::updateName(const string &oldName, const string &newName){
    vector<itemDetails> items = readFile();

    for(auto &item:items){
        if(item.name == oldName){
            item.name = newName;
            break;
        }
    }

    writeFile(items);
}

void ItemManagement::updateQuantity(const string &name, float quantity){
    vector<itemDetails> items = readFile();

    for(auto &item:items){
        if(item.name == name){
            item.quantity = quantity;
            break;
        }
    }

    writeFile(items);
}

void ItemManagement::updateCost(const string &name, float cost){
    vector<itemDetails> items = readFile();

    for(auto &item:items){
        if(item.name == name){
            item.cost = cost;
            break;
        }
    }

    writeFile(items);
}

bool ItemManagement::findItem(const string &name){
    vector<itemDetails> items = readFile();

    for(const auto &item:items){
        if(item.name == name){
            return true;
        }
    }

    return false;
}

unordered_map<string, pair<float, float>> ItemManagement::stockInfo() {
    unordered_map<string, pair<float, float>> m;
    vector<itemDetails> items = readFile();

    for(auto item:items){
        m.insert({item.name, {item.quantity, item.cost}});
    }

    return m;
}