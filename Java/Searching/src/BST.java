
public class BST<Key extends Comparable<Key>, Value> {

	private Node root;
	
	private class Node{
		private Key key;
		private Value val;
		private Node left;
		private Node right;
		private int N;			// Number of nodes 
		public Node(Key key, Value val, int N) {
			this.key = key;
			this.val = val;
			this.N = N;
		}
	}
	
	public int size() {
		return size(root);
	}
	
	private int size(Node x) {
		// TODO Auto-generated method stub
		if(x == null ) return 0;
		else return x.N;
	}
	
	public Value get(Key key) {
		return get(root, key);
	}
	
	private Value get(Node x, Key key) {
		// TODO Auto-generated method stub
		if(x == null) return null;
		int cmp = key.compareTo(x.key);
		if(cmp < 0) return get(x.left, key);
		else if(cmp > 0) return get(x.right, key);
		else return x.val;
	}

	public void put(Key key, Value val) {
		root = put(root, key, val);
	}
	
	private Node put(Node x, Key key, Value val) {
		// TODO Auto-generated method stub
		if(x == null) new Node(key, val, 1);
		int cmp = key.compareTo(x.key);
		if(cmp < 0) x.left = put(x.left, key, val);
		else if(cmp > 0) x.right = put(x.right, key, val);
		else x.val = val;
		x.N = size(x.left) + size(x.right) + 1;
		return x;		
	}

	public Key min() {
		return min(root).key;		
	}
	
	private Node min(Node x) {
		if(x.left == null) return x;
		return min(x.left);
	}
	
	public Key max() {
		return max(root).key;
	}
	
	private Node max(Node x) {
		if(x.right == null) return x;
		return max(x.right);
	}	
	
	public Key floor(Key key) {
		Node x = floor(root, key);
		if(x == null) return null;
		return x.key;
	}
	
	private Node floor(Node x, Key key) {
		if(x == null) return null;
		int cmp = key.compareTo(x.key);
		if(cmp == 0) return x;
		if(cmp < 0) return floor(x.left, key);
		Node t = floor(x.right, key);
		if(t != null) return t;
		else return x;
	}
	
	
	public Key ceil(Key key) {
		Node x = ceil(root, key);
		if(x == null) return null;
		return x.key;
	}
	
	private Node ceil(Node x, Key key) {
		if(x == null) return null;
		int cmp = key.compareTo(x.key);
		if(cmp == 0) return x;
		if(cmp > 0) return ceil(x.right, key);
		Node t = ceil(x.left, key);
		if(t != null) return t;
		else return x;
	}
	
	public Key select(int k) {
		return select(root, k).key;
	}
	
	private Node select(Node x, int k) {
		if(x.left == null) return x;
		int t = size(x.left);
		if(t > k) return select(x.left, k);
		else if(t < k) return select(x.right, k-t-1);
		else return x;
	}
	
	public int rank(Key key) {
		return rank(root, key);
	}
	
	private int rank(Node x, Key key) {
		if(x == null) return 0;
		int cmp = key.compareTo(x.key);
		if(cmp < 0) return rank(x.left, key);
		else if(cmp > 0) return 1 + size(x.left) + rank(x.right, key);
		else return size(x.left);
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
	}

}
