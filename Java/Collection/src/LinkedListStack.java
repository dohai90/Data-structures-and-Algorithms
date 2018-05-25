import java.util.Iterator;

public class LinkedListStack<Item> implements Iterable<Item>{
	
	private Node first;
	private int N;
	
	private class Node{
		Item item;
		Node next;
		
		public Node(Item item, Node next) {
			this.item = item;
			this.next = next;
		}
	}
	
	public void push(Item item) {
		/*
		Node oldfirst = first;
		first = new Node();
		first.item = item;
		first.next = oldfirst;
		*/
		first = new Node(item, first);
		N++;
	}
	
	public Item pop() {
		Item item = first.item;
		first = first.next;
		N--;
		return item;
	}
	
	public boolean isEmpty() {
		return N == 0;
	}
	
	public int size() {
		return N;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String statement = "to be or not to - be - - that - - - is";
		String[] words = statement.split(" ");
		LinkedListStack<String> lls = new LinkedListStack<String>();
		for(String w:words) {
			if(!w.equals("-")) lls.push(w);
			else if(!lls.isEmpty()) System.out.print(lls.pop() + " ");
		}
		System.out.print("\nThe number of remaining items: " + lls.size() + "\n");
		for(String str:lls)
			System.out.print(str + " ");
	}
	
	@Override
	public Iterator<Item> iterator() {
		return new LinkedListIterator();
	}
	
	private class LinkedListIterator implements Iterator<Item>{

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
