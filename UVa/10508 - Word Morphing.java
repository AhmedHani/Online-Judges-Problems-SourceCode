
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
import java.util.Vector;
import sun.security.provider.certpath.AdjacencyList;

public class Main {
    //public static 
    public static int Words, Letter;
    public static int Index;
    public static String First, All;
    
    public static void main(String[] args) throws IOException {
        Scanner Input = new Scanner(System.in);
        Vector<String> V = new Vector<String>();
        while(Input.hasNext()) {
            V.clear();
            Words = Input.nextInt();
            Letter = Input.nextInt();
            //V = new Vector<String>();
            V.setSize(Words);
            First = Input.next();
            V.add(0, First);
            for(int i = 1; i < Words; i++) {
                All = Input.next();
                Index = 0;
                for(int j = 0; j < Letter; j++) {
                    if(First.charAt(j) != All.charAt(j))
                        ++Index;
                }
                V.add(Index, All);
            }
            for(int i = 0; i < V.size(); i++)
                if(V.get(i) != null)
                    System.out.println(V.get(i));
           
        }
   
    }
    

}
