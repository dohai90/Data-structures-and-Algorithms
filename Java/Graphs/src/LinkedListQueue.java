import java.util.Iterator;

public class LinkedListQueue<Item> implements Iterable<Item>{
	
	private Node first;
	private Node last;
	private int N;
	
	private class Node{
		private Item item;
		private Node next;		
	}
	
	public void enqueue(Item item) {		
		Node oldlast = last;
		last = new Node();
		last.item = item;
		last.next = null;		
		if(isEmpty()) first = last;
		else oldlast.next = last;
		N++;
	}
	
	public Item dequeue() {
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

	public Iterator<Item> iterator() {
		return new QueueIterator();
	}
	
	private class QueueIterator implements Iterator<Item>{

		private Node current = first;
		
		@Override
		public boolean hasNext() {
			// TODO Auto-generated method stub			
			return current!=null;
		}

		@Override
		public Item next() {
			// TODO Auto-generated method stub
			Item item = current.item;
			current = current.next;
			return item;
		}
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String statement = "to be - - or - not - to be";
		String[] words = statement.split(" ");
		LinkedListQueue<String> llq = new LinkedListQueue<String>();
		for(String w : words) {
			if(!w.equals("-"))  llq.enqueue(w);
			else System.out.print(llq.dequeue() + " ");
		}
		System.out.println();
		if(!llq.isEmpty()) {
			System.out.println("not empty " + llq.size());
			for(String w : llq)
				System.out.print(w + " ");
		}
			
			
	}

}
