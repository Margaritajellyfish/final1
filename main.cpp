#include<iostream>
#include<deque>
#include<list>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>
#include<map>

using namespace std;

static const string names[] = {"Alice", "Bob", "Charlie", "Diana", "Ethan", "Fiona", "George", "Hannah",
"Isla", "Jack", "Karen", "Liam", "Mia", "Noah", "Olivia", "Peter",
"Quinn", "Rachel", "Sam", "Tina", "Uma", "Victor", "Wendy", "Xavier",
"Yvonne", "Zack", "Aaron", "Bella", "Cameron", "Daisy", "Elijah", "Faith",
"Gavin", "Hailey", "Ian", "Jasmine", "Kyle", "Lily", "Mason", "Nora",
"Owen", "Piper", "Ryan", "Sophie", "Tyler", "Violet", "Wyatt", "Zoey"};
static const string cOrders[] = {"Latte", "Cappuccino", "Espresso", "Americano", "Mocha"};
static const string mOrders[] = {"Blueberry muffin", "Chocolate chip muffin", "Banana nut muffin"};
static const string bOrders[] = {"Bracelet A", "Bracelet B", "Bracelet C", "Bracelet D"};
static const string pOrders[] = {"Margherita", "Pepperoni", "Hawaiian", "Veggie", "BBQ Chicken"};

template <size_t N>
string randoms(const string(&arr)[N]) {
    return arr[rand() % N];
}
bool chance(){
    int value = rand() % 100 + 1;
    return value > 50;
}

struct CoffeeCus{
    string name;
    string order;
    CoffeeCus *next;
};
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
    void enter(const string &name, const string &order) {
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
    void serveCustomer() {
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

    void serveCustomer() {
        if (dq.empty()) {
            return;
        }
        cout << "Serving " << dq.front().name << " " << dq.front().order << ".\n";
        dq.pop_front();
        return;
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
};
class Bqueue {
private:
    vector<Cus> vec;
public:
    void enter(const string &name, const string &order) {
        vec.push_back(Cus{name, order});
    }

    void serveCustomer() {
        if (vec.empty()) {
            return;
        }
        cout << "Serving " << vec.front().name << " " << vec.front().order << ".\n";
        vec.erase(vec.begin());
        return;
    }

    void print() const {
        cout << "[Bracelet Booth Queue]: ";
        if (vec.empty()) {
            cout << "(empty)";
        } else {
            for (auto &cust : vec) {
                cout << cust.name << "(" << cust.order << ") ";
            }
        }
        cout << "\n";
    }

};

class Pqueue {
private:
    map<int, Cus> mp;
    int count;
public:
    Pqueue() : count(1) {}

    void enter(const string &name, const string &order) {
        mp[count++] = Cus{name, order};
    }
    void serveCustomer() {
        if (mp.empty()) {
            return;
        }
        auto it = mp.begin(); 
        cout << "Serving " << it->second.name << " " << it->second.order << ".\n";
        mp.erase(it);
    }
    void print() const {
        cout << "[Pizza Booth Queue]: ";
        if (mp.empty()) {
            cout << "(empty)";
        } else {    
            for (auto &i : mp) {
                cout << i.second.name << "(" << i.second.order << ") ";
            }
        }
        cout << "\n";
    }
};

int main(){
    srand(static_cast<unsigned>(time(NULL)));

    Cqueue coffeeBooth;
    Mqueue muffinBooth;
    Bqueue braceletBooth;
    Pqueue pizzaBooth;
    for (int i = 0; i < 3; i++) {
        coffeeBooth.enter(randoms(names),randoms(cOrders));
        muffinBooth.enter(randoms(names), randoms(mOrders));
        braceletBooth.enter(randoms(names), randoms(bOrders));
        pizzaBooth.enter(randoms(names), randoms(pOrders));
    }
    for (int round = 1; round <= 10; round++) {
        cout << "=== Round " << round << " ===\n";
        coffeeBooth.serveCustomer();
        muffinBooth.serveCustomer();
        braceletBooth.serveCustomer();
        pizzaBooth.serveCustomer();
        if (chance()) {
            coffeeBooth.enter(randoms(names), randoms(cOrders));
            cout << "A new customer joined coffee queue.\n";
        }
        if (chance()) {
            muffinBooth.enter(randoms(names), randoms(mOrders));
            cout << "A new customer joined muffin queue.\n";
        }
        if (chance()) {
            braceletBooth.enter(randoms(names), randoms(bOrders));
            cout << "A new customer joined bracelate queue.\n";
        }
        if (chance()) {
            pizzaBooth.enter(randoms(names), randoms(pOrders));
            cout << "A new customer joined pizza queue.\n";
        }
        coffeeBooth.print();
        muffinBooth.print();
        braceletBooth.print();
        pizzaBooth.print();
        cout << "\n";
    }


    return 0;
}
