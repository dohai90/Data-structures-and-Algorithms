
public class MaxPQ<Key extends Comparable<Key>> {
	
	private Key[] pq;	// heap order priority queue
	private int N;		// number of entries in pq
	
	public MaxPQ(int maxN) {
		pq = (Key[]) new Comparable[maxN+1];
	}
	
	public void insert(Key key) {
		if(N == pq.length-1) resize(2*pq.length);
		pq[++N] = key;
		swim(N);		// swim from last position
	}
	
	public Key delMax() {
		if(isEmpty()) return null;
		Key key = pq[1];
		exch(1, N--);
		pq[N+1] = null;
		if(N < pq.length/4) resize(pq.length/2);
		sink(1);
		return key;
	}
	
	public boolean isEmpty() {
		return N == 0;
	}
	
	public int size() {
		return N;
	}
	
	private void resize(int newcap) {
		Key[] t = (Key[]) new Comparable[newcap];
		for(int i=1; i<=N; i++)
			t[i] = pq[i];
		pq = t;
	}
	
	private boolean less(int i, int j) {
		return pq[i].compareTo(pq[j]) < 0;
	}
	
	private void exch(int i, int j) {
		Key t = pq[i];
		pq[i] = pq[j];
		pq[j] = t;
	}
	
	private void swim(int k) {
		while(k>1 && less(k/2, k)) {
			exch(k/2, k);
			k = k/2;
		}			
	}
	
	private void sink(int k) {		
		while(2*k <= N) {
			int j = 2*k;
			if(j<N && less(j, j+1)) j++;
			if(!less(k, j)) break;
			exch(k, j);
			k = j;
		}
		
	}
	
	public void show() {
		for(int i=1; i<=N; i++) {
			System.out.print(i + "-" + pq[i] + " ");
		}
		System.out.println();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MaxPQ<String> mxpq = new MaxPQ<String>(1);
		mxpq.insert("P");		
		mxpq.insert("Q");		
		mxpq.insert("E");
		mxpq.show();
		System.out.println("max key: " + mxpq.delMax());
		
		mxpq.insert("X");
		mxpq.insert("A");
		mxpq.insert("M");
		mxpq.show();
		System.out.println("max key: " + mxpq.delMax());
		
		mxpq.insert("P");
		mxpq.insert("L");
		mxpq.insert("E");
		mxpq.show();
		System.out.println("max key: " + mxpq.delMax());	
		mxpq.show();
	}

}
