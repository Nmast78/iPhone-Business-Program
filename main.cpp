#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
//#include <bits/stdc++.h>

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
    std::cout <<"      \\\\       Welcome Nick      ////       " << std::endl;
    std::cout <<"            Select an Option Below            " << std::endl;
    std::cout <<"                                              " << std::endl;
    std::cout << "                1. Inventory" << std::endl;
    std::cout << "                2. Journal" << std::endl;
    std::cout << "                3. Sales" << std::endl;
    std::cout << "Select Your Option: ";
    std::cin >> x;

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
            std::cout << "\t\t\t Please select from the options given above \n" << std::endl;
    }

    return 0;
}

void inventory() {
    int y;
    std::cout << "            Select an Option Below          " << std::endl;
    std::cout << "                                            " << std::endl;
    std::cout << "              1. View Inventory" << std::endl;
    std::cout << "              2. Edit Inventory" << std::endl;
    std::cout << "Select Your Option: ";
    std::cin >> y;

    switch (y) {
        case 1:
            viewInventory();
            break;

        case 2:
            editInventory();
            break;

        default:
            system("cls");
            std::cout << "\t\t\t Please select from the options given above \n" << std::endl;

        }
        
    }

    void viewInventory() {
        std::ifstream Inventoryfile("inventory.txt");

        if(Inventoryfile.is_open()) {
            std::string inv;

            while (std::getline(Inventoryfile, inv)) {
                std::cout << inv << "\n";            
            }
            
            Inventoryfile.close();
        }
    }

    void editInventory() {
        int q;
        
        std::cout << "            Select an Option Below          " << std::endl;
        std::cout << "                                            " << std::endl;
        std::cout << "              1. Add Inventory" << std::endl;
        std::cout << "              2. Remove Inventory" << std::endl;
        std::cout << "Select Your Option: ";
        std::cin >> q;

        switch (q) {
        case 1:
            addInventory();
            break;

        case 2:
            removeInventory();
            break;

        default:
            system("cls");
            std::cout << "\t\t\t Please select from the options given above \n" << std::endl;

        }
    }    
        
        void addInventory() {
            std::string dateAcquired, itemNumber, model, color, storage, boughtForPrice, conditionNotes;

        
            std::cout << "Please Enter Item Specifics Below" << std::endl;

            std::cout << " Item Number: " << std::endl;
            std::cin >> itemNumber;
            std::cout << " Date Acquired: " << std::endl;
            std::cin >> dateAcquired;
            std::cout << " Model: " << std::endl;
            std::cin >> model;
            std::cout << " Color: " << std::endl;
            std::cin >> color;
            std::cout << " Storage: " << std::endl;
            std::cin >> storage;
            std::cout << " Bought For Price: " << std::endl;
            std::cin >> boughtForPrice;
            std::cout << " Condition Notes: " << std::endl;
            std::cin >> conditionNotes;

            std::ofstream InventoryFile("inventory.txt", std::ios::app);

            InventoryFile << itemNumber << "   " << dateAcquired << "   " << model << " " << color << " " << storage << " " << boughtForPrice << " " << conditionNotes << " " << std::endl;

            InventoryFile.close();

            std::cout << "Item has been added!" << std::endl;
        }
        //Doesn't work right
        void removeInventory() {
            std::string line, number;

            std::cout << "Please enter the item number you want to delete: ";
            std::cin >> number;

            std::ifstream InventoryFile;
            InventoryFile.open("inventory.txt");
            std::ofstream temp;
            temp.open("temp.txt");
            while(getline(InventoryFile, line)) {
                if(line != number) {
                    temp << line << std::endl;
                }
            }
            std::cout << "Item number " << number << " has been deleted." << std::endl;

            InventoryFile.close();
            temp.close();
            remove("inventory.txt");
            rename("temp.txt", "inventory.txt");
        }

void journal() {
    int p;
        
        std::cout << "            Select an Option Below          " << std::endl;
        std::cout << "                                            " << std::endl;
        std::cout << "              1. View All Transactions" << std::endl;
        std::cout << "              2. Add Transaction" << std::endl;
        std::cout << "Select Your Option: ";
        std::cin >> p;

        switch (p) {
        case 1:
            viewTransaction();
            break;

        case 2:
            addTransaction();
            break;

        default:
            system("cls");
            std::cout << "\t\t\t Please select from the options given above \n" << std::endl;

        }
    
    } 
    
    void viewTransaction() {
        std::ifstream transactionFile("transaction.txt");

        if (transactionFile.is_open()) {
            std::string tp;

            while(getline(transactionFile, tp)) {
                std::cout << tp << "\n";
            }

            transactionFile.close();
        }
        
    }

    void addTransaction() {
        std::string date, description, amount;

        std::cout << "Please enter item specifics below: " << std::endl;

        std::cout << "Transaction Date: ";
        std::cin >> date;
        std::cout << "Description: ";
        std::cin >> description;
        std::cout << "Amount: ";
        std::cin >> amount;

        std::ofstream transactionFile ("transaction.txt", std::ios::app);

        transactionFile << date << "  " << description << "  " << amount;

        transactionFile.close();

        std::cout << "Transaction has been added!" << std::endl;
        
    }

void sales() {
    int a;
        
        std::cout << "            Select an Option Below          " << std::endl;
        std::cout << "                                            " << std::endl;
        std::cout << "              1. View Sales" << std::endl;
        std::cout << "              2. Edit Sales" << std::endl;
        std::cout << "Select Your Option: ";
        std::cin >> a;

        switch (a) {
        case 1:
            viewSales();
            break;

        case 2:
            editSales();
            break;

        default:
            system("cls");
            std::cout << "\t\t\t Please select from the options given above \n" << std::endl;

        }

}

    void viewSales() {
        std::ifstream salesFile("sales.txt");

        if(salesFile.is_open()) {
            std::string sal;

            while(getline(salesFile, sal)) {
                std::cout << sal << "\n";
            }

            salesFile.close();
        }
    }

    void editSales() {
        int u;

        std::cout << "            Select an Option Below          " << std::endl;
        std::cout << "                                            " << std::endl;
        std::cout << "              1. Add sale" << std::endl;
        std::cout << "              2. Remove sale" << std::endl;
        std::cout << "Select Your Option: ";
        std::cin >> u;

        switch(u) {
            case 1:
                addSale();
                break;

            case 2:
                removeSale();
                break;

            default:
                system("cls");
                std::cout << "\t\t\t Please select from the options given above \n" << std::endl;

        }

    }

        void addSale() {
            std::string date, itemNumber, soldForPrice, shippingCost, repairCost;

            std::cout << "Please enter item specifics below: " << std::endl;

            std::cout << "Date: ";
            std::cin >> date;
            std::cout << "Item Number: ";
            std::cin >> itemNumber;
            std::cout << "Sold For Price: ";
            std::cin >> soldForPrice;
            std::cout << "Shipping Cost: ";
            std::cin >> shippingCost;
            std::cout << "Repair Cost: ";
            std::cin >> repairCost;

           std::ofstream salesFile("sales.txt", std::ios::app);

            salesFile << date << "  " << itemNumber << "  " << soldForPrice << "  " << shippingCost << "  " << repairCost << std::endl;

            salesFile.close();

            std::cout << "Sale has been added!" << std::endl;

        }
        //Going to be problems
        void removeSale() {
            

        }




