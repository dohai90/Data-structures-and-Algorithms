import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class ConnectedComponents {
	
	private boolean[] marked;		// traveled vertices
	private int[] id;				// component identifier of each vertex
	private int count;
	
	public ConnectedComponents(Graph G) {
		marked = new boolean[G.V()];
		id = new int[G.V()];
		for(int s=0; s<G.V(); s++) {
			if(!marked[s]) {
				dfs(G, s);
				count++;
			}
		}
	}
	
	private void dfs(Graph G, int v) {
		marked[v] = true;
		id[v] = count;
		for(int w:G.adj(v)) {
			if(!marked[w])
				dfs(G, w);
		}
	}
	
	public boolean isConnected(int v, int w) {
		return id[v] == id[w];
	}
	
	public int count() {
		return count;	// return number of connected components
	}
	
	public int id(int v) {
		return id[v];	// return id of vertex v
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File f = new File("tinyG.txt");
		try {
			Scanner scanner = new Scanner(f);
			Graph G = new Graph(scanner);
			ConnectedComponents CC = new ConnectedComponents(G);
			int M = CC.count(); 	// number of connected commponents
			LinkedListBag<Integer>[] components = new LinkedListBag[M];
			for(int i=0; i<M; i++) {
				components[i] = new LinkedListBag<Integer>();
			}
			for(int v=0; v<G.V(); v++) {
				components[CC.id(v)].add(v);
			}
			
			System.out.println(M + " connected components!");
			for(int i=0; i<M; i++) {
				System.out.print(i + ": ");
				for(int w:components[i]){
					System.out.print(w + " ");
				}
				System.out.println();
			}
		}catch(IOException e) {
			e.printStackTrace();
		}
	}

}
