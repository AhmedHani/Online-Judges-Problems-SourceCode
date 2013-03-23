//============================================================================
// File        : 1251 - Repeated Substitution with Sed.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 1.640
// Created on September 22, 2012, 06:20 PM
//============================================================================

import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.math.*;
import java.util.*;


public class Main {
  public static int NumberOfPaires;
	public static String[][] Pairs;
	public static  String From, To;
	public static Queue<String> Q;
	 static class All{
		String Word;
		int Counter;
		public All(String Wo, int C){
			Word    = Wo;
			Counter = C;
		}
	}
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer St = new StringTokenizer("");
		
		while(true){
			St = new StringTokenizer(Input.readLine());
			NumberOfPaires = Integer.parseInt(St.nextToken());
			if(NumberOfPaires == 0)		break;
			
			String[] [] Pairs = new String[NumberOfPaires][2];
			
			for(int i = 0; i < NumberOfPaires; i++){
				St = new StringTokenizer(Input.readLine());
				Pairs[i][0] = St.nextToken();
				Pairs[i][1] = St.nextToken();
			}
			From = Input.readLine();
			To	 = Input.readLine();
			
			System.out.println(SolveBFS(From, To, Pairs));
			
		}
		
	}
	
	private static int SolveBFS(String First, String Second, String[][] P ){
		Queue<All> Q = new LinkedList<All>();
		Q.add(new All(First, 0));
		
		while(!Q.isEmpty()){
			All Tmp = Q.poll();
			
			if(Tmp.Word.equals(Second))
				return Tmp.Counter;
			if(Tmp.Word.length() >= Second.length())
				continue;
			
			String Start;
			
			for(int i = 0; i < P.length; i++){
				Start = Tmp.Word.replaceAll(P[i][0], P[i][1]);
				if(!Start.equals(Tmp.Word))
					Q.add(new All(Start, Tmp.Counter + 1));
			}
		}
		return -1;
	
	}
	
	
	
}
	
	


