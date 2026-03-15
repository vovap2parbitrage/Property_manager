#include <iostream>
#include <string>
#include "list.h"

class cryptoToken {
    private:
    std::string name;
    unsigned int price;

    public:
    cryptoToken(std::string n , unsigned int p) : name(n) , price(p) {}

    unsigned long long operator+(const cryptoToken& other) {return price + other.price; }
    friend std::ostream& operator<<(std::ostream& os , const cryptoToken& token) {
        os << token.name << ": $" << token.price;
        return os;
    }
};

template <typename T>
void printList(const list<T>& l) {
    if(l.getSize() == 0) {
        std::cout << "Empty list\n";
        return;
    }

    for(auto it = l.begin() ; it != l.end() ; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

int main() {
    list<int> l;

    std::cout << "--- Phase 1: Push & Pop Mechanics ---\n";
    l.push_back(10);
    l.push_back(20);
    l.push_front(5);
    printList(l); 
    
    std::cout << "Peek Front: " << l.peek_front() << " | Peek Back: " << l.peek_back() << "\n";

    l.pop_back();
    l.pop_front();
    std::cout << "List after pop_front and pop_back\n";
    printList(l);

    std::cout << "\n--- Phase 2: Middle Insertion & Indexing ---\n";
    l.push_back(30);
    l.push_back(40);
    printList(l);
    
    l.insert(1, 99);
    printList(l);
    
    std::cout << "Value at index 2 using operator[]: " << l[2] << "\n";

    std::cout << "\n--- Phase 3: Deep Copy Constructor ---\n";
    list<int> copiedList = l;
    printList(copiedList);
    
    copiedList.push_back(777);
    printList(l);
    printList(copiedList);

    std::cout << "\n--- Phase 4: Custom Classes & Templates (Condition 1.c) ---\n";
    list<cryptoToken> portfolio;
    cryptoToken btc("Bitcoin", 80000);
    cryptoToken eth("Ethereum", 2050);
    cryptoToken sol("Solana", 90);

    portfolio.push_back(btc);
    portfolio.push_back(eth);
    portfolio.insert(1, sol);
    printList(portfolio);

    std::cout << "Testing overloaded operator+ (BTC + ETH): $" << portfolio[0] + portfolio[2] << "\n";

    return 0;
}