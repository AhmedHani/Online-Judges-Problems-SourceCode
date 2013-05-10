import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.LineNumberReader;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static int NumberOfBachelors, NumberOfSpinsiters;
    public static int[] BachelorsAges;
    public static int[] SpinistersAges;

    public static void main(String[] args) throws IOException {
        Scanner Input = new Scanner(System.in);
        int Cases = 1;
        while(Input.hasNext()) {
            NumberOfBachelors = Input.nextInt();
            NumberOfSpinsiters = Input.nextInt();
            if(NumberOfBachelors == 0 || NumberOfSpinsiters == 0)   break;
            BachelorsAges = new int[NumberOfBachelors];
            SpinistersAges = new int[NumberOfSpinsiters];
            
            for(int i = 0; i < NumberOfBachelors; i++)  BachelorsAges[i] = Input.nextInt();
            for(int i = 0; i < NumberOfSpinsiters; i++) SpinistersAges[i] = Input.nextInt();
            
            Arrays.sort(BachelorsAges);
            //System.out.println(BachelorsAges[0]);
            if(NumberOfBachelors <= NumberOfSpinsiters) System.out.println("Case " + (Cases++) + ": " + "0");
            else                                        System.out.println("Case " + (Cases++) + ": " + (NumberOfBachelors - NumberOfSpinsiters) + " " + (BachelorsAges[0]));
        }
        
    }
    
        
}
    
    

