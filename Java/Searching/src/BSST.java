
public class BSST<Key extends Comparable<Key>, Value> {
	private Key[] keys;
	private Value[] vals;
	private int N;
	
	public BSST(int cap) {
		keys = (Key[]) new Comparable[cap];
		vals = (Value[]) new Object[cap];
	}
	
	public void put(Key key, Value val) {
		int i = rank(key, 0, N-1);
		if(i<N && key.compareTo(keys[i]) == 0) vals[i] = val; // search hit and update val
		else {
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
		if(i<N && key.compareTo(keys[i]) == 0) return vals[i];	//search hit
		else return null;	// search miss
	}
	
	private int rank(Key key, int lo, int hi) {
		if(lo > hi) return lo;
		int mid = lo + (hi - lo) / 2;
		int cmp = key.compareTo(keys[mid]);
		if(cmp < 0) return rank(key, lo, mid - 1);
		else if(cmp > 0) return rank(key, mid + 1, hi);
		else return mid;
	}
	
	public boolean isEmpty() {
		return N == 0;
	}
	
	public void show() {
		for(int i=0; i<N; i++)
			System.out.print(keys[i] + " ");
		System.out.println();
		for(int i=0; i<N; i++)
			System.out.print(vals[i] + " ");
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String statement = "S E A R C H E X A M P L E";
		String[] words = statement.split(" ");
		BSST<String, Integer> bsst = new BSST<String, Integer>(20);
		for(int i=0; i<words.length; i++) {
			bsst.put(words[i], i);
		}
		bsst.show();
		
		System.out.print("\n" + bsst.get("E"));
	}

}
