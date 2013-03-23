//============================================================================
// File        : 10911 - Forming Quiz Teams.java
// Author      : AHMED HANI IBRAHIM
// Copyright   : AHani
// Version     : UVa - Accepted - 0.956
// Created on September 21, 2012, 3:02 PM
//============================================================================

import java.io.BufferedReader;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.math.*;
import java.util.*;


public class Main {
  static int Max              = 10000;
	static double[] DPMemo      = new double[1 << 16];
	static double[] [] Distance = new double[Max][Max];
	static int X;              
	static int Y;
	static int NumberOfTeams;

	public static void main(String args[]) throws NumberFormatException, IOException{
		BufferedReader Input = new BufferedReader(new InputStreamReader(System.in));
		int Cases = 1;
		
		while (true){
			NumberOfTeams = Integer.parseInt(Input.readLine());
			if (NumberOfTeams == 0)break;
			
			int[] [] XY = new int[2 * NumberOfTeams][2];
			
			for(int i = 0; i < 2 * NumberOfTeams; i++ ){
				String[] Line = Input.readLine().split(" ");
				X = Integer.parseInt(Line[1]);
				Y = Integer.parseInt(Line[2]);
				XY[i][0] = X;
				XY[i][1] = Y;
			}
			for (int i = 0; i < 2 * NumberOfTeams; i++ ){
				for(int j = i + 1; j < 2 * NumberOfTeams; j++ ){
					Distance[i][j] = Math.sqrt((XY[i][0] - XY[j][0]) * (XY[i][0] - XY[j][0]) + (XY[i][1] - XY[j][1]) * (XY[i][1] - XY[j][1]));
				}
			}
			Arrays.fill(DPMemo, -1);
			 BigDecimal Rounding = new BigDecimal(Solve(0));

	            System.out.println("Case " + (Cases++) + ": " + Rounding.setScale(2, BigDecimal.ROUND_HALF_UP));

			
		}
	
	}
	
	private static double Solve(int Mask){
		if(Mask == (1 << 2 * NumberOfTeams) - 1)	return 0;
		if(DPMemo[Mask] != -1)	return DPMemo[Mask];
		
		DPMemo[Mask] = 1 << 30;
		for(int i = 0; i < NumberOfTeams * 2; i++ )
			if((Mask & (1 << i)) == 0)
				for(int j = i + 1; j < NumberOfTeams * 2; j++)
					if( (Mask & (1 << j)) == 0 )
						DPMemo[Mask] = Math.min(DPMemo[Mask], Distance[i][j] + Solve(Mask|(1 << i)|(1 << j)));
		return DPMemo[Mask];
	}
	
	
	
	
}
	
	


