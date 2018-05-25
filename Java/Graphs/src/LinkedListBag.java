import java.util.Iterator;

public class LinkedListBag<Item> implements Iterable<Item>{
	private Node first;
	private int N;
	
	private class Node {
		Item item;
		Node next;
	}
	
	public void add(Item item) {
		Node oldfirst = first;
		first = new Node();
		first.item = item;
		first.next = oldfirst;
		N++;
	}
	
	public boolean isEmpty() {
		return N == 0;
	}
	
	public int size() {
		return N;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String statement = "H e l l o , W o r l d !";
		String[] words = statement.split(" ");
		LinkedListBag<String> llb = new LinkedListBag<String>();
		for(String w:words)
			llb.add(w);
		
		for(String w:llb)
			System.out.print(w);
	}

	@Override
	public Iterator<Item> iterator() {
		// TODO Auto-generated method stub
		return new BagIterator();
	}
	
	private class BagIterator implements Iterator<Item>{

		private Node current = first;
		
		@Override
		public boolean hasNext() {
			// TODO Auto-generated method stub
			return current != null;
		}

		@Override
		public Item next() {
			// TODO Auto-generated method stub
			Item item = current.item;
			current = current.next;
			return item;
		}
		
	}

}
