import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class test {

	/*
     * Complete the staircase function below.
     */
    static void staircase(int n) {
        /*
         * Write your code here.
         */
        char[][] stair = new char[n][n];
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=0; j--){	// print stair from right to left
        	//for(int j=0; j<n; j++) {		// print stair from left to right
                count++;
                if(count > i+1) stair[i][j] = ' ';
                else stair[i][j] = '#';
            }
            count = 0;            
        }
        
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                System.out.print(stair[i][j]);
            }
            System.out.println();
        }        

    }

    private static final int n = 6;

    public static void main(String[] args) {   

        //staircase(n);
    	/*
    	double meal_cost = 10.25;
        int tip_percent = 17;
        int tax_percent = 5;
        double total_cost = meal_cost * (1 + (tip_percent/100.0) + (tax_percent/100.0));
        System.out.println("The total meal cost is " + Math.round(total_cost) + " dollars.");
        
        String str = "to be or not to be";
        for(int i=0; i<str.length(); i++) {
        	if(str.charAt(i) == 't') System.out.println("found");
        }
        
    	
    	int arr[][] = {	{-1, -1, 0, -9, -2, -2},
    					{-2, -1, -6, -8, -2, -5},
						{-1, -1, -1, -2, -3, -4},
						{-1, -9, -2, -4, -4, -5},
						{-7, -3, -3, -2, -9, -9},
						{-1, -3, -1, -2, -4, -5}};
        
        int sum = 0;
        int max = Integer.MIN_VALUE;
        for(int blockIdi=0; blockIdi<4; blockIdi++){
            for(int blockIdj=0; blockIdj<4; blockIdj++){
                for(int i=0; i<3; i++){
                    for(int j=0; j<3; j++){
                        int globalIdi = blockIdi + i;
                        int globalIdj = blockIdj + j;
                        if(i==1 && (j == 0 || j == 2)) continue;
                        sum += arr[globalIdi][globalIdj];
                    }
                }
                if(max < sum) max = sum;
                sum = 0;
            }
        }
        
        System.out.println(max);
        
        
    	
    	File f = new File("test.txt");
    	try {
    		Scanner scanner = new Scanner(f);
    		int height = 1;
    		int width = 5;
    		char[][] grid = new char[height][width];
    		for(int i=0; i<height; i++) {
    			grid[i] = scanner.nextLine().toCharArray();
    		}
    		
    		for(int i=0; i<height; i++) {
    			for(int j=0; j<width; j++) {
    				if(grid[i][j] == '0') {
    				    System.out.print(j + " " + i + " ");
    				    int x = j;
    				    boolean flag = false;
    					while(++x<width){
    					    if(grid[i][x] == '0'){
    					        System.out.print(x + " " + i + " ");
    					        flag = true;
    					        break;
    					    }
    					}
    					if(flag == false){
    					    System.out.print("-1 -1 ");
    					}
    					
    					int y = i;
    				    flag = false;
    					while(++y<height){
    					    if(grid[y][j] == '0'){
    					        System.out.print(j + " " + y + " ");
    					        flag = true;
    					        break;
    					    }
    					}
    					if(flag == false){
    					    System.out.print("-1 -1 ");
    					}
    					System.out.println();
    				}    				
    			}
        	}    		
    	}catch(IOException e) {
    		e.printStackTrace();
    	}
    	
    	
    	int[] a = {1, 3, 6, 9, 10, 22, 25, 39};
    	int key = 30;
    	int id = rank(a, key, 0, a.length-1);
    	System.out.println(id);
    	if(a[id] == key) System.out.println("found");
    	else System.out.println("not found");
    	
    	
    	int n = 6;
    	int[] stocks = {3, 2, 4, 2, 1, 5};
    	int minId = -1;
        int maxLoss = 0;
        int temp = 0;
        int lo = 0; 
        int hi = n-1;
        while(true){
            if(lo>=hi) break;
            minId = minID(stocks, lo, hi);
            System.out.println("minId: "+ minId);
            for(int i=lo; i<minId; i++){
                temp = stocks[i] - stocks[minId];
                if(maxLoss<temp) maxLoss=temp;
            }
            lo = minId + 1;
        }
        
        
        if(maxLoss < 0) maxLoss = 0;
        else if(maxLoss > 0) maxLoss*=-1;
        System.out.println(maxLoss);
    	*/
    	
    	int[] a = {100, 99, 98, 97, 96, 95, 94, 93, 92, 91};
    	int[] b = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    	System.out.println("GCD: " + GCDArr(b));
    	System.out.println("LCM: " + BCNN(a));
    }
    
    
    public static int minID(int[] a, int lo, int hi){
        int minVal = Integer.MAX_VALUE;
        int minId = -1;
        for(int i=lo; i<=hi; i++){
            if(minVal>a[i]){
                minVal = a[i];
                minId = i;
            }
        }
        
        return minId;
    }
    
    private static int rank(int[] a, int key, int lo, int hi) {
    	if(lo > hi) return lo;
    	int mid = lo + (hi - lo) / 2;
    	if(a[mid] < key) return rank(a, key, mid + 1, hi);
    	else if(a[mid] > key) return rank(a, key, lo, mid - 1);
    	else return mid;
    }
    
    static int getTotalX(int[] a, int[] b) {
        /*
         * Write your code here.
         */
        int start = BCNN(a);
        int m = b.length;
        int min = Integer.MAX_VALUE;        
        for(int j=0; j<m; j++){
            if(b[j]<min) min = b[j];
        }
        int stop = min;
        
        int ans = 0;
        while(start<=stop){
            int count = 0;
            for(int j=0; j<m; j++) {
                if(b[j]%start != 0) break;
                else count++;
            }
            if(count == m) {
            	System.out.println("number in between: " + start);
            	ans++;
            }
            
            start++;
        }
        return ans;        
    }
    
    static int BCNN(int[] a){
        int n = a.length;
        int max = Integer.MIN_VALUE;
        for(int i=0; i<n; i++){
            if(a[i]>max) max = a[i];
        }
                
        while(true){
            int count = 0;
            for(int i=0; i<n; i++){
                if(max%a[i] != 0) break;
                else count++;
            }
            if(count == n) return max;
            max++;
        }        
    }
    
    static int GCD(int a, int b) {
    	while(a!=b) {
    		if(a>b) a-=b;
    		else b-=a;
    	}
    	
    	return a;
    }    
    
    static int GCDArr(int[] a) {
    	int res = a[0];
    	for(int i=0; i<a.length; i++) {
    		res = GCD(res, a[i]);
    	}
    	return res;
    }
    
    static int LCM(int a, int b) {
    	if(a==b) return a;
    	else return (a*b) * GCD(a, b);
    }
    
    static int LCMArr(int[] a) {
    	int res = a[0];
    	for(int i=0; i<a.length; i++) {
    		res = LCM(res, a[i]);
    	}
    	return res;
    }
    
    
    
    
}
