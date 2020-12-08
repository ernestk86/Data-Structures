#include <iostream>

using std::cout;
using std::endl;

class stack {
    private:
    
    class stackNode {
        public:
        
        int data;
        stackNode * next;
        
        stackNode(int d){
            data = d;
        }
    };

    public:
    
    stackNode * top;
    
    stack(){
        top = nullptr;
    }
    
    void push(int d){
        stackNode * newNode = new stackNode(d);
        if(top != nullptr) newNode->next = top;
        top = newNode;
    }
    
    int pop(){
        stackNode * deleteMe = top;
        top = top->next;
        int result = deleteMe->data;
        deleteMe->next = nullptr;
        delete(deleteMe);
        return result;
    }
    
    int peek(){
        return top->data;
    }
    
    bool isEmpty(){
        if(top == nullptr) return true;
        
        return false;
    }
};

class stackArray {
    public:
    
    int cap, top;
    int data[];
    
    stackArray(int capacity){
        top = -1;
        cap = capacity;
        int data[cap];
    }
    
    void push(int d){
        if(top >= cap) {
            cout << "Stack is full" << endl;
        } else {
            data[++top] = d;
        }
    }
    
    int pop() {
        if(top < 0) {
            cout << "Stack is empty" << endl;
        } else {
            return data[--top + 1];
        }
    }
    
    int peek() {
        if(top < 0) {
            cout << "Stack is empty" << endl;
        } else {
            return data[top];
        }
    }
    
    bool isEmpty() {
        if(top < 0) return true;
        
        return false;
    }
};

int main()
{
    stack myStack;
    
    cout << "Stack is empty? "<< myStack.isEmpty() << endl;
    
    myStack.push(4);
    myStack.push(7);
    myStack.push(33);
    
    cout << "Stack is empty? "<< myStack.isEmpty() << endl;
    cout << "Should be 33: " << myStack.pop() << endl;
    cout << "Should be 7: " << myStack.peek() << endl;
    cout << "Should still be 7: " << myStack.pop() << endl;
    cout << "Stack is empty? "<< myStack.isEmpty() << endl;
    cout << "Should be 4: " << myStack.pop() << endl;
    cout << "Stack is empty? "<< myStack.isEmpty() << endl;
    
    stackArray myStackArray(6);
    cout << "Stack array is empty? "<< myStackArray.isEmpty() << endl;
    
    myStackArray.push(4);
    myStackArray.push(7);
    myStackArray.push(33);
    
    cout << "Stack array is empty? "<< myStackArray.isEmpty() << endl;
    cout << "Should be 33: " << myStackArray.pop() << endl;
    cout << "Should be 7: " << myStackArray.peek() << endl;
    cout << "Should still be 7: " << myStackArray.pop() << endl;
    cout << "Stack array is empty? "<< myStackArray.isEmpty() << endl;
    cout << "Should be 4: " << myStackArray.pop() << endl;
    cout << "Stack array is empty? "<< myStackArray.isEmpty() << endl;

    return 0;
}