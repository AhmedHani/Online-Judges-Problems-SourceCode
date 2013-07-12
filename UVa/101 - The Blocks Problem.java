import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

/**
 *
 * @author ahani
 */
public class Main {
    public static int NumberBlocks;
    public static Stack<Integer> Blocks[];
    public static int Position[];
    public static String Line; 
    public static int A, B;
    
    public static void main(String[] args) throws IOException{
        BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
        NumberBlocks = Integer.parseInt(Input.readLine());
        Blocks = new Stack[NumberBlocks];
        Position = new int[NumberBlocks];
        for(int i = 0; i < NumberBlocks; i++) {
            Blocks[i] = new Stack<Integer>();
            Blocks[i].push(i);
            Position[i] = i;
        }
        //for(int i = 0; i < NumberBlocks; i++) {
            
        //}
        Line = "";
        while(!(Line = Input.readLine()).equals("quit")) {
            StringTokenizer token = new StringTokenizer(Line);
            String First = token.nextToken();
            A = Integer.parseInt(token.nextToken());
            String Second = token.nextToken();
            B = Integer.parseInt(token.nextToken());
            
            if(A == B || Position[A] == Position[B]) continue;
            if(First.equals("move")) {
                if(Second.equals("onto")) {
                    MoveOnto(A, B);
                } else if(Second.equals("over")) {
                    MoveOver(A, B);
                }
            } else if(First.equals("pile")) {
                if(Second.equals("onto")) {
                    PileOnto(A, B);
                } else if(Second.equals("over")) {
                    PileOver(A, B);
                }
            }
        }
        for(int i = 0; i < Blocks.length; i++) System.out.println(Solve(i));
    }
    public static void MoveOnto(int First, int Second) {
       ClearAbove(Second);
       MoveOver(First, Second);
    }
    public static void MoveOver(int First, int Second) {   
       ClearAbove(First);
       Blocks[Position[Second]].push(Blocks[Position[First]].pop());
       Position[First] = Position[Second];
    }
    public static void PileOnto(int First, int Second) {
       ClearAbove(Second);
       PileOver(First, Second);
    }
    public static void PileOver(int First, int Second) {
       Stack<Integer> Pile = new Stack<Integer>();
       while(Blocks[Position[First]].peek() != First) {
           Pile.push(Blocks[Position[First]].pop());
       }
       Pile.push(Blocks[Position[First]].pop());
       while(!Pile.isEmpty()) {
          int Tmp = Pile.pop();
          Blocks[Position[Second]].push(Tmp);
          Position[Tmp] = Position[Second];
       }
    }
    public static void ClearAbove(int Block) {
        while(Blocks[Position[Block]].peek() != Block) {
           Intial(Blocks[Position[Block]].pop());
        }
    }
    public static void Intial(int Block) {   
        while(!Blocks[Block].isEmpty()) {
           Intial(Blocks[Block].pop());
        }
        Blocks[Block].push(Block);
        Position[Block] = Block;
    }
    public static String Solve(int Index) {
        String Result = "";
        while(!Blocks[Index].isEmpty()) Result = " " + Blocks[Index].pop() + Result;
        Result = Index + ":" + Result;
        return Result;
    }

}
