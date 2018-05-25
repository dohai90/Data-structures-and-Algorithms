
public class LSD {

	
	public static void sort(String[] a, int W) {
		//sort N records of a arrays, each array has W characters.
		int N = a.length;
		int R = 256;
		String[] aux = new String[N];;
		
		
		for(int d = W-1; d>=0; d--) {
			int[] count = new int[R + 1];
			//Compute frequency count
			for(int i=0; i<N; i++) {
				count[a[i].charAt(d) + 1]++;
			}
			
			//Transform count to indices
			for(int r=0; r<R; r++) {
				count[r+1] += count[r];
			}
			
			//Distribute
			for(int i=0; i<N; i++) {
				aux[count[a[i].charAt(d)]++] = a[i];
			}
			
			//Copy back
			for(int i=0; i<N; i++) {
				a[i] = aux[i];
			}
		}
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] a = {	"4PGC938",
						"2IYE230",
						"3CIO720",
						"1ICK750",
						"1OHV845",
						"4JZY524",
						"1ICK750",
						"3CIO720",
						"1OHV845",
						"1OHV845",
						"2RLA629",
						"2RLA629",
						"3ATW723"};
		sort(a, 7);
		for(String s : a) {
			System.out.println(s);
		}
		
		System.out.print(a[1].substring(2));
	}

}
