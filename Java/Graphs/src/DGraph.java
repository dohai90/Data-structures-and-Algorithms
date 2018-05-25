import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class DGraph {
	
	private final int V;
	private int E;
	private LinkedListStack<Integer>[] adj;		// an array of adjacent lists
	
	public DGraph(int V) {
		this.V = V;
		this.E =0;
		adj = new LinkedListStack[V];
		for(int v=0; v<V; v++) {
			adj[v] = new LinkedListStack();
		}
	}
	
	public DGraph(Scanner scanner) {
		this(scanner.nextInt());
		int E = scanner.nextInt();
		for(int i=0; i<E; i++) {
			int v = scanner.nextInt();
			int w = scanner.nextInt();
			addEdge(v, w);
		}
	}
	
	public int V() {
		return V;
	}
	
	public int E() {
		return E;
	}
	
	public void addEdge(int v, int w) {
		adj[v].push(w);
		E++;
	}
	
	public Iterable<Integer> adj(int v){
		return adj[v];
	}
	
	public DGraph reverse() {
		DGraph R = new DGraph(V);
		for(int v=0; v<V; v++) {
			for(int w:adj[v])
				R.addEdge(w, v);
		}
		return R;
	}
	
	public String toString() {
		String s = new String();
		for(int v=0; v<V; v++) {
			s += v + " :";
			for(int w:adj[v])
				s += w + " ";
			s += "\n";
		}
		return s;
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File f = new File("tinyDG.txt");
		try {
			Scanner scanner = new Scanner(f);
			DGraph G = new DGraph(scanner);
			System.out.print(G);
		}catch(IOException e) {
			e.printStackTrace();
		}
	}

}
