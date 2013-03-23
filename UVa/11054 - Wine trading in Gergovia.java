//============================================================================
// File        : 11054 - Wine trading in Gergovia.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.972
// Created on September 28, 2012, 09:20 PM
//============================================================================


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.*;


public class Main {
  public static long NumberOfPersons;
	public static long[] Bottles;
	public static long Sum;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner Input = new Scanner(System.in);
		
		while(Input.hasNext()){
			NumberOfPersons = Input.nextLong();
			if(NumberOfPersons == 0)	break;
			
			Bottles = new long[100000 + 1];
			
			for(int i = 0; i < NumberOfPersons; i++)
				Bottles[i] = Input.nextLong();
			
			long Result = 0;
			for(int i = 1; i < NumberOfPersons; i++){
				Sum         = Bottles[i - 1];
				Bottles[i] += Bottles[i - 1];
				
				Result += (Sum < 0) ? (Sum * -1) : Sum;
			}
			System.out.println(Result);
		}
				
	}
	
}
	
