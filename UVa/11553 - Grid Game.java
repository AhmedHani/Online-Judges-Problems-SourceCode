
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.AbstractQueue;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
//import sun.security.provider.certpath.AdjacencyList;

public class GridGame {
    public static int TestCases;
    public static int Size;
    public static int[][] Grid = new int[100][10000];
    public static int Maximum;
    public static int[] Target = new int[100];
    public static void main(String[] args) throws IOException {
        Scanner Input = new Scanner(System.in);
        TestCases = Input.nextInt();
        while(TestCases-- > 0) {
            Size = Input.nextInt();
            Maximum = 1 << 30;
           // Target = new int[Size * Size + 1];
            //Grid = new int[Size + 1][Size + 1];
            for(int i = 0; i < Size; i++) {
                for(int j = 0; j < Size;j++) {
                    Grid[i][j] = Input.nextInt();
                }
            }
            BackTrack(0, 0);
            System.out.println(Maximum);
        }
        
    }
    public static void BackTrack(int Start, int Mask) {
        //int Sum;
        if(Start == Size) {
            int Sum = 0;
            for(int i = 0; i < Size; i++)   Sum += Grid[i][Target[i]];
            if(Sum < Maximum)Maximum = Sum;
            return;
        }
        for(int i = 0; i < Size; i++) {
            if((Mask & (1 << i)) > 0) continue;
            Target[Start] = i;
            BackTrack(Start + 1, Mask | (1 << i));
        }
    }
}
