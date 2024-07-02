// Implementation of Queue Using two stack
// for enqueue :- time complexity is O(1)
// for dequeue :- time complexity is O(n)
// we use Array
class Queue{
    // the size of Queue
    int size;
    int count = 0;  // counting the nodes and for loop;
    int stack1[] , stack2[];
    public Queue(int size)
    {
        this.size = size;
        this.stack1 = new int[this.size];
        this.stack2 = new int[this.size];
    }
    class Stack1{
        int top1 = -1;
        //int stack1[];
        // public Stack1(){
        //     stack1 = new int[size];
        // }
        public boolean push1(int data){
            boolean check = false;
            try{
                if(size <= 0){
                    throw new ArrayIndexOutOfBoundsException("invalid size of array");
                }
                else if(top1 == size-1){
                    check = false;
                }
                else{
                    top1++;
                    stack1[top1] = data;
                    check = true;
                }
            }catch(ArrayIndexOutOfBoundsException e){
                System.out.println(""+e.getMessage());
            }
            return check;
        }
        public int pop1(){
            int return_value = -1;
            if(top1 == -1){
                System.out.println("The Queue/Stack is underflow with return value -1");
                return_value = -1;
            }
            else{
                return_value = stack1[top1];
                top1--;
            }
            return return_value;
        }
        public boolean display(){
            boolean check = false;
            if(top1 == -1){
                check = false;
            }
            else{
                int i;
                for(i = 0 ; i <=top1 ; i++){
                    System.out.print(""+stack1[i]);
                    System.out.print("\t");
                }
                check = true;
            }
            return check;
            
        }

    }

    class Stack2{
        int top2 = -1;
        // int stack2[];
        // public Stack2()
        // {
        //     stack2 = new int[size];
        // } 
        public void push2(int data){
         try{
            if(size <= 0){
                throw new ArrayIndexOutOfBoundsException("Invaild size of array");
            }
            else if(top2 == size-1){
                System.out.println("overflow");
            }
            else{
                top2++;
                stack2[top2] = data; 
            }
         }catch(ArrayIndexOutOfBoundsException e){

         }
        }
        public int pop2(){
            int return_value;
            if(top2 == -1 && size <= 0){
                System.out.println("The Queue/Stack is underflow with return value -1");
                return_value = -1;
            }
            else{
                return_value = stack2[top2];
                top2--;
            }
            return return_value;
        }

        
    }

            // creating objects of both stack
            Stack1 s1 = new Stack1();
            Stack2 s2 = new Stack2();
            public void enqueue(int data)
            {
                // here only one condition will remain because my return type boolean 
                boolean check = s1.push1(data);
                if(check){
                   count++;
                }
                else{
                    System.out.println("The Queue is overflow.");
                }
               
            }
            public int dequeue(){
                  // underflow condition is defined in pop2
                  int i; // counter varible
                  int del_data = -1;
                 if(count != 0){
                    for(i =0 ; i<count ; i++){
                        int item = s1.pop1();
                        s2.push2(item);
    
                    }
                     del_data = s2.pop2();
                     count--;
                     if(count != 0){
                        for(i =0 ; i<count ; i++){
                            int item = s2.pop2();
                            s1.push1(item);
        
                        }
                     }
                 }
                 else{
                    System.out.println("The Queue is underflow with return value is -1");
                 }
                 return del_data;
            }
            public void display(){
                if(!s1.display()){
                    System.out.println("The Queue is empty.");
                }
                
            }
            
}
public class QueueUsingStack {
    public static void main(String[] args) {
        Queue q = new Queue(5);
        q.enqueue(4);
        q.enqueue(8);
        q.enqueue(45);
        q.enqueue(23);
        q.enqueue(1);
        //q.enqueue(43);
        System.out.println("The data items of Queue :-");
        q.display();
        System.out.println();
        System.out.println("After deleting the data items "+q.dequeue());
        System.out.println("The data items of Queue is :-");
        q.display();
        System.out.println("After deleting the data items "+q.dequeue());
        System.out.println("After deleting the data items "+q.dequeue());
        System.out.println("After deleting the data items "+q.dequeue());
        System.out.println("After deleting the data items "+q.dequeue());
        System.out.println("After deleting the data items "+q.dequeue());
        q.display();
        
    }
    
}
