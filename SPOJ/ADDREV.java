import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main{
  public static int First, Second;
	public static int TestCases, Result;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		Scanner Input = new Scanner(System.in);
		TestCases = Input.nextInt();
		Input.nextLine();
		while(TestCases-- > 0) {
			First = Input.nextInt();
			Second = Input.nextInt();
			Result = Solve(First) + Solve(Second);
			Result = Solve(Result);
			System.out.println(Result);
		
		}
		
			
	}
		
	public static int Solve(int Number) {
		int Reversed = 0;
		int Remainder = 0;
		while(Number > 0) {
			Remainder = Number % 10;
			Reversed = Reversed * 10 + Remainder;
			Number = Number / 10;
		}
		return Reversed;
	}
	
	

}

