
public class Quick {

	public static void sort(Comparable[] a, int lo, int hi) {
		if(lo >= hi) return;
		int j = partition(a, lo, hi);
		sort(a, lo, j-1);
		sort(a, j+1, hi);
	}
	
	private static int partition(Comparable[] a, int lo, int hi) {
		// Partition a[lo ... i ... hi]
		int i = lo;
		int j = hi + 1;
		Comparable v = a[i];
		while(true) {
			while(less(a[++i], v)) if(i == hi) break;
			while(less(v, a[--j])) if(j == lo) break;
			if(i >= j) break;
			exch(a, i, j);
		}
		exch(a, lo, j);
		return j;
	}
	
	private static void exch(Comparable[] a, int i, int j) {
		Comparable t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	
	private static boolean less(Comparable v, Comparable w) {
		return v.compareTo(w) < 0;
	}
	
	public static boolean isSorted(Comparable[] a) {
		for(int i=1; i<a.length; i++)
			if(less(a[i], a[i-1])) return false;
		return true;
	}
	
	public static void show(Comparable[] a) {
		for(int i=0; i<a.length; i++)
			System.out.print(a[i] + " ");		
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String statement = "A U I C K S O R T E X A M P L E";
		String[] words = statement.split(" ");
		sort(words, 0, words.length-1);
		assert isSorted(words);
		show(words);
	}

}
