#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Product Class
class Product {
    int productId;
    string name;
    double price;

public:
    Product(int productId, string name, double price)
        : productId(productId), name(name), price(price) {}

    string getDetails() const {
        return "Product ID: " + to_string(productId) + ", Name: " + name + ", Price: $" + to_string(price);
    }

    int getProductId() const {
        return productId;
    }

    double getPrice() const {
        return price;
    }
};

// Order Class
class Order {
    int orderId;
    int userId;
    vector<Product> products;  // A list of products in this order
    string status;

public:
    Order(int orderId, int userId)
        : orderId(orderId), userId(userId), status("Pending") {}

    void addProduct(const Product& product) {
        products.push_back(product);
    }

    vector<Product> getProducts() const {
        return products;
    }

    double calculateTotal() const {
        double total = 0;
        for (const Product& product : products) {
            total += product.getPrice();
        }
        return total;
    }
    string getStatus() const {
        return status;
    }
};

// Payment Class
class Payment {
    int paymentId;
    int orderId;
    double amount;
    string paymentDate;

public:
    Payment(int paymentId, int orderId, double amount, string paymentDate)
        : paymentId(paymentId), orderId(orderId), amount(amount), paymentDate(paymentDate) {}

    string getDetails() const {
        return "Payment ID: " + to_string(paymentId) + ", Order ID: " + to_string(orderId) + ", Amount: $" + to_string(amount) + ", Date: " + paymentDate;
    }
};

// User Class
class User {
    int userId;
    string name;
    string email;
    vector<Order> orders;  // A list of orders for the user

public:
    User(int userId, string name, string email)
        : userId(userId), name(name), email(email) {}

    void createOrder(const Order& order) {
        orders.push_back(order);
    }

    vector<Order> viewOrders() const {
        return orders;
    }
};

// Main Function (Example usage)
int main() {
    // Create a User
    User user1(1, "Alice", "alice@example.com");

    // Create Products
    Product product1(101, "Laptop", 999.99);
    Product product2(102, "Phone", 599.99);

    // Create an Order and add products to it
    Order order1(1001, 1);  // Order for user with ID 1
    order1.addProduct(product1);
    order1.addProduct(product2);

    // User places the order
    user1.createOrder(order1);

    // Create Payment for the order
    Payment payment1(5001, 1001, order1.calculateTotal(), "2024-10-16");

    // View Order and Payment Details
    cout << "Order Status: " << order1.getStatus() << endl;
    cout << "Total Order Amount: $" << order1.calculateTotal() << endl;
    cout << payment1.getDetails() << endl;

    return 0;
}
