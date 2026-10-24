# Practical Assignment 9: std::move in `<utility>`

## Student Details
- **Name:** Samruddhi Amol Mhamane
- **PRN:** 202501110050
- **Division:** A
- **Batch:** A2
- **Faculty:** Khushal Khairnar Sir

## Problem Statement
Write a C++ program to demonstrate `std::move()` from the `<utility>` header and understand how a move constructor transfers resources efficiently from one object to another.

## Objectives
- To understand move constructors introduced in C++11.
- To learn the use of `std::move()`.
- To understand lvalue and rvalue references.
- To demonstrate efficient resource transfer between objects.

## Theory
A **move constructor** transfers resources from a source object to a destination object without unnecessary copying.

`std::move()` is defined in the `<utility>` header and is available since C++11. It converts an expression into an rvalue expression, allowing move semantics to be used. The actual resource transfer is performed by the move constructor or move-assignment operator.

## Algorithm
1. Include the required header files.
2. Create a `Message` class with a string data member.
3. Define a parameterized constructor and a move constructor.
4. Create an object `m1` containing `"Hello, C++"`.
5. Use `std::move(m1)` to initialize another object `m2`.
6. Display both objects after moving.

## Technology Used
- **Language:** C++
- **IDE:** Embarcadero Dev-C++ / VS Code
- **Header Files:** `<iostream>`, `<string>`, `<utility>`
- **Standard:** C++11 or later

## Source Code
File: `std_move.cpp`

```cpp
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Message {
public:
    string text;

    Message(string msg) {
        text = msg;
    }

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
```

## Sample Output

```text
Before moving:
m1: Hello, C++

After moving:
m1: Moved from
m2: Hello, C++
```

## Results / Observations
- The program demonstrates `std::move()` and a move constructor.
- The move constructor uses an rvalue reference (`&&`).
- The message is transferred to the destination object `m2`.
- The source object's text is explicitly changed to `"Moved from"`.

## Conclusion
The practical demonstrates how `std::move()` enables move semantics in C++. Move constructors can help avoid unnecessary copying and improve resource efficiency.

## Assignment Questions
1. What is a move constructor?
2. When was the move constructor introduced in C++?
3. What is the purpose of `std::move()`?
4. Which header file contains `std::move()`?
5. What is the difference between `&` and `&&`?

## Repository Contents
- `std_move.cpp` — C++ source code
- `README.md` — Practical description and documentation
- `output.png` — Program output screenshot (optional)
