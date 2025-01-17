#include <iostream>
#include <string>
using namespace std;


class Stack {
private:
    static const int MAX_SIZE = 100;
    char arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(char x) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack overflow\n";
            return;
        }
        arr[++top] = x;
    }

    char pop() {
        if (isEmpty()) {
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (isEmpty()) {
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};


bool isOpenBracket(char c) {
    return c == '(' || c == '[' || c == '{';
}

bool isCloseBracket(char c) {
    return c == ')' || c == ']' || c == '}';
}

char getMatchingBracket(char c) {
    if (c == ')') return '(';
    if (c == ']') return '[';
    if (c == '}') return '{';
    return '\0';
}

void checkBrackets(const string& str) {
    Stack bracketStack;
    string currentString;

    for (size_t i = 0; i < str.length(); i++) {
        char current = str[i];
        currentString += current;

       
        if (current == ';') {
            if (bracketStack.isEmpty()) {
                cout << "Рядок коректний\n";
            } else {
                cout << "Помилка: незакриті дужки\n";
                cout << "Рядок до помилки: " << currentString << endl;
            }
            return;
        }

        
        if (isOpenBracket(current)) {
            bracketStack.push(current);
            continue;
        }

       
        if (isCloseBracket(current)) {
            if (bracketStack.isEmpty()) {
                cout << "Помилка: зайва закриваюча дужка\n";
                cout << "Рядок до помилки: " << currentString << endl;
                return;
            }

            char lastOpen = bracketStack.peek();
            char expectedOpen = getMatchingBracket(current);

            if (lastOpen != expectedOpen) {
                cout << "Помилка: невідповідність дужок\n";
                cout << "Рядок до помилки: " << currentString << endl;
                return;
            }

            bracketStack.pop();
        }
    }

    
    cout << "wrong input" << endl;
}

int main() {
    cout << "enter input:";
    string input;
    getline(cin, input);

    checkBrackets(input);


}