//============================================================================
// File        : 846 - Steps.java
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
  public static int TestCases;
	public static int First, Second;
	public static int Diffrence, Counter, Result;
	public static boolean Expand;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		Scanner Input = new Scanner(System.in);
		TestCases = Input.nextInt();
		
		while(TestCases-- > 0) {
			First     = Input.nextInt();
			Second    = Input.nextInt();
			Expand    = false;
			Counter   = 1;
			Result    = 0;
			Diffrence = Second - First;
			while(Diffrence > 0) {
				Diffrence = Diffrence - Counter;
				Result++;
				if(Expand == true)
					Counter++;
				Expand = !Expand;
			}
			
			System.out.println(Result);
			
		}
		
		
	}

}
	
