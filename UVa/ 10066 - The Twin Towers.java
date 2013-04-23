
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
//    public static class All {
//        int First, Second;
//        All(int First, int Second) {
//            this.First = First;
//            this.Second = Second;
//        }
//    }
    public static int FirstTower, SecondTower;
    public static int[] Tails1;
    public static int[] Tails2;
    public static int[][] DP;
    public static void main(String[] args) throws IOException {
        Scanner Input = new Scanner(System.in);
        int Cases = 1;
        while(Input.hasNext()) {
            FirstTower = Input.nextInt();
            SecondTower = Input.nextInt();
            if(FirstTower == 0 &&  SecondTower == 0)break;
            Tails1 = new int[FirstTower + 2];
            Tails2 = new int[SecondTower + 2];
            DP = new int[FirstTower + 1][SecondTower + 1];
            for(int i = 0; i < DP.length; i++) Arrays.fill(DP[i], -1);
            for(int i = 0; i < FirstTower; i++) Tails1[i] = Input.nextInt();
            for(int i = 0; i < SecondTower; i++)Tails2[i] = Input.nextInt();
            System.out.printf("Twin Towers #%d\n", Cases++);
            System.out.printf("Number of Tiles : %d\n\n", Solve(0, 0));
        }
        
    }
    
    public static int Solve(int i, int j) {
        if(DP[i][j] != -1)  return DP[i][j];
        if(i >= FirstTower || j >= SecondTower) return 0;
        if(Tails1[i] == Tails2[j])   return DP[i][j] = 1 + Solve(i + 1, j + 1);
        else                                    return DP[i][j] = Math.max(Solve(i + 1, j), Solve(i, j + 1));
    }
        
}
    
    

