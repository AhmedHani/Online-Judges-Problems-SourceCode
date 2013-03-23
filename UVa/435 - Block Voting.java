

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

public class Main{
    public static int TestCases;
    public static int VotesTotal;
    public static int Size, CurrentParty;
    public static int[] Votes;
    public static int CurrentSum, Power;
    
    public static void main(String[] args) throws IOException {
        Scanner Input = new Scanner(System.in);
        TestCases = Input.nextInt();
        while(TestCases-- > 0) {
            Size = Input.nextInt();
            Votes = new int[200];
            VotesTotal = 0;
            for(int i = 0; i < Size; i++) {
                Votes[i] = Input.nextInt();
                VotesTotal += Votes[i];
            }
            for(CurrentParty = 0; CurrentParty < Size; CurrentParty++) {
                System.out.println("party " + (CurrentParty + 1) + " has power index " + Solve());
            }
            System.out.println();
        }
   
    }
    public static void Rec(int i) {
        if(CurrentSum <= VotesTotal / 2.0f) {
            if(CurrentSum + Votes[CurrentParty] > VotesTotal / 2.0f)
                ++Power;
        }
        for(int j = i + 1; j < Size; j++) {
            if(j != CurrentParty) {
                CurrentSum += Votes[j];
                Rec(j);
                CurrentSum -= Votes[j];
            }
        }
    }
    public static int Solve() {
        Power = 0;
        CurrentSum = 0;
        Rec(-1);
        return Power;
    }
}
