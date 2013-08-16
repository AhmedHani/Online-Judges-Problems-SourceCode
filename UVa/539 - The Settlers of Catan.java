package uva;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.LineNumberReader;
import java.math.BigInteger;
import java.util.*;

/**
 *
 * @author ahani
 */
 
public class Main {

    public static int[][] Matrix;
    public static int NumberOfNodes, NumberOfEdges;
    public static boolean[][] Visited;
    public static int First, Second;
    
    public static void main(String[] args) {
        Scanner Input = new Scanner(System.in);
        while(Input.hasNext()) {
            NumberOfNodes = Input.nextInt();
            NumberOfEdges = Input.nextInt();
            if(NumberOfEdges == 0 && NumberOfNodes == 0) break;
            Matrix = new int[NumberOfNodes + 1][NumberOfNodes + 1];
            Visited = new boolean[NumberOfNodes + 1][NumberOfNodes + 1];
            int Answer = 0;
            for(int i = 0; i < NumberOfEdges; i++) {
                First = Input.nextInt();
                Second = Input.nextInt();
                Matrix[First][Second] = Matrix[Second][First] = 1;
            }
            for(int i = 0; i < NumberOfNodes; i++) {
                Answer = Math.max(Answer, Solve(i));
            }
            System.out.println(Answer);
        }
    }
    public static int Solve(int Node) {
        int Result = 0;
        for(int i = 0; i < NumberOfNodes; i++) {
            if(Matrix[Node][i] > 0 && !Visited[Node][i]) {
                Visited[Node][i] = Visited[i][Node] = true;
                Result = Math.max(Result, Solve(i) + 1);
                Visited[Node][i] = Visited[i][Node] = false;
            }
        }
        return Result;
    }
}
