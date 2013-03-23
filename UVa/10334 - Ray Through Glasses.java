import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  public static void main(String args[]) throws IOException{
		Scanner Input = new Scanner(System.in);
		BigInteger Fibonacci[] = new BigInteger[1001];
				Fibonacci[0] = BigInteger.ONE;
				Fibonacci[1] = BigInteger.valueOf(2);
				
				for(int i = 2 ; i < 1001 ; i++){
					Fibonacci [i] = Fibonacci [i - 1].add(Fibonacci [i - 2]);
				}
				
			while ( Input.hasNext() ){
				 int NumberOfTimes = Input.nextInt(); 
				 System.out.println (Fibonacci[NumberOfTimes]);

			}
			
		}

}
	
	


