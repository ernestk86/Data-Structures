public class Stack {
    int arr[];
    int top;
    
    public Stack(int size){
        arr = new int[size];
        top = -1;
    }
    
    public void push(int d) {
        arr[++top] = d;
    }
    
    public int pop() {
        return arr[--top + 1];
    }
    
    public int peek() {
        return arr[top];
    }
    
    public boolean isEmpty() {
        if(top < 0) return true;
        
        return false;
    }
    
    public static void main(String args[]) {
        Stack myStack = new Stack(6);

        System.out.println("Should be true: " + myStack.isEmpty());
      
        myStack.push(4);
        myStack.push(7);
        myStack.push(33);
        
        System.out.println("Should be false: " + myStack.isEmpty());
        System.out.println("Should be 33: " + myStack.pop());
        System.out.println("Should be 7: " + myStack.peek());
        System.out.println("Should still be 7: " + myStack.pop());
        System.out.println("Should be 4: " + myStack.pop());
        
        System.out.println("Should be true: " + myStack.isEmpty());
    }
}