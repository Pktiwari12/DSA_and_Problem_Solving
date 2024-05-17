import java.util.Scanner;
public class BinaryTreeCreation{
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
    // the root of binary tree
    public  Node root;
    public BinaryTreeCreation(){
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
        System.out.println("For left child of "+newData);
        newNode.left = create();
        System.out.println("For right child of "+newData);
        newNode.right = create();
        return newNode;

        

    }

}
// public class CreationBinaryTree{
//     public static void main(String[] args) {
//         Creation obj = new Creation();
//         obj.create();
        
//     }
// }