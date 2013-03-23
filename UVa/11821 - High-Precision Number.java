import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  public static void main(String args[]) throws IOException{
		Scanner Input = new Scanner(System.in);
		int TestCases =  Input.nextInt();
		BigDecimal Result;
		BigDecimal Number;
		
		while ( TestCases -- > 0 ){
			Result = BigDecimal.ZERO;
			Number = BigDecimal.ZERO;
			
			do {
				
			   Result = Result.add(Number);
				
				Number = Input.nextBigDecimal();
				
			}while ( Number.compareTo(BigDecimal.ZERO) != 0 );
			
			 char OutPut[] = Result.toString().toCharArray();
			 int Length = OutPut.length - 1;
			 
			 while (Length >= 0 && OutPut[Length] == '0') 
				 Length--; 
		      if (Length >= 0 && OutPut[Length] == '.') {
		        Length--;
		        
		      }
		      for (int i = 0; i <= Length; i++)
		    	  System.out.print(OutPut[i]);
		      System.out.println();
		}
		
		

}
}
	
	


