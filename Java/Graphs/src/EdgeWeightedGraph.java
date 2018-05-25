import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class EdgeWeightedGraph {

	private final int V;	// number of Vertices
	private int E;
	private LinkedListBag<Edge>[] adj;
	
	public EdgeWeightedGraph(int V) {
		this.V = V;
		this.E = 0;
		adj = new LinkedListBag[V];
		for(int v=0; v<V; v++) {
			adj[v] = new LinkedListBag<Edge>();
		}
	}
	
	public EdgeWeightedGraph(Scanner scanner) {
		this(scanner.nextInt());
		int E = scanner.nextInt();
		
		for(int i=0; i<E; i++) {
			int v = scanner.nextInt();				
			int w = scanner.nextInt();
			double weight = scanner.nextDouble();				
			Edge e = new Edge(v, w, weight);				
			addEdge(e);
		}		
	}
	
	public void addEdge(Edge e) {
		int v = e.either();
		int w = e.other(v);
		adj[v].add(e);
		adj[w].add(e);
		E++;
	}
	
	public Iterable<Edge> adj(int v) {
		return adj[v];
	}
	
	public Iterable<Edge> edges() {
		LinkedListBag<Edge> b = new LinkedListBag<Edge>();
		for(int v=0; v<V; v++) {
			for(Edge e:adj[v])
				if(e.other(v) > v) b.add(e);	// ignore self loop
		}
		return b;		
	}
	
	public int V() {
		return V;		
	}
	
	public int E() {
		return E;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File f = new File("tinyEWG.txt");
		try {
			Scanner scanner = new Scanner(f);
			EdgeWeightedGraph EWG = new EdgeWeightedGraph(scanner);
			for(int v=0; v<EWG.V(); v++) {
				System.out.print(v + ": ");
				for(Edge e:EWG.adj[v])
					System.out.print(e + " ");
				System.out.println();
			}
		}catch(IOException e) {
			e.printStackTrace();
		}
	}

}
