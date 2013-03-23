

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
    public static int INF = 100000000;
    public static int Nodes;
    public static int Connections;
    public static int First, Second, Cost;
    public static int[][] Matrix;
    public static int[] Path;
    public static int[] Distance;
    public static class Edges {
        int First, Second;
    }
    public static Edges[] Edge;
    public static int[] P;
    public static int Index;
    
    public static void main(String[] args) throws IOException {
        Scanner Input = new Scanner(System.in);
        while(Input.hasNext()) {
            Nodes = Input.nextInt();
            if(Nodes == 0)break;
            Connections = Input.nextInt();
            Edge = new Edges[100000];
            for(int i = 0; i < 100000; i++)Edge[i] = new Edges();
            Distance = new int[500];
            Path = new int[500];
            P = new int[500];
            Matrix = new int[500][500];
            for(int i = 1; i <= Nodes; i++)Distance[i] = INF;
            Path[0] = -1;
            Distance[1] = 0;
            for(int i = 0; i < Connections; i++) {
                Edge[i].First = Input.nextInt();
                Edge[i].Second = Input.nextInt();
                Cost = Input.nextInt();
                Matrix[Edge[i].First][Edge[i].Second] = Cost;
                Matrix[Edge[i].Second][Edge[i].First] = Cost;
            }
            Index = 0;
            int Result;
            BellMan();
            Result = Distance[Nodes];
            Paths(Nodes);
            Change();
            for(int i = 1; i <= Nodes; i++)Distance[i] = INF;
            Path[0] = -1;
            Distance[1] = 0;
            BellMan();
            Result += Distance[Nodes];
            System.out.println(Result >= INF ? "Back to jail" : Result);
        }
        
        
    }
    public static void BellMan() {
        int U, V;
        int No = Nodes;
        while(No-- > 0) {
            for(int i = 0; i < Connections; i++) {
                U = Edge[i].First;
                V = Edge[i].Second;
                if(Distance[U] + Matrix[U][V] < Distance[V]) {
                    Distance[V] = Distance[U] + Matrix[U][V];
                    Path[V] = U;
                }
                if(Distance[V] + Matrix[V][U] < Distance[U]) {
                    Distance[U] = Distance[V] + Matrix[V][U];
                    Path[U] = V;
                }
            }
        }
    }
    public static void Paths(int N) {
        if(N == 1) {
            P[Index++] = N;
            return;
        }
        Paths(Path[N]);
        P[Index++] = N;
    }
    public static void Change() {
        for(int i = 0; i < Index-1; i++) {
            Matrix[P[i]][P[i + 1]] = INF;
            Matrix[P[i + 1]][P[i]] = -Matrix[P[i + 1]][P[i]];
        }
    }

}
