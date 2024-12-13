// Product, Iten, Cart
#include<string>
#include<unordered_map>
using namespace std;
// forward declaration
class Item;
class Cart;

class Product{
    int id;
    string name;
    int price;

public:
    Product(){

    }
    Product(int u_id, string name, int price){
        id = u_id;
        this->name = name;
        this->price = price;
    }

    string getDisplayName(){
        return name + " : Rs " + to_string(price) +  "\n";
    }

    string getShortName(){
        return name.substr(0,1);
    }

    friend class Item;
    friend class Cart;
};

class Item{
    Product product;
    int qunatity;

public:
// constructor using intialisation list
    Item(){

    }
    Item(Product p, int q) : product(p), qunatity(q){}

    int getItemPrice(){
        return qunatity * product.price;
    }
    string getitemInfo(){
        return to_string(qunatity) + " x " + product.name + " Rs :  " + to_string(qunatity * product.price) + '\n';
    }

    friend class Cart;

};

class Cart{

    unordered_map<int,Item> items;

public:
    void addProduct(Product product){
        if(items.count(product.id)==0){
            Item newItem(product,1);
            items[product.id] = newItem;
        }
        else{
            items[product.id].qunatity += 1;
        }
    }

    int getTotal(){
        int total=0;
        for(auto itempair : items){
            auto item = itempair.second;
            total += item.getItemPrice();
        }
        return total;
    }

    string viewCart(){
        if(items.empty()){
            return "Your cart is empty.";
        }

        string itemizedList;
        int cart_total = getTotal();

        for(auto itempair : items){
            auto item = itempair.second;
            itemizedList.append(item.getitemInfo());
        }

        return itemizedList + "\nTotal Amount : Rs " + to_string(cart_total) + '\n';

    }

    bool isEmpty(){
        return items.empty();
    }

};