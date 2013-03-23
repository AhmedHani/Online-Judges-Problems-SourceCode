import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  public static void main(String args[]) throws IOException{
		BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
		String Number;
		
		while ( (Number = Input.readLine()) != null ){
			if ( !Number.contains("x") ){
				if ( Double.parseDouble(Number) < 0 )
					break;
				System.out.println("0x"+ Integer.toHexString(Integer.parseInt(Number)).toUpperCase());
			}else{
				System.out.println(Integer.decode(Number));
			}
		
		
			
		}

}
}
	
	


