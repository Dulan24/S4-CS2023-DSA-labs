#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

class Stack {
    private:
        Node* top;
    public:
        Stack() { top = NULL; }
        void push(int x);
        int pop();
        bool isEmpty();
        void display();
};

void Stack::push(int x) {
    Node* temp = new Node();
    if(temp == NULL) {
        cout << "Stack Overflow\n";
        return;
    }
    temp->data = x;
    temp->next = top;
    top = temp;
}

int Stack::pop() {
    if(top == NULL) {
        cout << "Stack Underflow\n";
        return -1;
    }
    int x = top->data;
    Node* temp = top;
    top = top->next;
    delete(temp);
    return x;
}

bool Stack::isEmpty() {
    return (top == NULL);
}

void Stack::display() {
    if(top == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    Node* temp = top;
    cout << "Stack: ";
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Stack s;
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
    return 0;
}
