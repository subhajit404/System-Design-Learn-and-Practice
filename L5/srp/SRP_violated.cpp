#include <iostream>
#include <vector>
using namespace std;

class Product
{
public:
    string name;
    double price;

    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart
{
private:
    vector<Product *> products;

public:
    void addProducts(Product *p)
    {
        products.push_back(p);
    }

    const vector<Product *> &getProducts()
    {
        return products;
    }

    // calculate total price in the cart
    double claculateTotal()
    {
        double total = 0;
        for (auto p : products)
        {
            total += p->price;
        }
        return total;
    }
    void printInvoice()
    {
        cout << "Shopping cart Invoice :\n";
        for (auto p : products)
        {
            cout << p->name << " - Rs. " << p->price<<endl;
            
        }
        cout << "Total: Rs." << claculateTotal() << endl;
    }
    void saveDatabase()
    {
        cout << "Save Shopping cart to the Database..." << endl;
    }
};

int main()
{
    ShoppingCart* cart = new ShoppingCart();
    cart->addProducts(new Product("Laptop",50000));
    cart->addProducts(new Product("Mouse",3000));
    cart->printInvoice();
    cart->saveDatabase();
}