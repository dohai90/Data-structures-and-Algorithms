import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Graph {

	private int V; 		// Number of Vertices
	private int E; 		// Number of Edges
	private LinkedListBag<Integer>[] adj;
	
	public Graph(int V) {
		this.V = V;
		this.E = 0;
		adj = (LinkedListBag<Integer>[]) new LinkedListBag[V];
		for(int i=0; i<V; i++) {
			adj[i] = new LinkedListBag<Integer>();
		}
	}
	
	public Graph(Scanner s) {		
		this(s.nextInt());		
		int E = s.nextInt();		
		
		for(int i=0; i<E; i++) {			
			int v = s.nextInt();					
			int w = s.nextInt();				
			addEdge(v, w);			
		}		
	}
	
	public int V() {
		return V;	// Number of Vertices
	}
	
	public int E() {
		return E;	//Number of Edges
	}
	
	public Iterable<Integer> adj(int v){
		return adj[v];
	}
	
	public void addEdge(int v, int w) {
		// TODO Auto-generated method stub
		adj[v].add(w);
		adj[w].add(v);
		E++;
	}
	
	public String toString() {
		String s = V + " vertices, " + E + " edges\n";
		for(int i=0; i<V; i++) {
			s += i + ": ";
 			for(Integer adjacent: adj[i]) {
				s += adjacent + " ";
			}
			s += "\n";
		}
		
		return s;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File f = new File("tinyG.txt");
		Graph G;
		try {
			Scanner s = new Scanner(f);
			G = new Graph(s);
			System.out.print(G);
		}catch(IOException e) {
			e.printStackTrace();
		}	
	}
}
