
public class SequencialSearchST<Key, Value> {

	private Node first;
	
	private class Node{
		Key key;
		Value val;
		Node next;
		
		public Node(Key key, Value val, Node next) {
			this.key = key;
			this.val = val;
			this.next = next;
		}
	}
	
	public void put(Key key, Value val) {
		for(Node x=first; x!=null; x=x.next) {
			if(key.equals(x.key)) {
				x.val = val;	// Search hit - update value
				return;		
			}
		}
		first = new Node(key, val, first);	// Search miss - insert value
		return;
	}
	
	public Value get(Key key) {
		for(Node x=first; x!=null; x=x.next) {
			if(key.equals(x.key)) return x.val;
		}
		return null;
	}
	
	public void show() {
		for(Node x=first; x!=null; x=x.next)
			System.out.print("|" + x.key + "|" + x.val + "|" + "->");
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String statement = "S E A R C H E X A M P L E";
		String[] words = statement.split(" ");
		SequencialSearchST<String, Integer> ssst = new SequencialSearchST<>();
		for(int i=0; i<words.length; i++) {
			ssst.put(words[i], i);
		}
		
		ssst.show();
	}

}
