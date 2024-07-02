// Creation of Binary Tree Using Recursion
import java.util.Scanner;
class BinaryTreeCreationUsingRecursion{
    // public static class Node{
    //     int data;
    //     Node leftChild;
    //     Node rightChild;
    //     public Node(int data){
    //         this.data = data;
    //         this.leftChild = null;
    //         this.rightChild = null;
    //     }
    // }
    // the root of binary tree
    public  Node root;
    public BinaryTreeCreationUsingRecursion(){
        this.root = null;
    }
    public Node create(){
        Scanner sc = new Scanner(System.in);
        Node newNode;
        System.out.println("Enter the data otherwise enter -1 to stop inputting in the binary tree.");
        int newData = sc.nextInt();
        if(newData == -1){
            return null;
        }
        newNode = new Node(newData);
        if(this.root == null){
            this.root = newNode;
        }
        System.out.println("For leftChild child of "+newData);
        newNode.leftChild = create();
        System.out.println("For rightChild child of "+newData);
        newNode.rightChild = create();
        return newNode;

        

    }

}
public class CreationBinaryTree{
    public static void main(String[] args) {
        BinaryTreeCreationUsingRecursion obj = new BinaryTreeCreationUsingRecursion();
        Node root = obj.create();
        BinaryTreeTraverse tr = new BinaryTreeTraverse();
        tr.inOrder(root);
        tr.preOrder(root);
        
    }
}