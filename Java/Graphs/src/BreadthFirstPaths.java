import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class BreadthFirstPaths {
	
	private boolean[] marked;	//traveled vertices
	private int[] edgeTo;	// last vertex on the known path to this vertex
	private final int s;	// source
	
	public BreadthFirstPaths(Graph G, int s) {
		this.marked = new boolean[G.V()];
		this.edgeTo = new int[G.V()];
		this.s = s;
		bfs(G, s);
	}
	
	private void bfs(Graph G, int s) {		
		LinkedListQueue<Integer> queue = new LinkedListQueue<Integer>();
		marked[s] = true;
		queue.enqueue(s);
		while(!queue.isEmpty()) {
			int v = queue.dequeue();
			for(int w : G.adj(v)) {
				if(!marked[w]) {
					edgeTo[w] = v;
					marked[w] = true;
					queue.enqueue(w);
				}
			}
		}
	}
	
	public boolean hasPathTo(int v) {
		return marked[v];
	}
	
	public Iterable<Integer> pathTo(int v) {
		if(!hasPathTo(v)) return null;
		LinkedListBag<Integer> path = new LinkedListBag<Integer>();
		for(int x=v; x!=s; x=edgeTo[x])
			path.add(x);
		path.add(s);
		return path;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File f = new File("mediumG.txt");
		try {
			Scanner scanner = new Scanner(f);			
			Graph G = new Graph(scanner);
			int source = 0;
			BreadthFirstPaths path = new BreadthFirstPaths(G, source);
			
			for(int v=0; v<G.V(); v++) {
				if(!path.hasPathTo(v)) continue;
				System.out.print(source + " to " + v + ": ");
				for(int x : path.pathTo(v)) {
					if(x == source) System.out.print(x);
					else System.out.print("-" + x);
				}
				System.out.println();
			}
			scanner.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
		
	}

}
