//============================================================================
// File        : 12149 - Feynman.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.160
// Created on September 21, 2012, 10:33 PM
//============================================================================

import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  static int Number;
	static int Counter;
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner Input = new Scanner(System.in);
		
		while(true){
			Number  = Input.nextInt();
			if(Number == 0)	break;
			Counter = 0;
			for(int i = 1; i <= Number; i++){
				Counter += Math.pow(i, 2);
			}
			System.out.println(Counter);
			
		}
		
	
	}
	
	
	
}
	
	
