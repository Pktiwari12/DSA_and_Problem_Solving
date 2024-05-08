// Program to implement the all basic operation of Deque
// in Deque , We use the circular array cocept
class Deque{
    // declaring the member or field of deque class
    private int front;
    private int rear;
    private int deque[];
    private int size;
    // constructor for initialize the user's size array
    public Deque(int size){
        this.size = size;
        this.deque = new int[this.size];
        rear = -1;
        front = -1;
    }
    public void enqueueFront(int data){
        //checking deque is full or not
        if((front == 0 && rear == size-1) || (front == rear+1) )
        {
            System.out.println("Deque is full");
        }
        // checking deque is empty or not
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            deque[front] = data;
        }
        // checking front corner point for insertion which is 0
        else if(front == 0){
            front = size - 1;
            deque[front] = data;
        }
        else{
            front--;
            deque[front] = data;
        }
    }
    public void enqueueRear(int data){
        // checking full condition
        if((front == 0 && rear == size-1) || (front == rear+1)){
            System.out.println("The Deque is full");
        }
        // checking empty condition
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            deque[rear] = data;

        }
        // checking the corner point of rear for insertion which is n-1
        else if(rear == size-1){
            rear = 0;
            deque[rear] = data;
        }
        else{
            rear++;
            deque[rear] = data;
        }
    }
    public void display(){
         
       if(front == -1 && rear == -1 ){
        System.out.println("The Deque is empty.");
       }
       else{
        int i;  //counter variable
        i = front;
        while(i != rear){
            System.out.print(""+deque[i]);
            System.out.print("\t");
            // circulatiory condition
            i = (i+1)%size;
        }
        System.out.println(""+deque[rear]);
       }
    }
    // method for deleting the data items
    public int dequeueRear(){
        int del_item = -1;
        // check empty condition
        if(front == -1 && rear == -1){
            System.out.println("The deque is underflow with return value -1");
            del_item = -1;

        }
        // when Deque has only one data item
        else if(front == rear){
            del_item = deque[rear];
            front = -1;
            rear = -1;
        }
        // checking corner point of rear for deleting
        else if(rear == 0){
            del_item = deque[rear];
            rear = size-1;
        }
        else{
            del_item = deque[rear];
            rear--;
        }
        return del_item;
    }
    public int dequeueFront(){
        int del_item = -1;
        if(front == -1 && rear == -1){
            System.out.println("The Deque is underflow and this method ends with return value -1");
            del_item = -1;
        }
        else if(front == rear){
            del_item = deque[front];
            front = -1;
            rear = -1;
        }
        // check corner point of front for deleting data which is n-1
        else if(front == size-1){
            del_item = deque[front];
            front = 0;
        }
        else{
            del_item = deque[front];
            front++;
        }
        return del_item;
    }
    public int frontItem(){
        int return_front = -1;
        if(front == -1 && rear == -1){
            return_front = -1;
            System.out.println("The DeQue is empty. the method ends with return value -1");
        }
        else{
            return_front = deque[front];
        }
        return return_front;
    }
    public int rearItem(){
        int return_rear = -1;
        if(front == -1 && rear == -1){
            return_rear = -1;
            System.out.println("The DeQue is empty. the method ends with return value -1");
        }
        else{
            return_rear = deque[rear];
        }
        return return_rear;
    }


}
// driver class
public class DequeUsingArray{
    public static void main(String args []){
        Deque d = new Deque(5);
        d.enqueueFront(55);
        d.enqueueFront(32);
        d.enqueueFront(8);
        d.enqueueFront(34);
        d.enqueueFront(45);
        d.display();
        System.out.println("The front element of Deque is :-   "+d.frontItem());
        System.out.println("The rear element of Deque :-\t "+d.rearItem());
        System.out.println("After deleting data from rear side :-    "+d.dequeueRear());
        d.display();
        System.out.println("After deleting data from front side :-    "+d.dequeueFront());
        d.display();
        System.out.println("After deleting data from rear side :-    "+d.dequeueRear());
        d.display();
        System.out.println("After deleting data from rear side :-    "+d.dequeueRear());
        d.display();
        System.out.println("After deleting data from front side :-    "+d.dequeueFront());
        d.display();
        

        


    }
}