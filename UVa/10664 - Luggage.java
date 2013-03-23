//============================================================================
// File        : 10664 - Luggage.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.404
// Created on September 18, 2012, 10:50 PM
//============================================================================

import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  static int Max = 1000;
	static int TestCases;
	static int Sum;
	static int [] Weights = new int [Max];
	String [] Line;
	static int [] [] DPMemo = new int [Max][Max];

	
	public static void main(String args[]) throws NumberFormatException, IOException{
		BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
		TestCases = Integer.parseInt(Input.readLine());
		
		while (TestCases-- > 0){
			String [] Line = Input.readLine().split(" ");
			
			for ( int i = 0; i < Line.length; i++ )
				Weights[i] = Integer.parseInt(Line[i]);
			
			for ( int i = 0; i < Max; i++ )
				for ( int j = 0; j < Max; j++ )
					DPMemo[i][j] = -1;
			
			Sum = 0;
			for ( int i = 0; i < Line.length; i++ )
				Sum += Weights[i];
			
			if ( Sum % 2 != 0)	System.out.printf("NO\n");
			else if ( Solve(Sum / 2, Line.length - 1) != Sum / 2)
				System.out.printf("NO\n");
			else
				System.out.printf("YES\n");
			
			
			
		}
		
	}
	
	private static int Solve(int W, int Index){
		if ( Index < 0 )	return 0;
		if ( DPMemo[W][Index] != -1 )		return DPMemo[W][Index];
		if ( W >= Weights[Index]){
			return DPMemo[W][Index] = Math.max(Weights[Index] + Solve(W - Weights[Index], Index - 1), Solve(W, Index - 1));
		}else{
			return DPMemo[W][Index] = Solve(W, Index - 1);
		}
	}
	
	
}
	
	


