import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Graph {

    private LinkedList<Integer>[] arr;
    private int size;

    public Graph(int V){
        size = V;
        arr = new LinkedList[V];

        for(int i=0;i<V;i++){
            arr[i] = new LinkedList<>();
        }
    }

    public void addEdge(int V1, int V2){

        LinkedList<Integer> list = arr[V1];
        list.add(V2);

        list = arr[V2];
        list.add(V1);
    }

    public void BFS(int vertex){

        boolean[] visited = new boolean[size];

        Queue<Integer> queue = new LinkedList<>();
        queue.add(vertex);

        while (queue.peek()!=null){

            int node = queue.poll();
            visited[node]= true;
            System.out.println(node);

            LinkedList<Integer> list = arr[node];

            list.stream().forEach(l->{
                if(visited[l]==false){
                    queue.add(l);
                }
            });
        }
    }

    public void DFS(int vertex){

        boolean[] visited = new boolean[size];

        Stack<Integer> stack = new Stack<>();
        stack.push(vertex);

        while (!stack.isEmpty()){

            int node = stack.pop();
            visited[node]= true;
            System.out.println(node);

            LinkedList<Integer> list = arr[node];

            list.stream().forEach(l->{
                if(visited[l]==false){
                    stack.push(l);
                }
            });
        }
    }

    public static void main(String[] args) {

        /**
        0----3----------2
        |               |
        |               |
        5---6--7        4---1
         */


        Graph graph = new Graph(8);
        graph.addEdge(0,3);
        graph.addEdge(0,5);
        graph.addEdge(3,2);
        graph.addEdge(2,4);
        graph.addEdge(4,1);
        graph.addEdge(5,6);
        graph.addEdge(6,7);

        System.out.println("------------------------BFS---------------------------------");
        graph.BFS(2);
        System.out.println("------------------------DFS---------------------------------");
        graph.DFS(5);

    }
}
