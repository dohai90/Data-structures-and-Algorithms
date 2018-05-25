
public class DFOder {

	private boolean[] marked;
	private LinkedListQueue<Integer> pre;
	private LinkedListQueue<Integer> post;
	private LinkedListStack<Integer> reversepost;
	
	public DFOder(DGraph G) {
		marked = new boolean[G.V()];
		pre = new LinkedListQueue<Integer>();
		post = new LinkedListQueue<Integer>();
		reversepost = new LinkedListStack<Integer>();
		
		for(int v=0; v<G.V(); v++) {
			if(!marked[v]) dfs(G, v);
		}
	}
	
	private void dfs(DGraph G, int v) {
		pre.enqueue(v);
		marked[v] = true;
		for(int w:G.adj(v)) {
			if(!marked[w]) {
				dfs(G, w);
			}
		}
		post.enqueue(v);
		reversepost.push(v);
	}
	
	public Iterable<Integer> pre(){
		return pre;
	}
	
	public Iterable<Integer> post(){
		return post;
	}
	
	public Iterable<Integer> reservepost(){
		return reversepost;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
