#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class Product {
public:
    string name;
    int stock;

    Product(string name, int stock) : name(name), stock(stock) {}
};

// Function to process incoming sales orders
void process_orders(unordered_map<string, Product>& inventory, const vector<pair<string, int>>& orders, int restock_threshold) {
    for (const auto& order : orders) {
        string product_name = order.first;
        int order_quantity = order.second;

        // Check if the product exists in the inventory
        if (inventory.find(product_name) != inventory.end()) {
            Product& product = inventory[product_name];

            // Check if stock is sufficient
            if (product.stock >= order_quantity) {
                product.stock -= order_quantity; // Reduce stock by order quantity
                cout << "Processed order for " << order_quantity << " units of " << product_name << ". Remaining stock: " << product.stock << endl;

                // Check if stock level is below threshold and trigger restock alert
                if (product.stock < restock_threshold) {
                    cout << "Alert: " << product_name << " stock is below threshold. Please restock." << endl;
                }
            } else {
                cout << "Error: Insufficient stock for " << product_name << ". Available stock: " << product.stock << ", but " << order_quantity << " units ordered." << endl;
            }
        } else {
            cout << "Error: Product " << product_name << " does not exist in the inventory." << endl;
        }
    }
}

// Function to restock items
void restock_items(unordered_map<string, Product>& inventory, const vector<pair<string, int>>& restock_list) {
    for (const auto& item : restock_list) {
        string product_name = item.first;
        int restock_quantity = item.second;

        // Check if the product exists in the inventory
        if (inventory.find(product_name) != inventory.end()) {
            Product& product = inventory[product_name];
            product.stock += restock_quantity; // Increase stock by restock quantity
            cout << "Restocked " << restock_quantity << " units of " << product_name << ". New stock: " << product.stock << endl;
        } else {
            cout << "Error: Product " << product_name << " does not exist in the inventory." << endl;
        }
    }
}

// Main function for example usage
int main() {
    // Initialize the inventory
    unordered_map<string, Product> inventory = {
        {"Laptop", Product("Laptop", 50)},
        {"Phone", Product("Phone", 15)},
        {"Tablet", Product("Tablet", 8)}
    };

    // Incoming orders (product name, quantity ordered)
    vector<pair<string, int>> orders = {
        {"Laptop", 5},
        {"Phone", 10},
        {"Tablet", 5},
        {"Tablet", 4} // This order should trigger a restock alert
    };

    // Process the orders (threshold for restock alert is 10)
    process_orders(inventory, orders, 10);

    // List of items to restock (product name, quantity to restock)
    vector<pair<string, int>> restock_list = {
        {"Tablet", 20},
        {"Phone", 15}
    };

    // Restock the items
    restock_items(inventory, restock_list);

    return 0;
}
