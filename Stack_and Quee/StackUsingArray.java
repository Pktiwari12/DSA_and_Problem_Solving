// Now we revise the this keyword
// In this Stack Class , we print the final result.this should not be done
// in the sence of oops concept
// but for now. we do this 
import java.util.Scanner;
class MyException extends Exception{
    public MyException(String s){
        super(s);
    }

}
// above class in custom exception class
class Stack{
    private int n; // for size of stack
    private int stack[];
    private int top = -1;
    public Stack(int n)     // taking arguement as total size of stack
    {
        this.n = n;
        stack = new int[n];
    }
    public void push(int data)
    {
        if(top >= n-1 )
        {
            System.out.println("the Stack is overflow.");
        }
        else{
            top++;
            stack[top] = data;
        }
    }
    public void  pop()
    {
        if(top == -1)
        {
            System.out.println("Stack is underflow");
            
        }
        else{
            int delData = stack[top];
            top--;
            System.out.println("the deletd item is  \t"+delData);
        }
    }
    public int peek()
    {
        // if stack is empty , then create custom exeption and return value is 0
        try{
            if(top == -1)
            {
                throw new MyException("Exception:  stack is empty.");
            }
            else{
                return stack[top];
                //System.out.println("The top element of stack is =\t"+stack[top]);
            }
        }catch(MyException e){
            System.out.println(e.getMessage()+"with return value 0");
            return 0;
        }
        
    }
    // funcion to display the data of stack
    public void display()
    {
        if(top == -1)
        {
            System.out.println("the stack is empty.");
        }
        else{
            int i;
            for(i=top;i>=0;i--)
            {
                System.out.print("\t"+stack[i]);
            }
            System.out.println();
        }
    }
    public int sizeOfStack()
    {
        // int count = 0; // the counter variable
        // while(count<=top)
        // {
        //     count++;
        // }
        // System.out.println("The size of stack is =\t "+count);
        return (top+1);

    }
    public boolean isFull()
    {
        boolean a;
        if(top == n-1)
        {
            a = true;
            //System.out.println("The stack is full");
            return a; 
        }
        else{
            a = false;
            return a;
            //System.out.println("the stack is not full.");
        }
    }  
    public boolean isEmpty()
    {
        boolean a;
        if(top == -1)
        {
            a = true;
            return a;
            // System.out.println("The stack is empty");
        }
        else{
            a = false;
            return a;
            // System.out.println("the stack is not empty.");
        }
    }
}
public class StackUsingArray{
    public static void main(String[] args) {
        // in the arguement of class is the total size of stack
        Stack s1 = new Stack(5);
        System.out.println("The stack is empty : "+s1.isEmpty());
        s1.isFull();
        System.out.println("The top element of stack is:  "+s1.peek());
        s1.push(6);
        s1.push(7);
        s1.display();
        System.out.println("The stack is empty: "+s1.isEmpty());
        System.out.println("The top element of stack is:  "+s1.peek());
        System.out.println("The size of stack is :"+s1.sizeOfStack());
        s1.pop();
        s1.display();
        System.out.println("The size of stack is :"+s1.sizeOfStack());
        s1.push(23);
        s1.push(23);
        s1.push(23);
        s1.push(23);
        s1.display();
        System.out.println("The size of stack is :"+s1.sizeOfStack());
        System.out.println(" The stack is full:"+s1.isFull());
        System.out.println("The top element of stack is:  "+s1.peek());

    }

}