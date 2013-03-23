//============================================================================
// File        : 11292 - Dragon of Loowater.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.876
// Created on October 2, 2012, 01:21 AM
//============================================================================


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.*;


public class Main {
  public static int NumberOfHeads, NumberOfKnights;
	public static int[] Heads;
	public static int[] Knights;
	public static int Current, Answer;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner Input = new Scanner(System.in);
		
		while(Input.hasNext()){
			NumberOfHeads = Input.nextInt();	NumberOfKnights = Input.nextInt();
			if(NumberOfHeads == 0 && NumberOfKnights == 0)	break;
			
			Heads   = new int[NumberOfHeads];
			Knights = new int[NumberOfKnights];
			
			for(int i = 0; i < NumberOfHeads; i++)		Heads[i]   = Input.nextInt();
			for(int i = 0; i < NumberOfKnights; i++)	Knights[i] = Input.nextInt();
			
			if(NumberOfHeads > NumberOfKnights){
				System.out.println("Loowater is doomed!");
				continue;
			}
			
			Arrays.sort(Heads);		Arrays.sort(Knights);
			
			Current = 0;
			Answer  = 0;
			boolean Output = true;
			
			for(int i = 0; i < NumberOfHeads; i++){
				if(NumberOfHeads - i > NumberOfKnights - Current){
					Answer = -1;
					Output = false;
					break;
				}
				
				for(int j = Current; j < NumberOfKnights; j++){
					if(Knights[j] < Heads[i]){
						Current++;
						continue;
					}
					Answer += Knights[j];
					Current++;
					Output = true;
					break;
				}
			}
			if(Answer == -1 && Output == false)		System.out.println("Loowater is doomed!");
			else									System.out.println(Answer);
				
		}
		

		
		
	}
	
	
	
	
}
	
	


