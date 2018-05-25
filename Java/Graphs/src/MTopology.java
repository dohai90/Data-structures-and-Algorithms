import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class MTopology {

	private Iterable<Integer> order;
	public MTopology(DGraph G) {
		MDCycle cyclefinder = new MDCycle(G);
		if(!cyclefinder.hasCycle()) {
			MDFOder dfs = new MDFOder(G);
			order = dfs.postreverse();
		}
	}
	
	
	public boolean isDAG() {
		return order != null;
	}
	
	public Iterable<Integer> order(){
		return order;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File f = new File("tinyDAG.txt");
		try {
			Scanner scanner = new Scanner(f);
			DGraph G = new DGraph(scanner);
			MTopology top = new MTopology(G);
			if(top.isDAG()) {
				for(int i:top.order())
					System.out.print(i + " ");
			}
		}catch(IOException e) {
			e.printStackTrace();
		}
	}

}
