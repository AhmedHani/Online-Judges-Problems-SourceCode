//============================================================================
// File        : 10896 - Known Plaintext Attack.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.132
// Created on September 21, 2012, 3:02 PM
//============================================================================

import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  static int TestCases;
	static boolean Answer;
	static String Encrpted;
	static String Word;
	static String[] EncryptedArray;
	
	public static void main(String args[]) throws NumberFormatException, IOException{
		BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder OutPut = new StringBuilder("");
		
		TestCases = Integer.parseInt(Input.readLine());
		
		while(TestCases-- > 0){
			Encrpted                           = Input.readLine();
			Word                               = Input.readLine();
			String [] EncrptedArray            = Encrpted.split(" ");
			PriorityQueue<Character> Container = new PriorityQueue<Character>();
			
			for(int i = 0; i < EncrptedArray.length; i++ ){
				if(EncrptedArray[i].length() == Word.length() && Word.length() != 0 ){
					int Tranformation = (EncrptedArray[i].charAt(0) - Word.charAt(0) + 26) % 26;
					Answer            = false;
					
					for(int k = 1; k  < Word.length(); k++){
						if((EncrptedArray[i].charAt(k) - Word.charAt(k) + 26) % 26 != Tranformation){
							Answer = true;
							break;
						}
					}
					
					if(Answer == false)	Container.add((char) (Tranformation + 'a'));
				}
			}
			while(!Container.isEmpty()){
				OutPut.append(Container.poll());
			}
			OutPut.append("\n");
			
		}
		System.out.print(OutPut);
		
		
	
	}
	
	
	
}
	
	


