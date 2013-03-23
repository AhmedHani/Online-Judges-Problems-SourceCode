//============================================================================
// File        : 10959 - The Party, Part I.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.432
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
	public static int NumberOfPersons, Connections;
	public static int First, Second;
	public static Queue<Integer> Q;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner Input = new Scanner(System.in);
		
		TestCases = Input.nextInt();
		while(TestCases-- > 0){
			NumberOfPersons    = Input.nextInt();
			Connections		   = Input.nextInt();
			boolean[][] Matrix = new boolean[NumberOfPersons][Connections];
			
			for(int i = 0; i < Connections; i++){
				First  = Input.nextInt();
				Second = Input.nextInt();
				Matrix[First][Second] = Matrix[Second][First] = true;
			}
			int[] Distance = new int[NumberOfPersons];
			Arrays.fill(Distance, -1);
			Distance[0] = 0;
			
			Q = new LinkedList<Integer>();
			Q.add(0);
			
			while(!Q.isEmpty()){
				int Current = Q.poll();
				
				for(int i = 0; i < NumberOfPersons; i++){
					if(Matrix[Current][i] == true && Distance[i] == -1){
						Distance[i] = Distance[Current] + 1;
						Q.add(i);
					}
				}
			}
			for(int i = 1; i < NumberOfPersons; i++){
				System.out.println(Distance[i]);
			}
			if(TestCases != 0)	System.out.println();
			
			
		}
		
		
	}
	
	
	
}
	
	


