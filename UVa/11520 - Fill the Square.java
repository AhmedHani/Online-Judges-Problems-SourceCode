//============================================================================
// File        : 11520 - Fill the Square.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.588
// Created on September 22, 2012, 09:20 PM
//============================================================================


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.*;


public class Main {
  public static int TestCases;
	public static char[] [] Grid;
	public static int Size;
	public static boolean Dot;
	public static char Chars;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner Input = new Scanner(System.in);
		TestCases = Input.nextInt();
		int Cases = 1;
		
		while(TestCases-- > 0){
			Size = Input.nextInt();
			Input.nextLine();
			Grid = new char[Size][Size];
			
			for(int i = 0; i < Size; i++)
				Grid[i] = Input.nextLine().toCharArray();
			
			for(int i = 0; i < Grid.length; i++){
				for(int j = 0; j < Grid[i].length; j++){
					if(Grid[i][j] == '.'){
						Dot = true;
						Chars = 'A';
						
						while(Dot){
							Dot = false;
							if(i > 0 && Grid[i - 1][j] == Chars){
								Chars++;
								Dot = true;
								continue;
							}
							if(i < Size - 1 && Grid[i + 1][j] == Chars){
								Chars++;
								Dot = true;
								continue;
							}
							if(j > 0 && Grid[i][j - 1] == Chars){
								Chars++;
								Dot = true;
								continue;
							}
							if(j < Size - 1 && Grid[i][j + 1] == Chars){
								Chars++;
								Dot = true;
								continue;
							}
						}
						Grid[i][j] = Chars;
					}
				}
			}
			System.out.println("Case " + Cases++ + ":");
			for(int i = 0; i < Grid.length; i++)
				System.out.println(new String(Grid[i]));
		
		}
		
		
		
	}
	
	
	
	
}
	
	


