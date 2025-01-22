// Program to count the number of number of nodes in the binary tree
public class Count {
    // function to count the number of total nodes in the binary tree
    int countNodes(Node root){
        int x,y;
        if(root == null){
            return 0;
        }
        x = countNodes(root.leftChild);
        y = countNodes(root.rightChild);
        return x+y+1;

    }
    // function to count the number of leaf nodes
    int countLeafNodes(Node root){
        int x,y;
        if(root == null){
            return 0;
        }
        x = countLeafNodes(root.leftChild);
        y = countLeafNodes(root.rightChild);
        if(root.leftChild == null && root.rightChild == null){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    // function to count the nodes with degree'2'
    int countNodesWithDegreeTwo(Node root){
        int x,y;
        if(root == null){
            return 0 ;
        }
        x = countNodesWithDegreeTwo(root.leftChild);
        y = countNodesWithDegreeTwo(root.rightChild);
        if(root.leftChild != null && root.rightChild != null){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    // function to count the number of nodes with degree 1
    int countNodesWithDegreeOne(Node root){
        int x,y;
        if(root == null){
            return 0 ;
        }
        x = countNodesWithDegreeTwo(root.leftChild);
        y = countNodesWithDegreeTwo(root.rightChild);
        if((root.leftChild != null && root.rightChild == null) || (root.leftChild == null && root.rightChild != null)){
            return x+y+1;
        }
        else{
            return x+y;
        }
    }
    public static void main(String args[]){
        BinaryTreeCreationUsingIteration bt = new BinaryTreeCreationUsingIteration();
        bt.create();
        BinaryTreeTraverse trvs = new BinaryTreeTraverse();
        System.out.println("The binary tree in inorder :");
        trvs.inOrder(bt.root);
        Count obj = new Count();
        System.out.println("The number of nodes in the binary tree = "+obj.countNodes(bt.root));
        System.out.println("The number of leaf nodes = "+obj.countLeafNodes(bt.root));
        System.out.println("The number of nodes with degree 2 = "+obj.countNodesWithDegreeTwo(bt.root));
    }
    
}

