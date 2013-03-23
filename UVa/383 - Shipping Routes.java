//============================================================================
// File        : 383 - Shipping Routes.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.208
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
  public static int Max            = 30 + 5;
	public static int TestCases;
	public static boolean Vistited[];
	public static Queue<Integer> Q;
	public static LinkedList<Integer> AdjList[];
	public static HashMap<String, Integer> Map;
	public static String Array[];
	public static String Words;
	public static int NumberOfWareH, Connections, Quaries, Start, End, Shipment;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner Input = new Scanner(System.in);
		int Cases = 0;
		AdjList = new LinkedList[Max];
		
		for(int i = 0; i < Max; i++)	AdjList[i] = new LinkedList<Integer>();
		
		Q     = new LinkedList<Integer>();
		Map   = new HashMap<String, Integer>();
		Array = new String[Max];
		Vistited = new boolean[Max];
		for(int i = 0; i < Max; i++)	AdjListv[i].clear();
		
		TestCases = Input.nextInt();
		boolean Line = false;
		String S[];
		int Index = 0;
		while(TestCases-- > 0){
			Cases++;
			System.out.println("\nDATA SET  " + Cases + "\n");
			NumberOfWareH = Input.nextInt();	Connections = Input.nextInt();	Quaries = Input.nextInt();
			Map.clear();
			
			for(int i = 0; i < NumberOfWareH; i++){
				AdjList[i].clear();
				Words = Input.next();
				Map.put(Words, i);
				Array[i] = Words;
			}
			for(int i = 0; i < Connections; i++){
				Start = Map.get(Input.next());
				End   = Map.get(Input.next());
				AdjList[Start].add(End);
				AdjList[End].add(Start);
			}
			for(int i = 0; i < Quaries; i++){
				Q.clear();
				Arrays.fill(Vistited, false);
				
				Shipment = Input.nextInt();
				Start    = Map.get(Input.next());
				End      = Map.get(Input.next());
				int R = BFS(Start, End);
				if(R == 0)	System.out.println("NO SHIPMENT POSSIBLE");
				else						System.out.println("$"+ R * Shipment * 100);
			}
			
			
			
			
		}
		
		
		
	
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
	
	


