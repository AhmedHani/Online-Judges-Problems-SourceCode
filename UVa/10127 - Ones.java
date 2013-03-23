import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  public static void main(String args[]) throws IOException{
		Scanner Input = new Scanner(System.in);
		while ( Input.hasNext() ){
			int NumberOfOnes = 1;
			int Tmp = 1;
			int Number = Input.nextInt();
			
			while ( Tmp != 0 ){
				if ( Number > Tmp ){
					NumberOfOnes++;
				}
				Tmp = Number > Tmp ? Tmp * 10 + 1 : Tmp % Number;
			}
			System.out.println(NumberOfOnes);
		}
	 
		

}
}
	
	
