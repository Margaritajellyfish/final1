#include<iostream>
#include<deque>
#include<list>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>

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
    void serveCustomer(CoffeeCus*& head, CoffeeCus*& tail) {
    if (head == nullptr) {
        return;
    }
    cout << "Serving " << head->name << " " << head->order << ".\n";
    CoffeeCus* temp = head;
    head = head->next;
    if (head == nullptr) { 
        tail = nullptr;
    }
    delete temp; 
    
    }
};

struct Cus {
    string name;
    string order;
};

class Mqueue {
private:
    deque<Cus> dq;
public:
    void enter(const string &name, const string &order) {
        dq.push_back(Cus{name, order});
    }

    bool serveCustomer() {
        if (dq.empty()) {
            return;
        }
        cout << "Serving " << dq.front().name << " " << dq.front().order << ".\n";
        dq.pop_front();
        return true;
    }

    void print() const {
        cout << "[Muffin Booth Queue]: ";
        if (dq.empty()) {
            cout << "(empty)";
        } else {
            for (auto &cust : dq) {
                cout << cust.name << "(" << cust.order << ") ";
            }
        }
        cout << "\n";
    }

template <size_t N>
string randoms(string(&arr)[N]) {
    return arr[rand() % N];
}
bool chance(){
    srand(time(0));
    int value = rand() % 100 + 1;
    return value > 50;
}

int main(){
    Cqueue coffeeBooth;
    for (int i = 0; i < 3; i++) {
        coffeeBooth.enter(
            randoms(names),
            randoms(cOrders)
        );
    }
    for (int round = 1; round <= 10; round++) {
        cout << "=== Round " << round << " ===\n";
        coffeeBooth.serveCustomer();
        if (chance()) {
            coffeeBooth.enter(randoms(names), randoms(cOrders));
            cout << "A new customer joined.\n";
        }
        coffeeBooth.print();
        cout << "\n";
    }


    return 0;
}
