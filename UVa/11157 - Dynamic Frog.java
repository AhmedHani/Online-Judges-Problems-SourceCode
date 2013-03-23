//============================================================================
// File        : 11157 - Dynamic Frog.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.760
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
	public static int NumberOfRocks, Distance;
	public static String[] LineRocks;
	public static Vector<Integer> V;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner Input = new Scanner(System.in);
		int Cases = 1;
		
		TestCases = Input.nextInt();
		while(TestCases-- > 0){
			NumberOfRocks = Input.nextInt();
			Distance	  = Input.nextInt();
			V 			  = new Vector<Integer>();
			
			V.add(0);	V.add(0);
			
			for(int i = 0; i < NumberOfRocks; i++){
				LineRocks = Input.next().split("-", -1);
				int D = Integer.parseInt(LineRocks[1]);
				V.add(D);
				if(LineRocks[0].equals("B"))
					V.add(D);
			}
			V.add(Distance);	V.add(Distance);
			
			int Result = -10000000;
			for(int i = 2; i < V.size(); i++){
				Result = Math.max(Result, V.get(i) - V.get(i - 2));
			}
			System.out.printf("Case %d: %d\n", Cases++, Result);
			
		}
		
	}
	
	
	
	
}
	
	


