import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

// Java program to demonstrate various operations in binary search tree
class BinarySearchTree {

    class Node {
        int key;
        Node left, right;

        public Node(int item) {
            key = item;
            left = right = null;
        }
    }

    // Root of BST
    private Node root;

    // Constructor
    BinarySearchTree() {
        root = null;
    }

    void insert(int key) {
        root = insertRec(root, key);
    }

    /* A recursive function to insert a new key in BST */
    Node insertRec(Node current, int key) {
 
        if (current == null) {
            current = new Node(key);
            return current;
        }
 
        if (key < current.key) {
            current.left = insertRec(current.left, key);
        }
        else if (key > current.key)
            current.right = insertRec(current.right, key);
 
        return current;
    }

    void inorder()  {
        inorderRec(root);
    }

    void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.println(root.key);
            inorderRec(root.right);
        }
    }

    void BFS() {

        Queue<Node> nodeQueue = new LinkedList<>();
        nodeQueue.add(root);

        while (nodeQueue.peek()!=null){

            Node current = nodeQueue.poll();
            System.out.println(current.key);

            nodeQueue.add(current.left);
            nodeQueue.add(current.right);
        }
    }

    void DFS() {

        Stack<Node> nodeStack = new Stack<>();
        nodeStack.push(root);

        while (!(nodeStack.empty())){

            Node current = nodeStack.pop();
            System.out.println(current.key);

            if(current.right!=null) {
                nodeStack.push(current.right);
            }
            if(current.left!=null) {
                nodeStack.push(current.left);
            }
        }
    }

    boolean isTreeBST() {
        return isTreeBFTRecur(root, 0, (int) (1e9));
    }

    private boolean isTreeBFTRecur(Node node, int min, int max){

        if(node==null){
            return true;
        }

        if(node.key<min || node.key>max){
            return false;
        }

        isTreeBFTRecur(node.left, min, node.key);
        isTreeBFTRecur(node.right, node.key, max);

        return true;
    }

    // Driver Program to test above functions
    public static void main(String[] args) {
        BinarySearchTree tree = new BinarySearchTree();
 
        /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
        tree.insert(50);
        tree.insert(30);
        tree.insert(20);
        tree.insert(40);
        tree.insert(70);
        tree.insert(60);
        tree.insert(80);

        // print inorder traversal of the BST
        System.out.println("------------------------------inorder traversal------------------------------");
        tree.inorder();

        System.out.println("------------------------------BFS------------------------------");
        tree.BFS();

        System.out.println("------------------------------DFS------------------------------");
        tree.DFS();

        System.out.println("------------------------------isTreeBST------------------------------");
        System.out.println(tree.isTreeBST());

    }
}