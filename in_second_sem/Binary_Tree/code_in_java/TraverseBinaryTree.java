// this program to traverse the binary tree using all three method using java
// we use the CreationBinaryTree class for creating binary tree
  class BinaryTreeTraverse{
    // fucntion to preorder traversing using Recursion
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
    // level Order Using iteration 
    public void levelOrder(Node root){
        CircularQueueUsingArray cq = new CircularQueueUsingArray(100);  // we should use Queue Using Linked list
        if(root != null){
            System.out.print(root.data+"\t");
            cq.enqueue(root);
        }
        while(! cq.isEmpty())
        {
            // reusing the root pointer which is nothing but temp pointer
            root = cq.dequeue();
            if(root.leftChild != null){
                System.out.print(root.leftChild.data+"\t");
                cq.enqueue(root.leftChild);
            }
            if(root.rightChild != null){
                System.out.print(root.rightChild.data+"\t");
                cq.enqueue(root.rightChild);
            }
        }

    }
}

 public class TraverseBinaryTree {
     public static void main(String[] args) {
         BinaryTreeCreationUsingIteration bt = new BinaryTreeCreationUsingIteration();
         bt.create();
         BinaryTreeTraverse obj = new BinaryTreeTraverse();
         System.out.println("Printing the elements of data using preorder traversing :- ");
         if(bt.root == null){
             System.out.println("The Binary tree is empty.");
         }
         obj.preOrder(bt.root);
         System.out.println();
         System.out.println("Printing the elements using inorder traversing :-");
         obj.inOrder(bt.root);
         System.out.println();
         System.out.println("Printing the elements using postorder traversing :-");
         obj.postOrder(bt.root);
         System.out.println("Printing the element using the level Order traversing.");
         obj.levelOrder(bt.root);
        
        
     }
    
    
 }
