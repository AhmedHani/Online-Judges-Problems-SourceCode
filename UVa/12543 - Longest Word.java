
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.AbstractQueue;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import sun.security.provider.certpath.AdjacencyList;

public class Main {
    public static int Maximum;
    public static String Word, Word2;
    public static int Length, CurrentLength;
    
    public static void main(String[] args) throws IOException {
        Scanner Input = new Scanner(System.in);
        Maximum = -1;
        while(Input.hasNext()) {
            Word = Input.next();
            if(Word.equals("E-N-D"))break;
            Length = Word.length();
            CurrentLength = 0;
            for(int i = 0; i < Length; i++) {
                if(Word.charAt(i) == '-' || Character.isLetter(Word.charAt(i)))
                    CurrentLength++;
            }
            if(Maximum < CurrentLength) {
                Maximum = CurrentLength;
                Word2 = new String(Word);
            }
        }
        Length = Word2.length();
        String Tmp = "";
        for(int i = 0; i < Length; i++) {
            if(Word2.charAt(i) == '-' || Character.isLetter(Word2.charAt(i)))
                Tmp += Character.toLowerCase(Word2.charAt(i));
        }
        System.out.println(Tmp);
   
    }
    

}
