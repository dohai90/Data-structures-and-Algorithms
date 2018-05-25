
public class BinarySearchST<Key extends Comparable<Key>, Value> {

	private Key[] keys;
	private Value[] vals;
	private int N;
	
	public BinarySearchST(int max) {
		keys = (Key[]) new Comparable[max];
		vals = (Value[]) new Object[max];
	}
	
	public int size() {
		return N;
	}
	
	public boolean isEmpty() {
		return N == 0;
	}
	
	private int rank(Key key, int lo, int hi) {
		if(hi < lo) return lo;
		int mid = lo + (hi - lo) / 2;
		int cmp = key.compareTo(keys[mid]);
		if(cmp<0) return rank(key, lo, mid - 1);
		else if(cmp>0) return rank(key, mid + 1, hi);
		else return mid;
	}
	
	private void resize(int newsize) {
		Key[] t1 = (Key[]) new Comparable[newsize];
		Value[] t2 = (Value[]) new Object[newsize];
		
		for(int i=0; i<N; i++) {
			t1[i] = keys[i];
			t2[i] = vals[i];
		}
		
		keys = t1;
		vals = t2;
	}
	
	public void put(Key key, Value val) {
		if(N == keys.length) resize(2*keys.length);
		int i = rank(key, 0, N - 1);
		if(i<N && key.compareTo(keys[i])==0) {
			vals[i] = val;
		}else {
			for(int j=N; j>i; j--) {
				keys[j] = keys[j-1];
				vals[j] = vals[j-1];
			}
			keys[i] = key;
			vals[i] = val;
			N++;
		}
	}
	
	public Value get(Key key) {
		if(isEmpty()) return null;
		int i = rank(key, 0, N-1);
		if(i<N && key.compareTo(keys[i])==0) 
			return vals[i];
		return null;
	}
		
	public void show() {
		for(int i=0; i<N; i++) {
			System.out.print(keys[i] + " ");
		}
		System.out.println();
		for(int i=0; i<N; i++) {
			System.out.print(vals[i] + " ");
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String statement = "S E A R C H E X A M P L E";
		String[] words = statement.split(" ");
		BinarySearchST<String, Integer> bsst = new BinarySearchST<String, Integer>(1);
		for(int i=0; i<words.length; i++) {
			bsst.put(words[i], i);
		}
		bsst.show();
		
		System.out.print("\n" + bsst.get("E"));
	}

}
