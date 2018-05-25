
public class SequencialSearchST<Key, Value> {

	private Node first;
	private int N;		//number of Node
	
	private class Node{
		private Key key;
		private Value val;
		private Node next;
		
		public Node(Key key, Value val, Node next) {
			this.key = key;
			this.val = val;
			this.next = next;
		}
	}
	
	public int size() {
		return N;
	}
	
	public boolean isEmpty() {
		return N == 0;
	}
	
	
	public void put(Key key, Value val) {
		for(Node x=first; x!=null; x=x.next) {
			if(x.key.equals(key)) {
				x.val = val;				// search hit
				return;
			}
		}
		first = new Node(key, val, first);	//search miss so creat new Node
		N++;
	}
	
	public Value get(Key key) {
		for(Node x=first; x!=null; x=x.next) {
			if(x.key.equals(key))
				return x.val;		// search hit
		}
		return null;				// search miss
	}
	
	public boolean contains(Key key) {
		for(Node x=first; x!=null; x=x.next) {
			if(x.key.equals(key))
				return true;
		}
		return false;
	}
	
	public Iterable<Key> keys(){
		LinkedListQueue<Key> keys = new LinkedListQueue<>();
		for(Node x=first; x!=null; x=x.next)
			keys.enqueue(x.key);
		return keys;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
