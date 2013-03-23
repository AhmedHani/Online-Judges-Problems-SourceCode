//============================================================================
// File        : 10651 - Pebble Solitaire.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 1.164
// Created on September 16, 2012, 12:42 AM
//============================================================================

import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  
	static int Max = 1 << 25;
	static int TestCases;
	static int[] DPMemo = new int[Max];
	static int Counter;
	static String Text;
	
	public static void main(String args[]) throws IOException{
		Scanner Input = new Scanner ( System.in);
		
		TestCases = Input.nextInt();
		while ( TestCases-- > 0 ){
			Counter = 0;
			Text = Input.next();
			
			for ( int i = 0; i < Text.length(); i++ )
				if ( Text.charAt(i) == 'o' )	Counter |= (1 << i);	
			
			for ( int i = 0; i < Max; i++ )	DPMemo[i] = -1;
			
			System.out.printf("%d\n",Solve(Counter));
		}
		
		
		}
	
	private static int Solve (int Mask){
		
		if ( DPMemo[Mask] != -1 )	return DPMemo[Mask];
		else{
		
		int counter = 0;
		
		for ( int i = 0; i < 12; i++ ){
			if ( (Mask & (1 << i)) != 0)	counter++;
		}
		for ( int i = 0; i < 12; i++ ){
			if ( i >= 2 && ((Mask ^ (3 << (i - 2))) & (7 << (i - 2))) == 0 )
				counter = Math.min(counter, Solve(Mask ^ (7 << (i - 2))));
			if ( i <= 9 && ((Mask ^ (6 << (i))) & (7 << (i))) == 0 )
				counter = Math.min(counter,Solve(Mask ^ (7 << i)) );
		}
		
		return DPMemo[Mask] = counter;
	}
	}
	
	
		
		
}
	
	


