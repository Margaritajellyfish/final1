#include<iostream>
#include<deque>
#include<list>
#include<vector>
#include<string>
#include<ctime>

using namespace std;

struct CoffeeCus{
    string name;
    string order;
    CoffeeCus *next;
};
static const string names[] = {"Alice", "Bob", "Charlie", "Diana", "Ethan", "Fiona", "George", "Hannah"};
static const string cOrders[] = {"Latte", "Cappuccino", "Espresso", "Americano", "Mocha"};
static const string mOrders[] = {"Blueberry muffin", "Chocolate chip muffin", "Banana nut muffin"};

class Cqueue{
private:
    CoffeeCus* head;
    CoffeeCus* tail;
public:
    Cqueue() : head(nullptr), tail(nullptr) {}

    ~Cqueue() {
        while (head != nullptr) {
            CoffeeCus* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
