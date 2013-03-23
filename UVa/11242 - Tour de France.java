//============================================================================
// File        : 11242 - Tour de France.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.380
// Created on September 30, 2012, 04:21 PM
//============================================================================


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import java.util.*;


public class Main {
  public static int FrontSpockets, RearSpocketss;
	public static int []NumberOfTeethF;
	public static int []NumberOfTeethR;
	public static double[] Result; 

	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner Input = new Scanner(System.in);
		
		while(Input.hasNext()){
			FrontSpockets = Input.nextInt();	if(FrontSpockets == 0)	break;
			RearSpocketss = Input.nextInt();
			
			NumberOfTeethF = new int[FrontSpockets];
			NumberOfTeethR = new int[RearSpocketss];
			Result		   = new double[FrontSpockets * RearSpocketss];
			
			for(int i = 0; i < FrontSpockets; i++)		NumberOfTeethF[i] = Input.nextInt();
			for(int i = 0; i < RearSpocketss; i++)		NumberOfTeethR[i] = Input.nextInt();
			
			int Index = 0;
			for(int i = 0; i < NumberOfTeethF.length; i++)
				for(int j = 0; j < NumberOfTeethR.length; j++)
					Result[Index++] = (NumberOfTeethR[j] * 1.0 / NumberOfTeethF[i]);
			
			Arrays.sort(Result);
			
			double Maximum = 0;
			for(int i = 0; i < Result.length - 1; i++)
				Maximum = Math.max(Maximum, Result[i + 1] / Result[i]);
			System.out.printf("%.2f\n", Maximum);
			
			
		}

		
		
	}
	
	
	
	
}
	
	


