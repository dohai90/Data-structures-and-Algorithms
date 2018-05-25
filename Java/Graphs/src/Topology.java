import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class Topology {

	private DCycle cyclefinder;
	private DFOder dfo;
	private Iterable<Integer> order;
	
	public Topology(DGraph G) {
		cyclefinder = new DCycle(G);
		if(!cyclefinder.hasCycle()) {
			dfo = new DFOder(G);
			order = dfo.reservepost();
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
			Topology top = new Topology(G);
			if(top.isDAG()) {
				for(int i:top.order())
					System.out.print(i + " ");
			}
		}catch(IOException e) {
			e.printStackTrace();
		}
	}

}
