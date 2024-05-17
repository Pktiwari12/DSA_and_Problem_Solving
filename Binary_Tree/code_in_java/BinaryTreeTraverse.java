// this program to traverse the binary tree using all three method using java
// we use the CreationBinaryTree class for creating binary tree
public class BinaryTreeTraverse{
    // fucntion to preorder traversing
    public void preOrder(BinaryTreeCreation.Node root){
        // Root Left Right
        if(root == null){
            return;
        }
        System.out.print(root.data+"\t");
        preOrder(root.left);
        preOrder(root.right);
    }
    // function to inorder traversig
    public void inOrder(BinaryTreeCreation.Node root){
        //  Left Root Right
        if(root == null){
            return;
        }
        inOrder(root.left);
        System.out.print(root.data+"\t");
        inOrder(root.right);
    }
    // function to postorder traversig
    public void postOrder(BinaryTreeCreation.Node root){
        //  Left  Right Root
        if(root == null){
            return;
        }
        
        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.data+"\t");
    }
}

// public class TraverseBinaryTree {
//     public static void main(String[] args) {
//         BinaryTreeCreation bt = new BinaryTreeCreation();
//         bt.create();
//         Traverse obj = new Traverse();
//         System.out.println("Printing the elements of data using preorder traversing :- ");
//         if(bt.root == null){
//             System.out.println("The Binary tree is empty.");
//         }
//         obj.preOrder(bt.root);
//         System.out.println();
//         System.out.println("Printing the elements using inorder traversing :-");
//         obj.inOrder(bt.root);
//         System.out.println();
//         System.out.println("Printing the elements using postorder traversing :-");
//         obj.postOrder(bt.root);
        
        
//     }
    
    
// }
