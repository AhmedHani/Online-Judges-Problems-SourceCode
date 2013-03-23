import java.io.IOException;
import java.math.*;
import java.util.*;


public class Main {
   public static void main(String[] args) {       

	        Scanner Input = new Scanner(System.in);
	        BigInteger Number;
	        
	        while (true){
	        	Number = Input.nextBigInteger();
	        	if (Number.compareTo(BigInteger.ZERO) == 0)
	        		break;
	        	if (Number.mod(BigInteger.valueOf(17)).compareTo(BigInteger.ZERO) == 0)
	        		System.out.println("1");
	        	else
	        		System.out.println ("0");

	        }
	

}
}
