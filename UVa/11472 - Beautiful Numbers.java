//============================================================================
// File        : 11472 - Beautiful Numbers.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.780
// Created on September 18, 2012, 1:44 AM
//============================================================================

import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  static int MaxMask   = 1030;
	static int MaxIndex  = 11;
	static int MaxDigits = 100 + 1;
	static int TestCases;
	static int Base, Digits;
	static long [] [] [] DPMemo;
	
	
	public static void main(String args[]) throws IOException{
		Scanner Input = new Scanner ( System.in);
		
		TestCases = Input.nextInt();
		while ( TestCases-- > 0 ){
			Base = Input.nextInt();	Digits = Input.nextInt();
			DPMemo = new long [Base + 1][Digits + 1][MaxMask];
			
			for (int j = 0; j < DPMemo.length; j++)
                for (int k = 0; k < DPMemo[j].length; k++)
                     Arrays.fill(DPMemo[j][k], -1);
			
			System.out.println(Solve(Base, Digits, 0, 0, 0));
		}
		
	
		
	}
	
	private static long Solve(int Base, int MaxDig, int Index, int Final, int Mask){
		if ( Index == MaxDig )	if ( Mask == (1 << Base) - 1)	return 1;	else	return 0;
		if ( DPMemo[Final][Index][Mask] != -1 )	return DPMemo[Final][Index][Mask];
		long Result = 0;
		
		if ( Mask == (1 << Base) - 1 )	Result++;
		
		for ( int i = 0; i < Base; i++ ){
			if ( (Index == 0 && i != 0) || Math.abs(Final - i) == 1 ){
				Result = (Result + Solve(Base, MaxDig, Index + 1, i, Mask|(1 << i) ) % 1000000007) % 1000000007;
			}
		}
		return DPMemo[Final][Index][Mask] = Result;
		
	}
}
	
	


