//============================================================================
// File        : 11850 - Alaska.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.332
// Created on October 21, 2012, 01:33 AM
//============================================================================


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;



public class Main {
  public static int NumberOfStations;
	public static int[] Stations;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		Scanner Input = new Scanner(System.in);
		
		while(true) {
			NumberOfStations = Input.nextInt();
			if(NumberOfStations == 0)	break;
			Stations = new int[NumberOfStations];
			
			for(int i = 0; i < NumberOfStations; i++)		Stations[i] = Input.nextInt();
			
			for(int i = 0; i < NumberOfStations; i++)
				Arrays.sort(Stations);
			
			boolean Check = true;
			
			for(int i = 1; i < NumberOfStations; i++)
				if(Stations[i] - Stations[i - 1] > 200)		Check = false;
			
			if(2 * (1422 - Stations[NumberOfStations - 1]) > 200)
				Check = false;
			
			if(Check)	System.out.println("POSSIBLE");
			else		System.out.println("IMPOSSIBLE");
		}
		
	}
		
}
	
