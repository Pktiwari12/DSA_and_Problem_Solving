class Queue{
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
    public Queue()
    {
         this.front = null;
         this.rear = null;
    }
    // second constructor which is taking integer type data
public Queue(int data){
    Node new_node = new Node(data);
    this.front = new_node;
    this.rear = new_node;

}
    public void enqueue(int data)
    {
        Node new_node = new Node(data);
        if(front == null && rear == null){
            front = new_node;
            rear = new_node;

        }
        else{
            rear.next = new_node;
            rear = new_node;

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
            while(temp != null){
                System.out.print(""+temp.data);
                System.out.print("\t");
                temp = temp.next;
            }
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
public class QueueUsingLinkedList {
    public static void main(String[] args) {
        Queue q = new Queue(45);
        q.enqueue(98);
        q.display();
        System.out.println("The top element is  :- "+q.peek());
        int del_data = q.dequeue();
        q.display();
        System.out.println("The top element is :- "+q.peek());

    }
    
}
