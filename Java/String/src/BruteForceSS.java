
public class BruteForceSS {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String txt = "to be or not to be";
		int found = search(txt, "be");
		if(found == txt.length()) System.out.print("not found");
		else System.out.print("found");

	}
	
	public static int search(String txt, String pat) {
		int i, N = txt.length();
		int j, M = pat.length();
		
		for(i=0, j=0; i<N & j<M; i++) {
			if(txt.charAt(i) == pat.charAt(j)) j++;
			else {
				i -= j;
				j=0;
			}
		}
		if(j == M) return i-M;
		else return N;
	}

}
