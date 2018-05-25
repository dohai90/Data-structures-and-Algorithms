
public class Prime {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n =100000000;
		System.out.println("largest prime number near " + n + " is " + largestPrime(n));
			
	}
	
	public static int largestPrime(int n) {
		for(int i=n; i>=1; i--) {
			int count = 0;
			for(int j=i; j>=1; j=j-2) {
				if(i%j == 0) count++;
				if(count > 2) break;
			}				
			if(count == 2) {
				return i;
			}
		}
		return -1;
	}

}
