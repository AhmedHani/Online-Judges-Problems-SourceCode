
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
    static class NODE implements Comparable<NODE> {
        double Cost;
        int Index;
        public NODE(int Ind, double CC) {
            Cost = CC;
            Index = Ind;
        }
        public int compareTo(NODE arg0) {
            if (Cost < arg0.Cost)return -1;
            else                return 1;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
        String Buf = "";
        while(!(Buf = Input.readLine()).equals("*")) {
            StringTokenizer St;
            St = new StringTokenizer(Buf);
            
            int W = Integer.parseInt(St.nextToken());
            int H = Integer.parseInt(St.nextToken());
            
            int Nodes = Integer.parseInt(Input.readLine()) + 2;
            double[][] Coord = new double[Nodes + 5][Nodes + 5];
            Coord[0][0] = 0.0;
            Coord[0][1] = 0.0;
            
            for(int i = 1; i < Nodes - 1; i++) {
                St = new StringTokenizer(Input.readLine());
                Coord[i][0] = Double.parseDouble(St.nextToken());
                Coord[i][1] = Double.parseDouble(St.nextToken());
                
            }
            Coord[Nodes - 1][0] = W;
            Coord[Nodes - 1][1] = H;
            double Mx = Double.parseDouble(Input.readLine());
            ArrayList<NODE>[] No = new ArrayList[Nodes];
            for(int i = 0; i < Nodes; i++)
                No[i] = new ArrayList<NODE>();
            for(int i = 0; i < Nodes; i++) {
                double x = Coord[i][0];
                double y = Coord[i][1];
                for (int j = 0; j < Nodes; j++) {
                    if (i != j) {
                        double xx = Coord[j][0];
                        double yy = Coord[j][1];
                        double distance = Math.sqrt((x - xx) * (x - xx) + (y - yy) * (y - yy));
                        if (distance <= 1.5)    No[i].add(new NODE(j, distance));
                    }
                }
            }
            double Result = Dijkstra(No, Nodes);
            if (Result <= Mx)   System.out.println("I am lucky!");
            else                System.out.println("Boom!");
        }
        
        
    }
    public static double Dijkstra(ArrayList<NODE>[] No, int n) {
        PriorityQueue<NODE> PQ = new PriorityQueue<NODE>();
        double[] distance = new double[n];
        Arrays.fill(distance, Double.MAX_VALUE);
        distance[0] = 0;
        PQ.add(new NODE(0, 0.0));
        while (!PQ.isEmpty()) {
            NODE current = PQ.poll();
            if (distance[current.Index] == current.Cost) {
                for (int i = 0; i < No[current.Index].size(); i++) {
                    NODE neighbor = No[current.Index].get(i);
 
                    if (distance[current.Index] + neighbor.Cost < distance[neighbor.Index]) {
                        distance[neighbor.Index] = distance[current.Index] + neighbor.Cost;
                        PQ.add(new NODE(neighbor.Index, distance[neighbor.Index]));
                    }
                }
            }
        }
        return distance[n - 1];
    }
    

}
