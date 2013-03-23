//============================================================================
// File        : 193 - Graph Coloring.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.588
// Created on September 22, 2012, 09:20 PM
//============================================================================

import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.math.*;
import java.util.*;


public class Main {
  public static int TestCases;
	public static int First, Second, MinimumNumberOfWhite;
	public static boolean[][] Matrix;
	public static int [] Color;
	public static int[] Chosen;
	public static int NumberOfNodes, Edges;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner Input = new Scanner(System.in);
		
		TestCases = Input.nextInt();
		while(TestCases-- > 0){
			NumberOfNodes = Input.nextInt();
			Edges		  = Input.nextInt();
			Matrix  = new boolean[NumberOfNodes + 1][NumberOfNodes + 1];
			
			for(int i = 0; i < Edges; i++){
				First  = Input.nextInt();
				Second = Input.nextInt();
				Matrix[First][Second] = Matrix[Second][First] = true;
			}
			Color = new int[NumberOfNodes + 1];
			MinimumNumberOfWhite = NumberOfNodes;
			
			Solve(1, 0);
			System.out.println(NumberOfNodes - MinimumNumberOfWhite);
			int CounterSpace = 0;
			
			for(int i = 1; i < Chosen.length; i++){
				if(Chosen[i] == 2){
					if(CounterSpace != 0)
						System.out.print(" " + i);
					else
						System.out.print(i);
					CounterSpace++;
				}
					
			}
			System.out.println();
			
			
			
		}
		
		
	}
	
	public static void Solve(int Index, int White){
		if(Index > NumberOfNodes){
			if(White < MinimumNumberOfWhite){
				MinimumNumberOfWhite = White;
				Chosen = Color.clone();
			}
		}else{
			boolean Black = true;
			for(int i = 0; i < Matrix.length; i++){
				if(Matrix[Index][i])	Black = Black && Color[i] != 2;
			}if(Black){
				Color[Index] = 2;
				Solve(Index + 1, White);
				Color[Index] = 0;
			}
			Color[Index] = 1;
			Solve(Index + 1, White + 1);
			Color[Index] = 0;
		}
	}
	
	
	
}
	
	


