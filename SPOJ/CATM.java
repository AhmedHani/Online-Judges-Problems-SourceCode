

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
    public static int TestCases; 
    public static int Rows, Columns;
    public static int XMouse, YMouse;
    public static int XCat1, YCat1;
    public static int XCat2, YCat2;
    public static int MouseNorth, MouseSouth, MouseEast, MouseWest;
    public static int CatNorth, CatSouth, CatEast, CatWest;
    
    public static void main(String[] args) throws IOException {
        Scanner Input = new Scanner(System.in);
        Rows = Input.nextInt();
        Columns = Input.nextInt();
        TestCases = Input.nextInt();
        while(TestCases-- > 0) {
            XMouse = Input.nextInt(); YMouse = Input.nextInt();
            XCat1 = Input.nextInt(); YCat1 = Input.nextInt();
            XCat2 = Input.nextInt(); YCat2 = Input.nextInt();
            if(XMouse >= XCat1 && XMouse >= XCat2)   System.out.println("YES");
            else if(XMouse <= XCat1 && XMouse <= XCat2) System.out.println("YES");
            else if(YMouse >= YCat1 && YMouse >= YCat2) System.out.println("YES");
            else if(YMouse <= YCat1 && YMouse <= YCat2) System.out.println("YES");
            else {
                MouseNorth = XMouse - 1;
                MouseSouth = Rows - XMouse;
                MouseEast = YMouse - 1;
                MouseWest = Columns - YMouse;
                CatNorth = Math.min(Math.abs(1 - XCat1) + Math.abs(YMouse - YCat1), Math.abs(1 - XCat2) + Math.abs(YMouse - YCat2));
                CatSouth = Math.min(Math.abs(Rows - XCat1) + Math.abs(YMouse - YCat1), Math.abs(Rows - XCat2) + Math.abs(YMouse - YCat2));
                CatEast = Math.min(Math.abs(XMouse - XCat1) + Math.abs(1 - YCat1), Math.abs(XMouse - XCat2) + Math.abs(1 - YCat2));
                CatWest = Math.min(Math.abs(XMouse - XCat1) + Math.abs(Columns - YCat1), Math.abs(XMouse - XCat2) + Math.abs(Columns - YCat2));
                if(MouseNorth < CatNorth || MouseSouth < CatSouth || MouseEast < CatEast || MouseWest < CatWest)
                    System.out.println("YES");
                else    System.out.println("NO");
            }
        }
           
   
    }
    

}

