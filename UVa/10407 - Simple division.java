import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

//import org.eclipse.persistence.internal.sessions.remote.ReplaceValueHoldersIterator;

public class Main {
  public static String First;
	public static String[] SNumbers;
	public static int Target, Index;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
		
		while((First = Input.readLine()) != null) {
			if("0".equals(First))	break;
			SNumbers = First.split(" ");
			int[] Numbers = new int[SNumbers.length - 1];
			int Minimum = Integer.MAX_VALUE;
			for(int i = 0; i < Numbers.length; i++) {
				Numbers[i] = Integer.parseInt(SNumbers[i]);
				if(Numbers[i] < Minimum)	Minimum = Numbers[i];
					
			}
			for(int i = 0; i < Numbers.length; i++) {
				Numbers[i] = Minimum;
			}
			Target = 0;
			
			for(int i = 0; i < Numbers.length; i++) {
				Target = GCD(Target, Numbers[i]);
			}
			System.out.println(Target);
		}
		

			
	}
	private static int GCD(int X, int Y) {
		return Y == 0 ? X : GCD(Y, X % Y);
	}
 	
	
	

}
