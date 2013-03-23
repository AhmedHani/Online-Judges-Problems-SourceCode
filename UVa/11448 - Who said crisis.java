import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  public static void main(String args[]) throws IOException{
		
		BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
		
		int TestCases = Integer.parseInt(Input.readLine());
		
		while ( TestCases-- > 0){
			 String [] line = Input.readLine().split(" ");
			 
			 BigInteger Number = new BigInteger(line[0]);
       Number = Number.subtract(new BigInteger(line[1]));
			 System.out.println(Number);

		}
							
		
		
		
	}
	
	

}
