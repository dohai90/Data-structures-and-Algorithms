import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class DCycle {
	
	private boolean[] marked;
	private int[] edgeTo;
	private boolean[] onStack;
	private LinkedListStack<Integer> cycle;
	
	public DCycle(DGraph G) {
		marked = new boolean[G.V()];
		edgeTo = new int[G.V()];
		onStack = new boolean[G.V()];
		for(int v=0; v<G.V(); v++) {
			if(!marked[v]) dfs(G, v);
		}
	}
	
	private void dfs(DGraph G, int v) {
		marked[v] = true;
		onStack[v] = true;
		for(int w:G.adj(v)) {
			if(hasCycle()) return;
			else if(!marked[w]) {
				edgeTo[w] = v;
				dfs(G, w);
			}else if(onStack[w]) {
				cycle = new LinkedListStack<>();
				for(int x=v; x!=w; x=edgeTo[x])
					cycle.push(x);
				cycle.push(w);
				cycle.push(v);
			}
		}
		onStack[v] = false;
	}
	
	
	public boolean hasCycle() {
		return cycle != null;
	}
	
	public Iterable<Integer> cycle(){
		return cycle;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		File f = new File("tinyDG.txt");
		try {
			Scanner scanner = new Scanner(f);
			DGraph G = new DGraph(scanner);
			DCycle DC = new DCycle(G);
			if(DC.hasCycle())
				for(int x:DC.cycle())
					System.out.print(x + " ");
		}catch(IOException e) {
			e.printStackTrace();
		}
		
	}

}
