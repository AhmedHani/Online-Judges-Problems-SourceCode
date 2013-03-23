//============================================================================
// File        : 10496 - Collecting Beepers.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.256
// Created on September 17, 2012, 9:42 PM
//============================================================================

import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  
	static int TestCases, NumberOfBeepers, X, Y;
	static int Max            = 11;
	static int INF            = 1 << 30;
	static int [] XCoordinate = new int [Max];
	static int [] YCoordinate = new int [Max];
	static int [] [] Distance = new int [Max][Max];
	static int [] [] DPMemo   = new int [Max][1 << Max];
	
	public static void main(String args[]) throws IOException{
		Scanner Input = new Scanner ( System.in);
		
		TestCases = Input.nextInt();
		while ( TestCases -- > 0 ){
			X = Input.nextInt();	Y = Input.nextInt();
			XCoordinate[0] = Input.nextInt();	YCoordinate[0] = Input.nextInt();
			NumberOfBeepers = Input.nextInt();
			
			for ( int i = 1; i <= NumberOfBeepers; i++ ){
				XCoordinate[i] = Input.nextInt();	YCoordinate[i] = Input.nextInt();
			}
			for ( int i = 0; i <= NumberOfBeepers; i++ )
				for ( int j = 0; j <= NumberOfBeepers; j++ )
					Distance[i][j] = Math.abs(XCoordinate[i] - XCoordinate[j]) + Math.abs(YCoordinate[i] - YCoordinate[j]);
			
			for ( int i = 0; i <= 10; i++ )
				for ( int j = 0; j <= 1025; j++ )
					DPMemo[i][j] = -1;
			
			System.out.printf("The shortest path has length %d\n", Solve(0, 1));
			
		}
		
		
		}
	
	private static int Solve(int Index, int Mask){
		if (Mask == (1 << (NumberOfBeepers + 1)) - 1)	return Distance[Index][0];
		if ( DPMemo[Index][Mask] != -1 )	return DPMemo[Index][Mask];
		 DPMemo[Index][Mask] = INF;
		
		for ( int i = 0; i <= NumberOfBeepers; i++ ){
			if ( i != Index && (Mask & (1 << i)) == 0 )
				DPMemo[Index][Mask] = Math.min(DPMemo[Index][Mask], Solve(i, Mask ^ (1 << i)) + Distance[Index][i]);
		}
		return  DPMemo[Index][Mask];
	}
	
	
	
	
	
	
		
		
}
	
	


