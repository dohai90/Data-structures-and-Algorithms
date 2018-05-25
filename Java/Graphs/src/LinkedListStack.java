import java.util.Iterator;

public class LinkedListStack<Item> implements Iterable<Item>{ 

	private Node first;
	private int N;
	
	private class Node{
		private Item item;
		private Node next;
		
		public Node(Item item, Node next) {
			this.item = item;
			this.next = next;
		}		
	}
	
	public void push(Item item) {
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

	}

	@Override
	public Iterator<Item> iterator() {
		// TODO Auto-generated method stub
		return new StackIterator();
	}
	
	private class StackIterator implements Iterator<Item>{

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
