import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  static int Result = 0;
	
	
	private static boolean Matching(String Tmp, String Second){
		for ( int i = 0 ; i < Tmp.length() ; i++ ){
			if ( Tmp.charAt(i) == Second.charAt(i) )
				return true;
		}
		return false;
	}
	
	public static void Solve(String First, String Second){
		String Temp = "";
		for ( int i = 0 ; i < First.length() ; i++ ){
			Temp = First.substring(i, First.length());
			if (Matching(Temp, Second)){
				Result -= Temp.length();
				break;
			}
		}
	}
	
	public static void main(String args[]) throws IOException{
		BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
		int TestCases = Integer.parseInt(Input.readLine());
		
		while ( TestCases -- > 0 ){
			StringTokenizer Str = new StringTokenizer(Input.readLine());
			int NumberOfChars = Integer.parseInt(Str.nextToken());
			int NumberOfWords = Integer.parseInt(Str.nextToken());
			String [] Words = new String[NumberOfWords];
			
			for ( int i = 0 ; i < NumberOfWords ; i++ ){
				Words[i] = Input.readLine();
			}
			
			Result = NumberOfChars * NumberOfWords;
			
			for ( int i = 0 ; i < NumberOfWords - 1 ; i++ ){
				Solve(Words[i], Words[i + 1]);
			}
			System.out.println(Result);
			
		}
			
			
		}
		
}
	
