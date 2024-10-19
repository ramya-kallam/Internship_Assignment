Project Overview
This project implements a simplified e-commerce system in C++ using object-oriented principles. The system allows users to manage products, orders, payments, and inventory. Additionally, some SQL queries for analytics are provided to retrieve information on customer purchases, author revenue, and book orders.

Contents
ecommerce.cpp: Implements the basic e-commerce functionality with product listings, order management, and payment details.
stock.cpp: Handles inventory and stock management, allowing for order processing and restocking products.
SQL Queries: Includes example SQL queries to fetch useful data such as top customers, author revenue, and high-demand books.
ecommerce.cpp Explanation
a) Classes:

Product: Represents a product with attributes like productId, name, and price.
Order: Contains order details including the userId, a list of products, and the order status.
Payment: Handles payment information for an order, including paymentId, orderId, amount, and paymentDate.
User: Represents a user with details like userId, name, and a list of orders.

b) Main Flow:
A User is created.
Products are defined and added to an Order.
The user places the order, and the total order amount is calculated.
A Payment is created for the order, and details are displayed to the user.

stock.cpp Explanation
a) Classes:

Product: Used to manage product stock with attributes like name and stock.
Functions:

process_orders: Processes incoming orders, checks inventory, reduces stock, and generates restock alerts if the stock falls below a certain threshold.
restock_items: Restocks products in the inventory and updates the stock levels.

b) Main Flow:
The system initializes an inventory with products.
Incoming sales orders are processed, and alerts are generated if stock falls below a threshold.
The system restocks low-stock products.

How to Run the C++ Code
Requirements: You need a C++ compiler, such as g++, to compile and run the code.

Steps:

Compile the ecommerce.cpp file:
g++ ecommerce.cpp -o ecommerce
Run the executable:
./ecommerce

Similarly, compile and run stock.cpp:
g++ stock.cpp -o stock
./stock

Assumptions:

The product prices and stock quantities are hardcoded for simplicity.
The e-commerce system supports basic functionalities and does not include features like user authentication or advanced error handling.
Inventory management is handled separately in the stock.cpp file.

The system assumes that each order is processed sequentially, and products cannot go "out of stock" mid-order.
Restock alerts are triggered when stock levels fall below a certain threshold (defined in the function call).
Payment date is provided as a string, assuming the system handles date formatting externally.
