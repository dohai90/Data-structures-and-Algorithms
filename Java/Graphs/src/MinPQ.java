import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class MinPQ<Key extends Comparable<Key>> {

	private Key[] pq;	// heap order priority queue
	private int N;		// number of entries in pq
	
	public MinPQ(int maxN) {
		pq = (Key[]) new Comparable[maxN+1];
	}
	
	public void insert(Key key) {
		if(N == pq.length-1) resize(2*pq.length);
		pq[++N] = key;
		swim(N);
	}
	
	public Key delMin() {
		if(isEmpty()) return null;
		Key key = pq[1];
		exch(1, N--);
		pq[N+1] = null;
		sink(1);
		return key;
	}
	
	public boolean isEmpty() {
		return N == 0;
	}
	
	public int size() {
		return N;
	}
	
	private boolean greater(int i, int j) {
		return pq[i].compareTo(pq[j]) > 0;
	}
	
	private void exch(int i, int j) {
		Key t = pq[i];
		pq[i] = pq[j];
		pq[j] = t;
	}
	
	private void resize(int newcap) {
		Key[] t = (Key[]) new Comparable[newcap];
		for(int i=0; i<=N; i++) {
			t[i] = pq[i];
		}
		pq = t;
	}	
	
	private void swim(int k) {
		while(k>1 && greater(k/2, k)) {
			exch(k/2, k);
			k = k/2;
		}
	}
	
	private void sink(int k) {
		while(2*k <= N) {
			int j = 2*k;
			if(j<N && greater(j, j+1)) j++;
			if(!greater(k, j)) break;
			exch(k, j);
			k = j;
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File f = new File("tinyBatch.txt");
		try {
			Scanner scanner = new Scanner(f);			
			int M = 5;
			MinPQ<Double> minpq = new MinPQ(M);
			
			while(scanner.hasNext()) {
				scanner.next();
				scanner.next();
				double transaction = scanner.nextDouble();
				minpq.insert(transaction);
				if(minpq.size()>M) minpq.delMin();				
			}
			
			LinkedListStack<Double> stack = new LinkedListStack<Double>();
			for(int i=1; i<=M; i++) {
				stack.push(minpq.delMin());				
			}
			
			for(double d : stack) {
				System.out.println(d);
			}
			
		}catch(IOException e) {
			e.printStackTrace();
		}
	}

}
