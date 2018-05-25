import java.util.Scanner;

public class SymbolGraph {

	private SequencialSearchST<String, Integer> st;			// String -> Indices
	private String[] keys;									// Indices -> String
	private Graph G;										// Indices Graph
	
	public SymbolGraph(Scanner s1, Scanner s2, String delim) {
		st = new SequencialSearchST<>();
		while(s1.hasNextLine()) {						// Map String key to Indices
			String[] a = s1.nextLine().split(delim);
			for(int i=0; i<a.length; i++) {
				if(!st.contains(a[i])) {
					st.put(a[i], st.size());
				}
			}
		}
		
		keys = new String[st.size()];					// Map back from Indices to String key
		for(String key:st.keys()) {
			keys[st.get(key)] = key;
		}
		
		G = new Graph(st.size());
		while(s2.hasNextLine()) {
			String[] a = s2.nextLine().split(delim);
			int v = st.get(a[0]);
			for(int i=1; i<a.length; i++) {
				int w = st.get(a[i]);
				G.addEdge(v, w);
			}
		}
	}
	
	public Graph G() {
		return G;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
