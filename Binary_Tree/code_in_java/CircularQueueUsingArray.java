//import CreationUsingQueue.Node;
// this create an Exception
 public class CircularQueueUsingArray{
    // declaration of container Queue fields like size and array
    private int size;
    private Node cir_queue[];
    private int front;
    private int rear;
    public CircularQueueUsingArray(int size)
    {
        // the size of Queue
        this.size = size;
         this.cir_queue = new Node[this.size];
         front = -1;
         rear = -1;
        
        
    }
   
    void enqueue(Node n){
        try{
            if(this.size <= 0){
                throw new  ArrayIndexOutOfBoundsException("You entered invaild size of Array");
            }
            else if(this.rear == -1 && this.front == -1){
                this.rear++;
                this.front++;
                cir_queue[rear] = n;
            }
            else if((this.rear+1)%this.size == this.front){
                System.out.println("The Queue is overflow.");
            }
            else{
                this.rear = (this.rear+1)%this.size;
                cir_queue[rear] = n;
            }
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println(""+e.getMessage());
           
        }
        
    }    

    public Node dequeue(){
        Node returnValue;
        if(front == -1 && rear == -1){
            System.out.println("The Queue is under flow.");
            return null;
        }
        else if(front == rear){
            returnValue=cir_queue[front];
            front = -1;
            rear = -1;
            return returnValue;
        }
        else{
             returnValue = cir_queue[front];
            //System.out.println("the deleted item is =  "+cir_queue[front]);
            front = (front+1)%this.size;
            return returnValue;
        }
    }
    public void display(){
        if(front == -1 && rear == -1 /*&& this.size <= 0*/){
            System.out.println("The Queue is empty.");

        }
        else{
            // the display condition vary . but I follow this condition
            int i = front;
            while(i != rear ){
                // Loop with this condition will print only n-1 data items
                System.out.print(""+cir_queue[i].data);
                System.out.print("\t");
                i = (i+1)%this.size;
            }
            // this print function for printint the last data item
            System.out.print(""+cir_queue[rear].data);
        }
    }
    // Peek method gives us the reference of the top data
    Node peek(){
        Node returnvalue;
        if(front == -1 && rear == -1){
            System.out.println("the Circular Queue is empty with return value -1");
            returnvalue = null;
        }
        else{
            returnvalue = cir_queue[front];
        }
        return returnvalue;
    }
    boolean isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        }
        else{
            return false;
        }
    }
}
// public class CircularQueueUsingArray2{
//     public static void main(String[] args) {
//         Node n = new Node(3);;
//         CircularQueueUsingArray cq = new CircularQueueUsingArray(5);
//         System.out.println(n);
//          cq.enqueue(n);
//         // cq.enqueue( 69);
//         // cq.enqueue(17);
//         // cq.enqueue(0);
//         // System.out.println("the top element of Queue\t:-"+cq.peek());
//         // System.out.println("The data items of Queue area/t:");
//         // cq.display();
//         // System.out.println();
//         // System.out.println("After the deleleting data items :-");
//         // cq.dequeue();
//          cq.dequeue();
//        cq.display();
//        System.out.println("Queue is empty "+cq.isEmpty());
        
//     }
// }