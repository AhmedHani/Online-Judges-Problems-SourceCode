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
 * @ahani
 */
 
public class Main {

    public static class All {
        int First, Second;

        public  All(int First, int Second) {
            this.First = First;
            this.Second = Second;
        }
        
    }
    public static int FirstMall, SecondMall;
    public static int X, Y;
    public static int[][] Marked;
    public static int[][] Distance;
    public static Queue<All> Q;
    public static final int[] dx = {0, 0, -1, 1};
    public static final int[] dy = {-1, 1, 0, 0};
    
    public static void main(String[] args) throws IOException {
        Scanner Input = new Scanner(System.in);
        while(Input.hasNext()) {
            FirstMall = Input.nextInt();
            if(FirstMall == 0)  break;
            Marked = new int[2000 + 10][2000 + 10];
            Distance = new int[2000 + 10][2000 + 10];
            //for(int i = 0; i < Distance.length; i++) Arrays.fill(Distance[i], -1);
            Arrays.fill(Distance, -1);
            Q = new ArrayDeque<All>();
            while(FirstMall-- > 0) {
                X = Input.nextInt();
                Y = Input.nextInt();
                Marked[X][Y] = 1;
                Q.add(new All(X, Y));
                Distance[X][Y] = 0;
            }
            SecondMall = Input.nextInt();
            while(SecondMall-- > 0) {
                X = Input.nextInt();
                Y = Input.nextInt();
                Marked[X][Y] = 2;
            }
            System.out.println(BFS());
        }
    }
    
    public static int BFS() {
        while(!Q.isEmpty()) {
            All Front = Q.poll();
            for(int i = 0; i < 4; i++) {
                int CurrentX = Front.First + dx[i];
                int CurrentY = Front.Second + dy[i];
                if(inRange(CurrentX, CurrentY)) {
                    All Next = new All(CurrentX, CurrentY);
                    if(Distance[CurrentX][CurrentY] == -1) {
                        Distance[CurrentX][CurrentY] = Distance[Front.First][Front.Second] + 1;
                        if(Marked[CurrentX][CurrentY] == 2) return Distance[CurrentX][CurrentY];
                        Q.add(Next);
                    }
                } 
            }
        }
        return -1;
    }
    public static boolean inRange(int X, int Y) {
        return X >= 0 && X < 2000 && Y >= 0 && Y < 2000;
    }
    

}
