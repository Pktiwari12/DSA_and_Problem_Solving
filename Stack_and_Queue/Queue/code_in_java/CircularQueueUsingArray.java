// this create an Exception
public class CircularQueueUsingArray{
    // declaration of container Queue fields like size and array
    private int size;
    private int cir_queue[];
    private int front=-1;
    private int rear =-1;
    public CircularQueueUsingArray(int size)
    {
        // the size of Queue
        this.size = size;
         this.cir_queue = new int[this.size];
        
        
    }
   
    void enqueue(int data){
        try{
            if(this.size <= 0){
                throw new  ArrayIndexOutOfBoundsException("You entered invaild size of Array");
            }
            else if(this.rear == -1 && this.front == -1){
                this.rear++;
                this.front++;
                cir_queue[rear] = data;
            }
            else if((this.rear+1)%this.size == this.front){
                System.out.println("The Queue is overflow.");
            }
            else{
                this.rear++;
                cir_queue[rear] = data;
            }
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println(""+e.getMessage());
           
        }
    }    

    public void dequeue(){
        if(front == -1 && rear == -1){
            System.out.println("The Queue is under flow.");
        }
        else if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            System.out.println("the deleted item is =  "+cir_queue[front]);
            front = (front+1)%this.size;
        }
    }
    public void display(){
        if(front == -1 && rear == -1 && this.size <= 0){
            System.out.println("The Queue is empty.");

        }
        else{
            // the display condition vary . but I follow this condition
            int i = front;
            while(i != rear ){
                // Loop with this condition will print only n-1 data items
                System.out.print(""+cir_queue[i]);
                System.out.print("\t");
                i = (i+1)%this.size;
            }
            // this print function for printint the last data item
            System.out.print(""+cir_queue[rear]);
        }
    }
    int peek(){
        int returnvalue;
        if(front == -1 && rear == -1){
            System.out.println("the Circular Queue is empty with return value -1");
            returnvalue = -1;
        }
        else{
            returnvalue = cir_queue[front];
        }
        return returnvalue;
    }
}
// public class CircularQueueUsingArray{
//     public static void main(String[] args) {
//         CircularQueue cq = new CircularQueue(5);
//         cq.enqueue(5);
//         cq.enqueue( 69);
//         cq.enqueue(17);
//         cq.enqueue(0);
//         System.out.println("the top element of Queue\t:-"+cq.peek());
//         System.out.println("The data items of Queue area/t:");
//         cq.display();
//         System.out.println();
//         System.out.println("After the deleleting data items :-");
//         cq.dequeue();
//         cq.dequeue();
//         cq.display();
        
//     }
// }