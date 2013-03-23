//============================================================================
// File        : 11218 - KTV.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 1.500
// Created on September 17, 2012, 2:30 AM
//============================================================================

import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  
	static int Max = 9;
	static int INF = 1 << 20;
	static int Combinations;
	static int[] DPMemo = new int[1 << 9];
	static int [] [] [] Score = new int [Max][Max][Max];
	static int First, Second, Third, Cost;
	
	public static void main(String args[]) throws IOException{
		Scanner Input = new Scanner ( System.in);
		int Cases = 1;
		
		
		while ( Input.hasNext() ){
			Combinations = Input.nextInt();
			if ( Combinations == 0 )	break;
			
			for ( int i = 0; i < Max; i++)
				for ( int j = 0; j < Max; j++ )
					for ( int k = 0; k < Max; k++)
						Score[i][j][k] = 0;
			for ( int i = 0; i < 1 << 9; i++ )	DPMemo[i] = -1;
			
			for ( int i = 0; i < Combinations; i++){
				First = Input.nextInt();
				Second = Input.nextInt();
				Third = Input.nextInt();
				Cost = Input.nextInt();
				First--;	Second--;	 Third--;
				
				Score[First][Second][Third] = Cost;
				Score[First][Third][Second] = Cost;
				Score[Second][First][Third] = Cost;
				Score[Second][Third][First] = Cost;
				Score[Third][Second][First] = Cost;
				Score[Third][First][Second] = Cost;
			}
			
			if ( Solve(0) > 0 ){
				 System.out.printf("Case %d: %d\n", Cases++, Solve(0));
			}
			else	System.out.printf("Case %d: %d\n", Cases++, -1);
			
			
			
			
		}
		
		}
	
	private static int Solve(int Mask){
		
		if ( Mask == (1 << 9) - 1 )	return 0;
		if ( DPMemo[Mask] != -1 )	return DPMemo[Mask];
		else{
			int Maximum = -INF;
			for ( int i = 0; i < 9; i++ )
				if ( (Mask & (1 << i)) == 0)
					for ( int j = i + 1; j < 9; j++ )
						if ( (Mask & (1 << j)) == 0 )
							for ( int k = j + 1; k < 9; k++ )
								if ( Score[i][j][k] != 0 && ((Mask & (1 << k)) == 0 ))
									Maximum = Math.max(Maximum, Score[i][j][k] + Solve(Mask|(1 << i)|(1 << j)|(1 << k)));
			return DPMemo[Mask] = Maximum;
			
		}
		
	}
	
	
	
	
		
		
}
	
	


