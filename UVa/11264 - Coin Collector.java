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
    public static int TestCases;
    public static long All;
    public static int Index, Answer;
    public static int NumberOfCoins;
    public static int[] List;
    public static int[] Values;

    public static void main(String[] args) throws IOException {
        Scanner Input = new Scanner(System.in);
        TestCases = Input.nextInt();
        int Cases = 1;
        while(TestCases-- > 0) {
            All = Index = Answer = 0;
            NumberOfCoins = Input.nextInt();
            List = new int[NumberOfCoins + 1];
            Values = new int[NumberOfCoins + 1];
            for(int i = 0; i < NumberOfCoins; i++) {
                List[i] = Input.nextInt();
            }
            for(int i = 0; i < NumberOfCoins; i++) {
                while(All >= List[i])   All -= Values[--Index];
                All += List[i];
                Values[Index++] = List[i];
                if(Index > Answer)  Answer = Index;
            }
            System.out.println(Answer);
        }
        
    }
    
        
}
    
    

