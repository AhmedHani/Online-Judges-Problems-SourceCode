//============================================================================
// File        : 10559 - Blocks.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 1.956
// Created on September 16, 2012, 12:42 AM
//============================================================================

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  static int Max = 205;
	static int TestCases;
	static int NumberOfBlocks;
	static int [] Blocks = new int [Max];
	static int [] [] [] DPMemo = new int [Max][Max][Max];
	
	public static void main(String args[]) throws IOException{
		Scanner Input = new Scanner ( System.in);
		int Cases = 1;
		TestCases = Input.nextInt();
		
		while ( TestCases-- > 0 ){
			NumberOfBlocks = Input.nextInt();
			
			for (int i = 0; i < NumberOfBlocks; i++){
				Blocks[i] = Input.nextInt();
			}
			for ( int i = 0; i <= NumberOfBlocks; i++ ){
				for ( int j = 0; j <= NumberOfBlocks; j++ ){
					for ( int k = 0; k <= NumberOfBlocks; k++ ){
						DPMemo[i][j][k] = -1;
					}
				}
			}
			System.out.printf("Case %d: %d\n", Cases++, Solve(0, NumberOfBlocks - 1, 1));
			
			
		}
		
		
		}
	
	public static int Solve (int LeftMost, int RightMost, int Length){
		int Maximum;
		int Score = Length * Length;
		if ( LeftMost == RightMost )	return Score;
		if ( LeftMost > RightMost )	return 0;
		if ( DPMemo[LeftMost][RightMost][Length] != -1 )	return DPMemo[LeftMost][RightMost][Length];
		
		Maximum = Score + Solve(LeftMost + 1, RightMost, 1);
		
		for ( int i = LeftMost + 1; i <= RightMost; i++ ){
			if ( Blocks[i] == Blocks[LeftMost] )
				Maximum = Math.max(Maximum, Solve(i, RightMost, Length + 1) + Solve(LeftMost + 1, i - 1, 1));
		}
		return DPMemo[LeftMost][RightMost][Length] = Maximum;
		
		
		
	}
		
		
}
	
	


