import java.io.IOException;
import java.math.*;
import java.util.*;


public class Main {
  public static void main(String args[]){
		int TestCases;
		
		Scanner Input = new Scanner(System.in);
		TestCases = Input.nextInt();
		
		while (TestCases-- > 0){
			BigInteger First = Input.nextBigInteger();
			Input.next();
			BigInteger Second = Input.nextBigInteger();
			BigInteger D = First.gcd(Second);
			First = First.divide(D);
			Second = Second.divide(D);
			 System.out.println(First + " / " + Second);
		}
	}
	
	

}
