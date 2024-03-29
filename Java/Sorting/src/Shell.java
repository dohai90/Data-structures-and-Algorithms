
public class Shell {

	public static void sort(Comparable[] a) {
		int N = a.length;
		int h = 1;
		while(h<N/3) h = 3*h + 1;
		while(h>=1) {
			for(int i=h; i<N; i++)
				for(int j=i; j>=h && less(a[j], a[j-h]); j-=h)
					exch(a,j, j-h);
			
			h/=3;
		}
	}
	
	private static void exch(Comparable[] a, int i, int j) {
		Comparable t = a[i];
		a[i] = a[j];
		a[j] = t;
	}
	
	private static boolean less(Comparable v, Comparable w) {
		return v.compareTo(w)<0;
	}
	
	private static boolean isSorted(Comparable[] a) {
		for(int i=1; i<a.length; i++)
			if(less(a[i], a[i-1])) return false;
		return true;
	}
	
	private static void show(Comparable[] a) {
		for(int i=0; i<a.length; i++)
			System.out.print(a[i] + " ");
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
