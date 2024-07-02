// this program contains nothing but just update last node's next null to first node address
// circular linked list
// but queue then "insertion_at_end" and  "deletion_at_beg"

class CircularQueue{
    // two end points of Queue are front and rear
     Node front;
     Node rear;
    public class Node{
        int data;
        Node next;
        public Node(int data)
        {
            this.data = data;
            this.next = null;
        }
    }
    // first constructor which is not taking any data
    public CircularQueue()
    {
         this.front = null;
         this.rear = null;
    }
    // second constructor which is taking integer type data
public CircularQueue(int data){
    Node new_node = new Node(data);
    this.front = new_node;
    this.rear = new_node;
    this.rear.next = this.front;

}
    public void enqueue(int data)
    {
        Node new_node = new Node(data);
        if(front == null && rear == null){
            front = new_node;
            rear = new_node;
            this.rear.next = this.front;

        }
        else{
            rear.next = new_node;
            rear = new_node;
            this.rear.next = this.front;

        }
    }
    public int dequeue(){
        int del_item;
        if(front == null && rear == null){
            System.out.println("The stack is underflow with return value -1");
            del_item = -1;
        }
        else if(front == rear){
            del_item = front.data;
            front = null;
            rear = null;

        }
        else{
            del_item = front.data;
            front = front.next;
            this.rear.next = front;
        }
        return del_item;
    }
    // I am not able to store data of linked list into form of array
    public void display(){
    
        if(front == null && rear == null){
            System.out.println("The Queue is empty.");
         
        }
        else{
            Node temp = front;
            do{
                System.out.print(""+temp.data);
                System.out.print("\t");
                temp = temp.next;
            }while(temp != front);
            System.out.println();
        }
    }
    public int  peek(){
        int top_ele;
        if(front == null || rear == null){
            top_ele = -1;
            System.out.println("The stack is empty.");
        }
        else{
            top_ele = front.data;

        }
        return top_ele;
    }

    
}
public class CircularQueueUsingLL {
    public static void main(String[] args) {
        CircularQueue cq = new CircularQueue();
        cq.display();
        cq.enqueue(5);
        cq.enqueue(45);
        cq.enqueue(34);
        cq.enqueue(4);
        cq.enqueue(9);
        System.out.println("The data items of Circular Queue :-");
        cq.display();
        System.out.println("The top element of Queue :\t"+cq.peek());
        System.out.println("After deleting the item\t"+cq.dequeue());
        System.out.println("After deleting the item\t"+cq.dequeue());
        System.out.println("After deleting the item\t"+cq.dequeue());
        System.out.println("The data items of Circular Queue :-");
        cq.display();
        System.out.println("After adding data items 56 and 89");
        cq.enqueue(56);
        cq.enqueue(89);
        cq.display();
        System.out.println("After deleting ");
        cq.dequeue();
        cq.dequeue();
        cq.dequeue();
        cq.dequeue();
        cq.display();


        
    }
    
}
