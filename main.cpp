#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void inventory();
void journal();
void sales();
void viewInventory();
void editInventory();
void addInventory();
void removeInventory();
void viewTransaction();
void addTransaction();
void viewSales();
void editSales();
void addSale();
void removeSale();

int main() {    
    int x;
    cout <<"      \\\\       Welcome Nick      ////       " << endl;
    cout <<"            Select an Option Below            " << endl;
    cout <<"                                              " << endl;
    cout << "                1. Inventory" << endl;
    cout << "                2. Journal" << endl;
    cout << "                3. Sales" << endl;
    cout << "Select Your Option: ";
    cin >> x;

    switch (x) {
        case 1:
            inventory();
            break;
        
        case 2:
            journal();
            break;

        case 3:
            sales();
            break;

        default:
            system("cls");
            cout << "\t\t\t Please select from the options given above \n" << endl;
    }

    return 0;
}

void inventory() {
    int y;
    cout << "            Select an Option Below          " << endl;
    cout << "                                            " << endl;
    cout << "              1. View Inventory" << endl;
    cout << "              2. Edit Inventory" << endl;
    cout << "Select Your Option: ";
    cin >> y;

    switch (y) {
        case 1:
            viewInventory();
            break;

        case 2:
            editInventory();
            break;

        default:
            system("cls");
            cout << "\t\t\t Please select from the options given above \n" << endl;

        }
        
    }

    void viewInventory() {
        ifstream Inventoryfile("inventory.txt");

        if(!Inventoryfile) {
            cout << "There was an error." << endl;
        }

        string line;
        getline(Inventoryfile, line);
        cout << line << endl;


    }

    void editInventory() {
        int q;
        
        cout << "            Select an Option Below          " << endl;
        cout << "                                            " << endl;
        cout << "              1. Add Inventory" << endl;
        cout << "              2. Remove Inventory" << endl;
        cout << "Select Your Option: ";
        cin >> q;

        switch (q) {
        case 1:
            addInventory();
            break;

        case 2:
            removeInventory();
            break;

        default:
            system("cls");
            cout << "\t\t\t Please select from the options given above \n" << endl;

        }
    }    
        
        void addInventory() {
            string dateAcquired, itemNumber, model, color, storage, boughtForPrice, conditionNotes;

        
            cout << "Please Enter Item Specifics Below" << endl;

            cout << " Date Acquired: " << endl;
            cin >> dateAcquired;
            cout << " Item Number: " << endl;
            cin >> itemNumber;
            cout << " Model: " << endl;
            cin >> model;
            cout << " Color: " << endl;
            cin >> color;
            cout << " Storage: " << endl;
            cin >> storage;
            cout << " Bought For Price: " << endl;
            cin >> boughtForPrice;
            cout << " Condition Notes: " << endl;
            cin >> conditionNotes;

            ofstream InventoryFile("inventory.txt", ios::app);

            InventoryFile << dateAcquired << "   " << itemNumber << "   " << model << " " << color << " " << storage << " " << boughtForPrice << " " << conditionNotes << " " << endl;

            InventoryFile.close();

            cout << "Item has been added!" << endl;
        }

        void removeInventory() {
            int num;

            cout << "Enter the item number you  would like to remove: ";
            cin >> num;
        
            fstream inventoryFile("inventory.txt");
            inventoryFile.open("inventory.txt", ios::in);
        }

void journal() {
    int p;
        
        cout << "            Select an Option Below          " << endl;
        cout << "                                            " << endl;
        cout << "              1. View All Transactions" << endl;
        cout << "              2. Add Transaction" << endl;
        cout << "Select Your Option: ";
        cin >> p;

        switch (p) {
        case 1:
            viewTransaction();
            break;

        case 2:
            addTransaction();
            break;

        default:
            system("cls");
            cout << "\t\t\t Please select from the options given above \n" << endl;

        }
    
    } 
    
    void viewTransaction() {
        fstream transactionFile("transaction.txt");
        transactionFile.open("transaction.txt", ios::in);

        if(!transactionFile) {
            cout << "There was an error." << endl;
        }
    }

    void addTransaction() {
        string date, description, amount;

        cout << "Please enter item specifics below: " << endl;

        cout << "Transaction Date: ";
        cin >> date;
        cout << "Description: ";
        cin >> description;
        cout << "Amount: ";
        cin >> amount;

        fstream input("transaction.txt");

        input.close();
        
    }

void sales() {
    int a;
        
        cout << "            Select an Option Below          " << endl;
        cout << "                                            " << endl;
        cout << "              1. View Sales" << endl;
        cout << "              2. Edit Sales" << endl;
        cout << "Select Your Option: ";
        cin >> a;

        switch (a) {
        case 1:
            viewSales();
            break;

        case 2:
            editSales();
            break;

        default:
            system("cls");
            cout << "\t\t\t Please select from the options given above \n" << endl;

        }

}

    void viewSales() {
        fstream salesFile("sales.txt");
        salesFile.open("sales.txt", ios::in);

        if(!salesFile) {
            cout << "There was an error." << endl;
        }
    }

    void editSales() {
        int u;

        cout << "            Select an Option Below          " << endl;
        cout << "                                            " << endl;
        cout << "              1. View Sales" << endl;
        cout << "              2. Edit Sales" << endl;
        cout << "Select Your Option: ";
        cin >> u;

        switch(u) {
            case 1:
                addSale();
                break;

            case 2:
                removeSale();
                break;

            default:
                system("cls");
                cout << "\t\t\t Please select from the options given above \n" << endl;

        }

    }

        void addSale() {
            string date, itemNumber, soldForPrice, shippingCost, repairCost;

            cout << "Please enter item specifics below: " << endl;

            cout << "Date: ";
            cin >> date;
            cout << "Item Number: ";
            cin >> itemNumber;
            cout << "Sold For Price: ";
            cin >> soldForPrice;
            cout << "Shipping Cost: ";
            cin >> shippingCost;
            cout << "Repair Cost: ";
            cin >> repairCost;

            fstream input("sales.txt");

            input.close();

        }

        void removeSale() {
            

        }




