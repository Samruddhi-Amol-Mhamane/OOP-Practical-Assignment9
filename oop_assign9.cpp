#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Message {
public:
    string text;

    // Parameterized constructor
    Message(string msg) {
        text = msg;
    }

    // Move constructor
    Message(Message&& obj) {
        text = std::move(obj.text);
        obj.text = "Moved from";
    }

    void display() {
        cout << text << endl;
    }
};

int main() {
    Message m1("Hello, C++");

    cout << "Before moving:" << endl;
    cout << "m1: ";
    m1.display();

    Message m2(std::move(m1));

    cout << "\nAfter moving:" << endl;
    cout << "m1: ";
    m1.display();

    cout << "m2: ";
    m2.display();

    return 0;
}