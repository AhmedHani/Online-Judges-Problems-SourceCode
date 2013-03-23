//============================================================================
// File        : 429 - Word Transformation.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.556
// Created on September 21, 2012, 12:40 AM
//============================================================================

import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.math.*;
import java.util.*;


public class Main {
  public static int Max            = 200 + 5;
	public static int TestCases;
	public static boolean Vistited[];
	public static Queue<Integer> Q;
	public static LinkedList<Integer> AdjList[];
	public static HashMap<String, Integer> Map;
	public static String Array[];
	public static String Words;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
		AdjList = new LinkedList[205];
		
		for(int i = 0; i < Max; i++)	AdjList[i] = new LinkedList<Integer>();
		
		Q     = new LinkedList<Integer>();
		Map   = new HashMap<String, Integer>();
		Array = new String[Max];
		Vistited = new boolean[Max];
		for(int i = 0; i < Max; i++)	Matrix[i].clear();
		
		TestCases = Integer.parseInt(Input.readLine());
		boolean Line = false;
		String Tmp = Input.readLine();
		String S[];
		int Index = 0;
		while(TestCases-- > 0){
			if(Line)	System.out.println();
			Line = true;
			Map.clear();
			Index = 0;
			while(!(Words = Input.readLine()).equals("*")){
				Map.put(Words, Index);
				Array[Index] = Words;
				
				for(int i = 0; i < Index; i++){
					if(Check(Words, Array[i])){
						AdjList[Index].add(i);
						AdjList[i].add(Index);
					}
				}
				Index++;
			}
			
			while(((Words = Input.readLine()) != null) && (!Words.equals(Tmp))){
				Q.clear();
				
				for(int i = 0; i < Index; i++){
					Vistited[i] = false;
				}
				S = Words.split(" ");
				System.out.println(S[0] + " " + S[1] + " " + BFS(Map.get(S[0]), Map.get(S[1])));
				
				
			}
			
			
		}
		
		
		
	
	}
	
	public static boolean Check(String First, String Second){
		int Counter = 0;
		
		Counter = Math.abs(First.length() - Second.length());
		if( Second.length() >= First.length() ){
			for(int i = 0; i < First.length(); i++)
				if(First.charAt(i) != Second.charAt(i))	Counter++;
		}else{
			for(int i = 0; i < Second.length(); i++)
				if(First.charAt(i) != Second.charAt(i))
					Counter++;
		}
		return Counter == 1;
	}
	
	public static int BFS(int Start, int End){
		Q.add(Start);
		Q.add(0);
		Vistited[Start] = true;
		
		int Current = 0;	int Answer = 0;
		
		while(!Q.isEmpty()){
			Current = Q.poll();
			Answer  = Q.poll();
			
			for(int Node : AdjList[Current])
				if(!Vistited[Node]){
					if(Node == End)
						return Answer + 1;
					Vistited[Node] = true;
					Q.add(Node);
					Q.add(Answer + 1);
				}
		}
		return 0;
	}
	
	
	
}
	
	


