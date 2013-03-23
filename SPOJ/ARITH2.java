import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main{
  public static int Number;
	public static int TestCases;
	public static String Line;
	public static BigInteger Answer;
	public static BigInteger Current;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		Scanner Input = new Scanner(System.in);
		TestCases = Input.nextInt();
		Input.nextLine();
		while(TestCases-- > 0) {
			Input.nextLine();
			Line = Input.nextLine();
			Line = Line.replaceAll("=", "");
			String[] Arr = Line.split("\\s+");
			Answer = Answer.valueOf(0);
			char Operators = '+';
			
			for(String X : Arr) {
				if(X.length() == 0)		continue;
				else if("+".equals(X))		Operators = '+';
				else if("-".equals(X))		Operators = '-';
				else if("*".equals(X))		Operators = '*';
				else if("/".equals(X))		Operators = '/';
				else {
					Current = new BigInteger(X);
					if(Operators == '+')	Answer = Answer.add(Current);
					else if(Operators == '-')	Answer = Answer.subtract(Current);
					else if(Operators == '*')	Answer = Answer.multiply(Current);
					else if(Operators == '/')	Answer = Answer.divide(Current);
					
				}
			}
			System.out.println(Answer);
		}
		
			
		}
		
	
	
	

}

