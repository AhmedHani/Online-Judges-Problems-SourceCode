//============================================================================
// File        : 10871 - Primed Subsequence.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.220
// Created on October 3, 2012, 12:21 AM
//============================================================================


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.*;


public class Main {
  public static int TestCases;
	public static int Numbers;
	public static String[] Line;
	public static int [] Sequence;
	public static int[] Sum = new int[10001];
	public static boolean[] Primes = new boolean[10001];
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
		
		TestCases = Integer.parseInt(Input.readLine());
		while(TestCases-- > 0){
			boolean Found = false;
			//Seive();
			Line     = Input.readLine().split(" ");
			Numbers  = Integer.parseInt(Line[0]);
			Sequence = new int[Numbers];
			
			int Add = 0;
			for(int i = 1; i < Line.length; i++){
				Sequence[i - 1] = Integer.parseInt(Line[i]);
				Add += Sequence[i - 1];
				Sum[i - 1] = Add; 
			}
			
			for(int i = 1; i < Numbers; i++){
				for(int j = 0; j < (Numbers - i) && !Found; j++){
					if(IsPrime(Sum[i + j] - Sum[j] + Sequence[j])){
						Found = true;
						System.out.printf("Shortest primed subsequence is length %d:",(i + 1));
						for(int ii = j; ii <= i + j; ii++)
							System.out.printf(" %d",Sequence[ii]);
						System.out.println();
					}
				}
			}
			if(!Found)
				System.out.printf("This sequence is anti-primed.\n");
		}
		
		
		
	}
	
	//public static void Seive(){
		//Arrays.fill(Primes, false);
		//for(int i = 2; i * i < 10001; i++)
			//if(!Primes[i])
			//	for(int j = i * i; j < 10001; j += i)
		//			Primes[j] = true;
	//}
	
	public static boolean IsPrime(int number)
	{	
		
		for (int i=2; i<number; i++)
		{
			if (number % i == 0)
			{
				return false;
			}
		}
		
		return true;	
	}
	
	
	
	
}
	
	


