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
    void enter(string &name, string &order) {
        CoffeeCus* newNode = new CoffeeCus{ name, order, nullptr };
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void print() const {
        CoffeeCus* current = head;
        cout << "[Coffee Booth Queue]: ";
        if (current == nullptr) {
            cout << "(empty)";
        }
        while (current != nullptr) {
            cout << current->name << "(" << current->order << ") ";
            current = current->next;
        }
        cout << "\n";
    }

};

int main(){

    return 0;
}
