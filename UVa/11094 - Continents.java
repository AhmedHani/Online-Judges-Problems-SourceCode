import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

//import org.eclipse.persistence.internal.sessions.remote.ReplaceValueHoldersIterator;

public class Main {
  public static String Land;
	public static String[] Grid;
	public static char[][] Map;
	public static int Row, Column;
	public static int Currentx, Currenty, Result, Sum;
	public static boolean[][] Visited;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder out = new StringBuilder();
		while((Land = Input.readLine()) != null) {
			Grid = Land.split(" ");
			Row = Integer.parseInt(Grid[0]);
			Column = Integer.parseInt(Grid[1]);
			Map = new char[25][25];
			Visited = new boolean[25][25];
			
			for(int i = 0; i < Row; i++) {
				Map[i] = Input.readLine().toCharArray();
			}
			Grid = Input.readLine().split(" ");
			Currentx = Integer.parseInt(Grid[0]);
			Currenty = Integer.parseInt(Grid[1]);
			Result = 0;
			DFS(Currenty, Currentx);
			for(int i = 0; i < Row; i++) {
				for(int j = 0; j < Column; j++) {
					Sum = 0;
					DFS(i, j);
					if(Sum > Result)	Result = Sum;
				}
			}
			out.append(Result + "\n");
			Input.readLine();
		}
		System.out.print(out);

			
	}
	public static void DFS(int X, int Y) {
		if(X < 0 || X >= Row)	return;
		if(Y >= Column)			Y = 0;
		if(Y < 0)				Y = Column - 1;
		if(Visited[X][Y] || Map[X][Y] != Map[Currentx][Currenty])	return;
		Visited[X][Y] = true;
		Sum++;
		DFS(X + 1, Y);
		DFS(X, Y + 1);
		DFS(X - 1, Y);
		DFS(X, Y - 1);
	}
 	
	
	

}
