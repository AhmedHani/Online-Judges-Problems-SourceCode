//============================================================================
// File        : 12160 - Unlock the Lock.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.576
// Created on September 22, 2012, 01:22 PM
//============================================================================

import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.io.Reader;
import java.math.*;
import java.util.*;


public class Main {
  public static int Max            = 10000;
	public static int TestCases;
	public static boolean Vistited[];
	public static Queue<Integer> Q;
	public static LinkedList<Integer> Matrix[];
	public static int Zero, Unlock, Value;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner Input = new Scanner(System.in);
		int Cases = 1;
		Zero = Input.nextInt();	Unlock = Input.nextInt();	Value = Input.nextInt();
		while(Zero != 0 || Unlock != 0 || Value != 0){
			
			int AddValue[] = new int[Value];
			Vistited = new boolean[Max];
			
			
			for(int i = 0; i < Value; i++){
				AddValue[i] = Input.nextInt();
			}
			
			Q     = new LinkedList<Integer>();
			Vistited[Zero] = true;
			Q.add(Zero);
			Q.add(0);
			boolean Found = false;
			
			while(!Q.isEmpty()){
				int Current = Q.poll();
				int Answer  = Q.poll();
				
				if(Current == Unlock){
					Found = true;
					System.out.printf("Case %d: %d\n", Cases++, Answer);
				   break;
				}
				
				for(int i = 0; i < Value; i++){
					int Currentstate = (Current + AddValue[i]) % 10000;
	                if(!Vistited[Currentstate]){
	                	Q.add(Currentstate);
	                	Q.add(Answer + 1);
	                	Vistited[Currentstate] = true;
	                }
				}
				
					
			}
			
			
			if(!Found)
				System.out.printf("Case %d: Permanently Locked\n", Cases++);
			Zero = Input.nextInt();	Unlock = Input.nextInt();	Value = Input.nextInt();
			
		}
		
		
	}
	
		
}
	
