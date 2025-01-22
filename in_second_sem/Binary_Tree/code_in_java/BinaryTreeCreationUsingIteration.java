// this program is not working properly for strict binary tree
import java.util.Scanner;
public class BinaryTreeCreationUsingIteration{
    // binary tree member variable which is root
    Node root;
    public BinaryTreeCreationUsingIteration(){
        this.root = null;
    }
   // Method to create the binary tree
    public Node create(){
        // first node is created using user input
        int x;  // for data
        this.root = null;
        Node currentPtr,temp;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the root element of binary tree");
         x = sc.nextInt();
         
        // we will take Queue Using Linked List
        // but now we take size 100
        CircularQueueUsingArray cq = new CircularQueueUsingArray(100);
        if(x!= -1){
            currentPtr = new Node(x);
            this.root = currentPtr;
            cq.enqueue(currentPtr);

        }
        else{
            return this.root;
        }
        // if Queue is empty then returns true otherwise false
        // here a small mistake and whole woule be like correct
        while(! cq.isEmpty()){
             currentPtr = cq.dequeue();
            System.out.println("Enter the leftChild child of "+currentPtr.data);
            x = sc.nextInt();
            if(x != -1){
                temp = new Node(x);
                cq.enqueue(temp);
                currentPtr.leftChild = temp;
            }
            // for rightChild child
            System.out.println("Enter the rightChild child of "+currentPtr.data);
            x = sc.nextInt();
            if(x != -1){
                temp = new Node(x);
                cq.enqueue(temp);
                currentPtr.rightChild = temp;
            }
        }
        return this.root;


    }
   
}
// public class CreationBinaryTreeUsingIteration {
//     public static void main(String[] args) {
//         System.out.println("This Program is not working properly for strict binary tree."+
//         "\nproblem in size of cir_queue, so\n solution is take queue Using linked list,so for instance we take size 100.");
//         BinaryTree bt = new BinaryTree();
//        Node root =  bt.create();
//        BinaryTreeTraverse tr = new BinaryTreeTraverse();
//        tr.inOrder(root);
       
       
//     }
    
// }
