import java.io.IOException;
import java.math.*;
import java.util.*;


public class Main {
   public static void main(String[] args) {       

	        Scanner Input = new Scanner(System.in);
	        int N, A;
	        while(Input.hasNextInt()) {
	            N = Input.nextInt();
	            A = Input.nextInt();
	            BigInteger sum = new BigInteger("0"), 
	            tmpA = BigInteger.valueOf(A);
	            for(int i = 1; i <= N; i++)
	                sum = sum.add(BigInteger.valueOf(i).multiply(tmpA.pow(i)));
	            System.out.println(sum);
	        }
	        }
	

}
