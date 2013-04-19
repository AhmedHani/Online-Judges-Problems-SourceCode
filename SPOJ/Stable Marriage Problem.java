
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
    public static int TestCases, Marriages;
    public static int Man, Woman;
    public static int[][] Prefered;
    public static int[][] WomanToMan;
    public static int[][] ManToWoman;
    public static Queue<Integer> Q;
    public static int[] El_7ag;
    public static int[] El_7aga;
 
    public static void main(String[] args) throws IOException {
        Scanner Input = new Scanner(System.in);
        TestCases = Input.nextInt();
        while(TestCases-- > 0) {
            Marriages = Input.nextInt();
            Prefered = new int[Marriages + 1][Marriages + 1];
            WomanToMan = new int[Marriages + 1][Marriages + 1];
            ManToWoman = new int[Marriages + 1][Marriages + 1];
            El_7ag = new int[Marriages + 1];
            El_7aga = new int[Marriages + 1];
            Q = new ArrayDeque<Integer>();
            
            for(int i = 0; i < Marriages; i++) {
                Woman = Input.nextInt();
                for(int j = 0; j < Marriages; j++) {
                    WomanToMan[Woman - 1][j] = Input.nextInt();
                    --WomanToMan[Woman - 1][j];
                    Prefered[Woman - 1][WomanToMan[Woman - 1][j]] = j;
                }
            }
            for(int i = 0; i < Marriages; i++) {
                Man = Input.nextInt();
                for(int j = 0; j < Marriages; j++) {
                    ManToWoman[Man - 1][j] = Input.nextInt();
                    --ManToWoman[Man - 1][j];
                }
            }
            Arrays.fill(El_7ag, -1);
            Arrays.fill(El_7aga, -1);
            
            for(int i = 0; i < Marriages; i++)  Q.add(i);
            while(!Q.isEmpty()) {
                int CuurentMan = Q.poll();
                for(int i = 0; i < Marriages; i++) {
                    int CurrentWoman = ManToWoman[CuurentMan][i];
                    if(El_7aga[CurrentWoman] == -1) {
                        El_7aga[CurrentWoman] = CuurentMan;
                        El_7ag[CuurentMan] = CurrentWoman;
                        break;
                    } else if(Prefered[CurrentWoman][CuurentMan] < Prefered[CurrentWoman][El_7aga[CurrentWoman]]) {
                        Q.add(El_7aga[CurrentWoman]);
                        El_7ag[CuurentMan] = CurrentWoman;
                        El_7aga[CurrentWoman] = CuurentMan;
                        break;
                    }
                }
            }
            for(int i = 0; i < Marriages; i++)  System.out.printf("%d %d\n", i + 1, El_7ag[i] + 1);
        }
        
        
    }
    
    

}
