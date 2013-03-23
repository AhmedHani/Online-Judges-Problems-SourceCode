//============================================================================
// File        : 10116 - Robot Motion.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.188
// Created on September 19, 2012, 12:49 AM
//============================================================================

import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  static int Rows, Columns, Start, X, Y, Movements;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
		
		while (true){
			StringTokenizer Con = new StringTokenizer(Input.readLine());
			Rows    = Integer.parseInt(Con.nextToken());
			Columns = Integer.parseInt(Con.nextToken());
			Start   = Integer.parseInt(Con.nextToken());
			
			if ( Rows == 0 && Columns == 0 && Start == 0 )	break;
			
			char[] [] Grid    = new char[Rows][Columns];
			boolean [] []Visited = new boolean[Rows][Columns];
			int [] []Counter = new int[Rows][Columns];
			
			X = 0;	Y = Start - 1;
			
			for ( int i = 0; i < Rows; i++ )
				Grid[i] = Input.readLine().toCharArray();
			
			Visited[X][Y] = true;
			Movements     = 0;
			
			while (true){
				if ( Grid[X][Y] == 'N' )	X--;
				else if ( Grid[X][Y] == 'S' )	X++;
				else if ( Grid[X][Y] == 'E' )	Y++;
				else if ( Grid[X][Y] == 'W' )	Y--;
				
				Movements++;
				
				if ( X < 0 || Y < 0 || X >= Rows || Y >= Columns ){
					System.out.println(Movements + " step(s) to exit");
					break;
				}
				if ( Visited[X][Y] == true ) {
					System.out.println(Counter[X][Y] + " step(s) before a loop of " + (Movements - Counter[X][Y]) + " step(s)");
					break;
				}
				Visited[X][Y] = true;
				Counter[X][Y] = Movements;
			}
			
		}
		
		
	}
	
	
	
	
}
	
	


