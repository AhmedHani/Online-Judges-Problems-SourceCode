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
  public static int Faces, Throws, Summation;
	public static BigInteger Result;
	public static BigInteger[][] DPMemo;
	
	public static void main(String args[]) throws Exception {
		Scanner Input = new Scanner(System.in);
		while(Input.hasNext()) {
			Faces = Input.nextInt();
			Throws = Input.nextInt();
			Summation = Input.nextInt();
			DPMemo = new BigInteger[Throws + 1][Summation + 1];
			System.out.print(Solve(Throws, Summation));
			System.out.println("/" + new BigInteger(Faces + "").pow(Throws));
		}
			
			
		}
		
	public static BigInteger Solve(int T, int S) {
		if(T < 0 || S < 0)	return BigInteger.ZERO;
		else if(T == 0 && S == 0)	return DPMemo[T][S] = BigInteger.ONE;
		else if(T == 0 || S == 0)	return DPMemo[T][S] = BigInteger.ZERO;
		else if(DPMemo[T][S] != null)	return DPMemo[T][S];
		else {
			Result = BigInteger.ZERO;
			for(int i = 1; i <= Faces; i++)
				Result = Result.add(Solve(T - 1, S - i));
			return DPMemo[T][S] = Result;
			
		}
		
	}
		
			
	
	
	
	

}
