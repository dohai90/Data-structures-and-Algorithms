import java.io.File;
import java.io.IOException;
import java.util.Scanner;

public class BreadthFirstPathsInMaze {
	
	private boolean[] marked; 
	private int[] edgeTo;
	private final int s;	
	
	public BreadthFirstPathsInMaze(Graph G, int s) {
		marked = new boolean[G.V()];
		edgeTo = new int[G.V()];
		this.s = s;
		bfs(G, s);
	}
	
	private void bfs(Graph G, int s) {
		LinkedListQueue<Integer> q = new LinkedListQueue<Integer>();		
		marked[s] = true;
		q.enqueue(s);
		while(!q.isEmpty()) {
			int v = q.dequeue();
			for(int w:G.adj(v)) {
				if(!marked[w]) {
					marked[w] = true;
					edgeTo[w] = v;
					q.enqueue(w);
				}
			}
		}
	}
	
	public boolean hasPathTo(int v) {
		return marked[v];
	}
	
	public Iterable<Integer> pathTo(int v){
		LinkedListStack<Integer> path = new LinkedListStack<Integer>();
		for(int x=v; x!=s; x=edgeTo[x]) {
			path.push(x);
		}
		path.push(s);
		return path;
	}	
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		File f = new File("test.txt");
		try {
			Scanner scanner = new Scanner(f);
			int height = scanner.nextInt();
			int width = scanner.nextInt();
			int[][] maze = new int[height][width];
			
			for(int i=0; i<height; i++) {
				for(int j=0; j<width; j++) {
					maze[i][j] = scanner.nextInt();					
				}
			}
			scanner.close();			
			
			Maze mazeObj = new Maze(maze, height, width);
			Graph G = mazeObj.G();
			BreadthFirstPathsInMaze path = new BreadthFirstPathsInMaze(G, mazeObj.index(Integer.toString(11)));
			int dest = mazeObj.index(Integer.toString(59));
			if(path.hasPathTo(dest)) {
				for(int x:path.pathTo(dest)) {
					int row = Integer.valueOf(mazeObj.name(x))/width;
					int col = Integer.valueOf(mazeObj.name(x))%width;
					maze[row][col] = 9;
				}
			}
			
			for(int i=0; i<height; i++) {
				for(int j=0; j<width; j++) {
					System.out.print(maze[i][j] + " ");
				}
				System.out.println();
			}			
		}catch(IOException e){
			e.printStackTrace();
		}
	}

}

class Maze{
	private SequencialSearchST<String, Integer> st;
	private String[] keys;
	private Graph G;
	
	public Maze(int[][] maze, int height, int width) {
		st = new SequencialSearchST<>();		// Map Key -> Value
		for(int i=0; i<height; i++) {
			for(int j=0; j<width; j++) {
				if(maze[i][j] == 0) {
					int v = i*width + j;
					st.put(Integer.toString(v), st.size());
				}					
			}
		}
		
		keys = new String[st.size()]; 			// Map back from Value to Key
		for(String name : st.keys()) {
			keys[st.get(name)] = name;
		}
		
		
		G = new Graph(st.size());
		for(int i=0; i<height; i++) {
			for(int j=0; j<width; j++) {
				if(maze[i][j] == 0) {
					int v = i*width + j;
					if(j != width-1) {
						if(maze[i][j+1] == 0) {
							int w = i*width + j + 1;
							G.addEdge(st.get(Integer.toString(v)), st.get(Integer.toString(w)));
						}
					}
					
					if(i != height-1) {
						if(maze[i+1][j] == 0) {
							int w = (i+1)*width + j;
							G.addEdge(st.get(Integer.toString(v)), st.get(Integer.toString(w)));
						}
					}
				}					
			}
		}		
	}
	
	public Graph G() {
		return G;
	}
	
	public int index(String name) {
		return st.get(name);
	}
	
	public String name(int v) {
		return keys[v];
	}
}
