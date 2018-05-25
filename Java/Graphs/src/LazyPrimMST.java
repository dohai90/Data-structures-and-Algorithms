import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class LazyPrimMST {	
	
	private boolean[] marked;			// vertices on the mst
	private LinkedListQueue<Edge> mst;	// contains all lowest weighted edges
	private MinPQ<Edge> pq;				// contains crossing (ineligible) edges
	
	public LazyPrimMST(EdgeWeightedGraph G) {
		marked = new boolean[G.V()];
		mst = new LinkedListQueue<Edge>();
		pq = new MinPQ<Edge>(1);
		
		visit(G, 0);
		while(!pq.isEmpty()) {
			Edge e = pq.delMin();
			int v = e.either();
			int w = e.other(v);
			if(marked[v] && marked[w]) continue;
			mst.enqueue(e);
			if(!marked[v]) visit(G, v);
			if(!marked[w]) visit(G, w);
		}
	}
	
	private void visit(EdgeWeightedGraph G, int v) {
		marked[v] = true;
		for(Edge e:G.adj(v)) {
			if(!marked[e.other(v)]) pq.insert(e);
		}
	}
	
	public Iterable<Edge> edges() {
		return mst;
	}
	
	public double weight() {
		double weight = 0;
		for(Edge e:edges())
			weight += e.weight();
		return weight;		
	}
	
	public int size() {
		return mst.size();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File f = new File("tinyEWG.txt");
		try {
			Scanner scanner = new Scanner(f);
			EdgeWeightedGraph G = new EdgeWeightedGraph(scanner);
			LazyPrimMST pMST = new LazyPrimMST(G);
			for(Edge e:pMST.edges()) {
				System.out.println(e);
			}
			System.out.println("MST weight: "+ pMST.weight());		
			System.out.println(G.V() + " vertices and " + pMST.size() + " edges");
			scanner.close();
		}catch(IOException e) {
			e.printStackTrace();
		}
	}

}
