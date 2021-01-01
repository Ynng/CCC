import java.io.*;
import java.util.*;

public class afk {
	static boolean ispossible(int length, int width, int newy, int newx, String map[][], boolean visited[][]) {
		if (newy < width && newy >= 0 && newx < length && newx >=0 && (!visited[newy][newx])) {
			if (!map[newy][newx].equals("X")) {
				return true;
			} 
		}
		return false;
	}
	static void worthornot(String map[][], int length, int width, int startx, int starty, int finishx, int finishy, boolean[][] visited, int[][] distance) {
		int dx[] = {-1, 1, 0, 0}; 
    int dy[] = { 0, 0, -1, 1};  
        
		LinkedList<Integer> queue = new LinkedList<Integer>();
		
		queue.add(starty);
		queue.add(startx);
		
		while (!queue.isEmpty()) {
			int y = queue.remove(0);
			int x = queue.remove(0);
			if (x == finishx && y == finishy) {
        if(distance[finishy][finishx]>=60)
          System.out.println("#notworth");
        else 
		      System.out.println(distance[finishy][finishx]);
				return; 
			}
      for (int i = 0; i<4; i++) {
        int newy = y + dy[i];
        int newx = x + dx[i];
        if (ispossible(length, width, newy, newx, map, visited)) {
          visited[newy][newx] = true;
          queue.add(newy);
          queue.add(newx);
          distance[newy][newx] = distance[y][x] + 1;
          if (distance[newy][newx] > 60) {
            System.out.println("#notworth");
            return;
          }
        }
			}
		}
		System.out.println("#notworth");
		return;
  }
  //CQ
  //QO
	public static void main(String[] args)throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testcases= Integer.parseInt(br.readLine());
		int finishy = 0;
		int starty = 0;
		int startx = 0; 
		int finishx = 0;
		int startcount = 0;
		int finishcount = 0;
		
		for (int i = 0; i < testcases; i++) {
			String lengthwidth[] = br.readLine().split(" ");
			int length = Integer.parseInt(lengthwidth[0]);
			int width = Integer.parseInt(lengthwidth[1]);
			String map[][] = new String[width][length];
			boolean visit[][] = new boolean[width][length];
			int distance[][] = new int[width][length];
			
			for (int j = 0; j < width; j ++) {
				String line = br.readLine();
				for (int g = 0; g < length; g++) {
					map[j][g] = String.valueOf(line.charAt(g));
					distance[j][g] = 0;
					visit[j][g] = false;
					if (map[j][g].equals("C")) {
						starty = j;
						startx = g;	
						startcount += 1;
					}
					if (map[j][g].equals("W")) {
						finishy = j;
						finishx = g;
						finishcount += 1;
					}
				}
			}
			if (startcount == 0 || finishcount == 0) {
				System.out.println("#notworth");
				break;
      }
      visit[starty][startx] = true;
			worthornot(map, length, width, startx, starty, finishx, finishy, visit, distance);
		}
	}
}