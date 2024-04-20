//Program to implement the stack using Linked list
// blue print of Stack data structure
class Stack{
    // blue print of node of ll because we using linked list
    public class Node{
        int data;
        Node next;
        // constructor of node with inserting user_data into 'data part of node' and null into next
        public Node(int data)
        {
            this.data = data;
            this.next = null;
        }

    }
    // declare the top reference variable of custom data types or node class
    Node top;
    // constructor of stack without recieving the data. creating empty stack
    public Stack()
    {
        top = null;
    }
    // constructer of stack with recieving the data. creating stack with single data
    public Stack(int data)
    {
        Node new_node = new Node(data);
        top = new_node;
    }
    // function defination of to insert data into stack
    // here we use the concept of 'insert_at_beg'
    // Time complexity id O(1)
    public void push(int data)
    {
        Node new_node = new Node(data);
        new_node.next = top;
        top = new_node;

    }
    // we need to traverse 
    // time complexity is O(n)
    public void display()
    {
        Node temp = this.top;
        while(temp != null)
        {
            System.out.print(""+temp.data);
            System.out.print("\t");
            temp = temp.next;
        }  
    }
    // concept delete_at_beg
    // time complexity is O(1)
    // I am not sufficien knowledge to say anything about free memory in java
    public void pop()
    {
        // try{
        //     if(this.top == null)
        //     {
        //         throw new MyException("The Stack is underflow.")
        //     }
        //     Node temp = top;
        //     top = top.next; 
        // }
        if(top == null)
        {
            return;
        }
        // stack has only single node which to be deleted
        else if(top.next == null)
        {
            top = null;
            return;
        }
        else{
            top = top.next;
            return;
        }




    }
    public int peek()
{
    try{
        if(top == null ){
            throw new MyException("Exception due to Empty Stack with return value is zero.");
        }
        else{
        return(top.data);
        }

    }catch(MyException e){
        System.out.println(e.getMessage());
        return 0;
    }
}
public boolean isEmpty()
{
    if(top == null){
        return true;
    }
    else{
        return false;
    }

}

}

public class StackUsingLL{
    public static void main(String[] args) {
        Stack s1 = new Stack();
        System.out.println("Stack is Empty:"+s1.isEmpty());
        s1.push(34);
        s1.push(67);
        System.out.println("The data items of stack is :");
        s1.display();
        System.out.println("The top element of stack :"+s1.peek());
        System.out.println();
        s1.pop();
        System.out.println("After deleting the data from stack:");
       
        s1.display();
        System.out.println("The top element of stack :"+s1.peek());
        System.out.println("Stack is Empty:"+s1.isEmpty());
    }

}
 class MyException extends Exception{
     MyException(String s)
     {
         super(s);
     }
 }