import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class DepthFirstPaths {

	private boolean[] marked;
	private int[] edgeTo;
	private final int s;
	
	public DepthFirstPaths(Graph G, int s) {
		marked = new boolean[G.V()];
		edgeTo = new int[G.V()];
		this.s = s;
		dfs(G, s);
	}
	
	private void dfs(Graph G, int v) {
		marked[v] = true;
		for(int w:G.adj(v)) {
			if(!marked[w]) {
				edgeTo[w] = v;
				dfs(G, w);
			}
		}
	}
	
	public boolean hasPathTo(int v) {
		return marked[v];
	}
	
	public Iterable<Integer> pathTo(int v) {
		if(!hasPathTo(v)) return null;
		LinkedListBag<Integer> path = new LinkedListBag<Integer>();
		for(int x=v; x!=s; x=edgeTo[x]) {
			path.add(x);
		}
		path.add(s);
		return path;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File f = new File("tinyG.txt");
		try {
			Scanner scanner = new Scanner(f);
			Graph G = new Graph(scanner);
			int source = 0;
			DepthFirstPaths dfpath = new DepthFirstPaths(G, source);
			for(int v=0; v<G.V(); v++) {
				if(dfpath.hasPathTo(v)) {
					System.out.print(source + " to " + v + ":");	
					for(int x:dfpath.pathTo(v)) {
						if(x == source) System.out.print(x);
						else System.out.print("-" + x);					
					}
					System.out.println();
				}				
			}
			scanner.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}

}
