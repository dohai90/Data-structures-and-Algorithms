
public class Merge {
	
	private static Comparable[] aux;
	public static void sort(Comparable[] a) {
		aux = new Comparable[a.length];
		sort(a, 0, a.length-1);
	}

	private static void sort(Comparable[] a, int lo, int hi) {
		if(lo >= hi) return;
		int mid = lo + (hi-lo) / 2;
		sort(a, lo, mid);	// Sort left half
		sort(a, mid+1, hi);	// Sort right half
		merge(a, lo, mid, hi);		// Merge the result
	}
	
	public static void merge(Comparable[] a, int lo, int mid, int hi) {
		// Merge a[lo...mid] with a[mid+1...hi]
		int i = lo;
		int j = mid+1;
		for(int k=lo; k<=hi; k++) {
			aux[k] = a[k];	// Copy a[lo...hi] to aux[lo...hi]
		}
		for(int k=lo; k<=hi; k++) {
			if(i>mid) 						a[k] = aux[j++];	// Move result back to a[lo...hi]
			else if(j>hi) 					a[k] = aux[i++];
			else if(less(aux[j], aux[i])) 	a[k] = aux[j++];
			else 							a[k] = aux[i++];
		}		
	}
	
	public static boolean less(Comparable v, Comparable w) {
		return v.compareTo(w) < 0;
	}
	
	public static boolean isSorted(Comparable[] a) {
		for(int i=1; i<a.length; i++) {
			if(less(a[i], a[i-1])) return false;
		}
		return true;
	}
	
	public static void show(Comparable[] a) {
		for(int i=0; i<a.length; i++) {
			System.out.print(a[i] + " ");
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String statement = "S O R T E X A M P L E";
		String[] words = statement.split(" ");
		sort(words);
		assert isSorted(words);
		show(words);
	}

}
