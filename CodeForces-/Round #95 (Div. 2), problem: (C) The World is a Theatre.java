import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
 
public class Main {
    public static int N, M, T;
   // public static long[][] C = new long[35][35];
    public static long Result;
    public static void main(String[] args) throws IOException {
      Scanner Input = new Scanner(System.in);
          Result = 0;
          N = Input.nextInt();
          M = Input.nextInt();
          T = Input.nextInt();
          for(int i = 1; i < T; i++) {
              if(T - i < 4) break;
              if(i > M)     break;
              Result += (long) PreCa(M, i) * (PreCa(N, T - i));
          }
          System.out.println(Result);
    }
    
    public static long PreCa(int First, int Second) {
        long[][] C = new long[100][100];
        for(int i = 0; i < 31; i++)    
            C[i][0] = C[0][i] = 1;
        for(int i = 1; i < 31; i++) {
            for(int j = 1; j <= i; j++) {
                C[i][j] = (i != j) ? C[i - 1][j] + C[i - 1][j - 1] : 1;
            }
        }
        return C[First][Second];
    }
 
}
