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
    public static String Line;
    public static int Connect, Length;
    public static void main(String[] args) throws IOException {
        BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
        TestCases = Integer.parseInt(Input.readLine());
        while(TestCases-- > 0) {
            Connect = 0;
            Line = Input.readLine();
            Length = Line.length();
            for(int i = 0; i < Line.length(); i++) {
                if(Line.charAt(i) == 'F')  Connect += 1;
                if(Line.charAt(i) == 'M')  Connect -= 1;
            }
            System.out.println(Connect == 0 && Length != 2 ? "LOOP" : "NO LOOP");
        }
        
    }
        
}
