
public class MDFOder {

	private boolean[] marked;
	private LinkedListQueue<Integer> pre;
	private LinkedListQueue<Integer> post;
	private LinkedListStack<Integer> postreverse;
	
	public MDFOder(DGraph G) {
		marked = new boolean[G.V()];
		pre = new LinkedListQueue<>();
		post = new LinkedListQueue<>();
		postreverse = new LinkedListStack<>();
		for(int s=0; s<G.V(); s++) {
			if(!marked[s]) dfs(G, s);
		}
		
	}
	
	private void dfs(DGraph G, int v) {
		pre.enqueue(v);
		marked[v] = true;
		
		for(int w:G.adj(v)) {
			if(!marked[w]) dfs(G, w);
		}
		post.enqueue(v);
		postreverse.push(v);
	}
	
	public Iterable<Integer> pre(){
		return pre;
	}
	
	public Iterable<Integer> post(){
		return post;
	}
	
	public Iterable<Integer> postreverse(){
		return postreverse;
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
