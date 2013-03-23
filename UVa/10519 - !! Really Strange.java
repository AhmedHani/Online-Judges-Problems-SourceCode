import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  public static void main(String args[]) throws IOException{
		Scanner Input = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    BigInteger two = new BigInteger("2");

	    while (Input.hasNext())
	    {
	      BigInteger Number = Input.nextBigInteger();
	      BigInteger E = Number.pow(2);

	      if (Number.compareTo(new BigInteger("0")) == 0) {
	        System.out.println("1");
	      } else if (Number.compareTo(new BigInteger("1")) == 0) {
	        System.out.println("2");
	      } else {
	        System.out.println(E.subtract(Number).add(two).toString());
	      }
	    }
		
		

}
}
	
	


