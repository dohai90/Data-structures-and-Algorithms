
public class MSD {
	
	private static int R = 256;			// Radix
	private static String[] aux;		// auxiliary string
	private static int M = 15;			// cutoff value for small substring sort
	
	private static int charAt(String a, int d) {
		if(d<a.length()) return a.charAt(d);
		else return -1;
	}
	
	public static void sort(String[] a) {
		int N = a.length;
		aux = new String[N];
		sort(a, 0, N-1, 0);
	}
	
	private static void sort(String[] a, int lo, int hi, int d) {
		if(hi<=lo+M) {
			insertionSort(a, lo, hi, d);
			return;
		}
		
		int[] count = new int[R+2];		// Compute frequency counts
		for(int i=lo; i<=hi; i++)
			count[charAt(a[i], d) + 2]++;
		
		for(int r=0; r<R+1; r++)		// Transform count to indices
			count[r+1] += count[r];
		
		for(int i=lo; i<=hi; i++)		// Distribute
			aux[count[charAt(a[i], d) + 1]++] = a[i];
		
		for(int i=lo; i<=hi; i++)		// Copy back
			a[i] = aux[i - lo];
		
		// Recursively sort for each character value
		for(int r=0; r<R; r++)
			sort(a, lo + count[r], lo + count[r+1] - 1, d+1);
	}
	
	private static void insertionSort(String[] a, int lo, int hi, int d) {
		for(int i=lo; i<=hi; i++)
			for(int j=i; j>lo && less(a[j], a[j-1], d); j--)
				exch(a, j, j-1);
	}
	
	private static boolean less(String v, String w, int d) {
		return v.substring(d).compareTo(w.substring(d)) < 0;
	}
	
	private static void exch(String[] a, int i, int j) {
		String t = a[i];
		a[i] = a[j];
		a[j] = t;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] a = {	"she",
						"sells",
						"seashells",
						"by",
						"the",
						"seashore",
						"the",
						"shells",
						"she",
						"sells",
						"are",
						"surely",
						"seashells"};
		
		sort(a);
		for(String x:a)
			System.out.println(x);
	}

}
