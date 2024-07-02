// this program to traverse the binary tree using all three method using java
// we use the CreationBinaryTree class for creating binary tree
 public class BinaryTreeTraverse{
    // fucntion to preorder traversing
    public void preOrder(Node root){
        // Root leftChild rightChild
        if(root == null){
            return;
        }
        System.out.print(root.data+"\t");
        preOrder(root.leftChild);
        preOrder(root.rightChild);
    }
    // function to inorder traversig
    public void inOrder(Node root){
        //  leftChild Root rightChild
        if(root == null){
            return;
        }
        inOrder(root.leftChild);
        System.out.print(root.data+"\t");
        inOrder(root.rightChild);
    }
    // function to postorder traversig
    public void postOrder(Node root){
        //  leftChild  rightChild Root
        if(root == null){
            return;
        }
        
        postOrder(root.leftChild);
        postOrder(root.rightChild);
        System.out.print(root.data+"\t");
    }
}

//  public class TraverseBinaryTree {
//      public static void main(String[] args) {
//          BinaryTreeCreation bt = new BinaryTreeCreation();
//          bt.create();
//          BinaryTreeTraverse obj = new BinaryTreeTraverse();
//          System.out.println("Printing the elements of data using preorder traversing :- ");
//          if(bt.root == null){
//              System.out.println("The Binary tree is empty.");
//          }
//          obj.preOrder(bt.root);
//          System.out.println();
//          System.out.println("Printing the elements using inorder traversing :-");
//          obj.inOrder(bt.root);
//          System.out.println();
//          System.out.println("Printing the elements using postorder traversing :-");
//          obj.postOrder(bt.root);
        
        
//      }
    
    
//  }
