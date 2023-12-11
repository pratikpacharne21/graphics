#include <iostream>
#include <vector>
#include <algorithm>

// Define the Item class
class Item {
public:
    int code;
    std::string name;
    double cost;
    int quantity;

    // Constructor
    Item(int c, const std::string& n, double cst, int qty)
        : code(c), name(n), cost(cst), quantity(qty) {}
};

// Function to display an item
void displayItem(const Item& item) {
    std::cout << "Code: " << item.code << "\tName: " << item.name
              << "\tCost: " << item.cost << "\tQuantity: " << item.quantity << std::endl;
}

// Function to compare items based on their codes for sorting
bool compareItemCode(const Item& a, const Item& b) {
    return a.code < b.code;
}

int main() {
    // Create a vector to store items
    std::vector<Item> items;

    // Add some sample items
    items.emplace_back(101, "ItemA", 10.99, 50);
    items.emplace_back(103, "ItemB", 5.99, 30);
    items.emplace_back(102, "ItemC", 7.49, 40);

    // Display unsorted items
    std::cout << "Items (Unsorted):" << std::endl;
    for (const auto& item : items) {
        displayItem(item);
    }

    // Sort items based on item code
    std::sort(items.begin(), items.end(), compareItemCode);

    // Display sorted items
    std::cout << "\nItems (Sorted by Code):" << std::endl;
    for (const auto& item : items) {
        displayItem(item);
    }

    // Search for an item with a specific code (binary search, requires a sorted range)
    int searchCode = 103;
    auto it = std::lower_bound(items.begin(), items.end(), searchCode, compareItemCode);

    if (it != items.end() && it->code == searchCode) {
        std::cout << "\nItem found:" << std::endl;
        displayItem(*it);
    } else {
        std::cout << "\nItem with code " << searchCode << " not found." << std::endl;
    }

    return 0;
}