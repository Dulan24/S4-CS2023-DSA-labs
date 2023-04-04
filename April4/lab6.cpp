#include <stdio.h>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <stack>

using namespace std;
#define size 100

class myStack{
    private:
    int top;
    int arr[size];

    public:
    myStack(){
        top = -1;
    }
    void push(int x);
    int pop();
    bool isempty();
    bool isfull();
    int stacktop();
    void display();
};

void myStack::push(int x){
    if(top<size){
        arr[++top] = x;
    }
}

int myStack::pop(){
    if (top>=0){
        int x = arr[top--];
        return x;
    }
    
}

bool myStack::isempty() {
    return (top<0);
}

bool myStack::isfull(){
    return (top+1>=size);
}

int myStack::stacktop(){
    int x = arr[top];
    return x;
}

void myStack::display(){
    int n=top;
    cout<<"\n";
    for(int i=0; i<=top+1; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    clock_t start, end;
    start = clock();

    myStack s;
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

    end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken in array operation %.6f s\n", time_spent);

}
