// this one  program contain all operations 
// in this program , all operations is nothing but which have already discussed in particular file

import java.util.Scanner;

 public class BinaryTree {
    public Node root;
    public BinaryTree(){
        this.root = null;
    }
    // class of node of binary tree
    public static class Node{
        int data;
        Node left;
        Node right;
        public Node(int data){
            this.data = data;
            this.left = null;
            this.right = null;
        }
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
        System.out.println("For left child of "+newData);
        newNode.left = create();
        System.out.println("For right child of "+newData);
        newNode.right = create();
        return newNode;
    }
    public void preOrder(Node root){
        // Root Left Right
        if(root == null){
            return;
        }
        System.out.print(root.data+"\t");
        preOrder(root.left);
        preOrder(root.right);
    }
     // function to inorder traversig
     public void inOrder(Node root){
        //  Left Root Right
        if(root == null){
            return;
        }
        inOrder(root.left);
        System.out.print(root.data+"\t");
        inOrder(root.right);
    }
    // function to postorder traversig
    public void postOrder(Node root){
        //  Left  Right Root
        if(root == null){
            return;
        }
        
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.data+"\t");
    }
    
}
// Driver Code
// public class Main{
//     public static void main(String[] args) {
//         BinaryTree bt = new BinaryTree();
//         bt.create();
//         bt.preOrder(bt.root);
//         System.out.println();
//         bt.inOrder(bt.root);
//         System.out.println();
//         bt.postOrder(bt.root);
//     }
// }
