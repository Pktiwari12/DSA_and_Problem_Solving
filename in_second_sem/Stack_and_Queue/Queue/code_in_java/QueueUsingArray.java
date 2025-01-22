// Java Program to implement Queue Using Array
// Queue Class contains all operations of Queue
// the draw back of Queue for implement "isFull()" method
class Queue{
    // declaration Queue as Array
    private int queue[];
    int rear = -1 ,front = -1;     // rear for inserting data and front for delete
    public Queue(int n)
    {
         queue = new int[n]; 
    }
    // data is always inserted through the 'rear end'
    public void enqueue(int data){
        if(rear >=queue.length-1){
            System.out.println("Overflow Condition.");
        }
        else if(rear == -1 && front == -1){
            rear++;
            front++;
            queue[rear] = data;
        }
        else{
            rear++;
            queue[rear] = data;
        }

    }
    // data is always deleted from the 'front end'
    public int dequeue(){
        int returnValue;
        if(rear ==  -1 && front == -1){
            System.out.println("The Queue is empty. Underflow condition.");
            returnValue =  -1;
        }
        // when Single data is present in Queue
        else if(rear == front){
            returnValue = queue[front];
            rear = -1;
            front = -1;
        }
        else{
            returnValue = queue[front];
            front++;
        }
        return returnValue;
    }
    public int[] display(){
        int arr[] = new int[rear - front + 1];
        if(rear == -1 && front == -1){
            // for this condition array length is 
            System.out.println("The stack is empty.");
            arr[0] = -1;
        }
        else{
            for(int i = front , j = 0 ; i<=rear && j < arr.length ; i++,j++){
                arr[j] = queue[i];
            }
        }
        
        return arr;
    }
    public int peek(){
        int topdata;
        if(rear == -1 && front == -1){
            System.out.println("The Queue is empty. with retruning value is -1 :");
            topdata = -1;
        }
        else{
            topdata = queue[front];
        }
        return topdata;
    }
}
public class QueueUsingArray{
    public static void main(String args[])
    {
        Queue q = new Queue(5);
        q.enqueue(23);
        System.out.println("The deleted item is  :- "+q.dequeue());
        q.enqueue(25);
        q.enqueue(245);
        q.enqueue(22);
        int queueData[] = q.display();
        for(int i = 0;i<queueData.length ;i++)
        {
            System.out.println(""+queueData[i]);
        }
        System.out.println("The top element of Queue is :-  "+q.peek());
    }

}
