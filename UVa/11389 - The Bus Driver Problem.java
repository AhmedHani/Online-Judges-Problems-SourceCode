//============================================================================
// File        : 11389 - The Bus Driver Problem.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.588
// Created on September 28, 2012, 09:20 PM
//============================================================================


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.*;


public class Main {
  public static int NumberOfBusDrivers, Distance, Over;
	public static int[] Morning;
	public static int[] Evening;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner Input = new Scanner(System.in);
		
		while(true){
			NumberOfBusDrivers = Input.nextInt();
			Distance		   = Input.nextInt();
			Over			   = Input.nextInt();
			if(NumberOfBusDrivers == 0 && Distance == 0 && Over == 0)	break;
			
			Morning = new int[NumberOfBusDrivers];
			Evening = new int[NumberOfBusDrivers];
			
			for(int i = 0; i < NumberOfBusDrivers; i++)		Morning[i] = Input.nextInt();
			for(int i = 0; i < NumberOfBusDrivers; i++)		Evening[i] = -Input.nextInt();
			
			Arrays.sort(Morning);	Arrays.sort(Evening);
			
			int Value = 0;
			for(int i = 0; i < NumberOfBusDrivers; i++){
	            int Result = Morning[i] + (-Evening[i]);
	            if(Result > Distance)
	                Value += (Result - Distance) * Over;
	        }
			System.out.println(Value);
		}

		
		
	}
	
	
	
	
}
	
	


