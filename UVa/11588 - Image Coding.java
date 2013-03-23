import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.LineNumberReader;
import java.math.BigInteger;
import java.util.*;

//import org.eclipse.persistence.internal.sessions.remote.ReplaceValueHoldersIterator;

public class Main {
  public static String[] Line;
	//public static char[] Grid;
	public static int Rows, Columns, M, MM;
	public static int TestCases;
	public static void main(String args[]) throws Exception {
		BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
		TestCases = Integer.parseInt(Input.readLine());
		int Cases = 1;
		while(TestCases-- > 0) {
			Line = Input.readLine().split(" ");
			Rows = Integer.parseInt(Line[0]);
			Columns = Integer.parseInt(Line[1]);
			M = Integer.parseInt(Line[2]);
			MM = Integer.parseInt(Line[3]);
			int[] Freq = new int[26];
			for(int i = 0; i < Rows; i++) {
				char[] Grid = Input.readLine().toCharArray(); 
				for(int j = 0; j < Columns; j++) {
					Freq[Grid[j] - 'A']++;
				}
			}
			Arrays.sort(Freq);
			int Result = 0;
			int Maximum = Freq[25];
			for(int i = 0; i < 25 && Freq[i] != Maximum; i++) {
				Result += Freq[i] * MM;
			}
			int Last = 25;
			while(Freq[Last] == Maximum) { Result += Freq[25] * M; Last--; }
			System.out.println("Case " + (Cases++) + ": " + Result);
		}
		
		
			
	
	}
	
	

}
