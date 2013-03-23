import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {
  public static int Max = 10000 + 5;
	public static int NumberOfPeople, Operation, First, Second;
	public static int[] Parents = new int[Max + Max + 1];
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		Scanner Input = new Scanner(System.in);
		NumberOfPeople = Input.nextInt();
		for(int i = 1; i <= (Max + Max); i++)		Parents[i] = i;
		
		while(Input.hasNext()) {
			Operation = Input.nextInt(); First = Input.nextInt(); Second = Input.nextInt();
			if(Operation == 0 && First == 0 && Second == 0)		break;
			if(Operation == 1)	setFriends(First, Second);
			if(Operation == 2)	setEnemies(First, Second);
			if(Operation == 3)	areFriends(First, Second);
			if(Operation == 4)	areEnemies(First, Second);
			
		}
		
	}
	
	public static int FindSet(int i){
	    return Parents[i] == i ? i : (Parents[i] = FindSet(Parents[i]));
	}
	public static void setFriends(int X, int Y) {
		int A1, B1, A2, B2;
		A1 = FindSet(X);	A2 = FindSet(Y);
		B1 = FindSet(X + NumberOfPeople);
		B2 = FindSet(Y + NumberOfPeople);
		
		if(A1 == B2 || A2 == B1)	System.out.println("-1");
		else {
			Parents[A2] = A1;
			Parents[B2] = B1;
		}
	}
	public static void areFriends(int X, int Y) {
		System.out.println(FindSet(X) == FindSet(Y) ? "1" : "0");
			
	}
	public static void setEnemies(int X, int Y) {
		int A1, B1, A2, B2;
		A1 = FindSet(X);	A2 = FindSet(Y);
		B1 = FindSet(X + NumberOfPeople);
		B2 = FindSet(Y + NumberOfPeople);
		
		if(A1 == A2)	System.out.println("-1");
		else {
			Parents[B1] = A2;
			Parents[B2] = A1;
		}
	}
	public static void areEnemies(int X, int Y) {
		int A1, B1, A2, B2;
		A1 = FindSet(X);	A2 = FindSet(Y);
		B1 = FindSet(X + NumberOfPeople);
		B2 = FindSet(Y + NumberOfPeople);
		
		System.out.println((A1 == B2 || A2 == B1) ? "1" : "0");
	}
	
}
