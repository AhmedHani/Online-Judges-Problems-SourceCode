import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;


public class Main {
  public static int NumberOfHoles;
	public static boolean OK;
	public static double GXCoord, GYCoord;
	public static double DXCoord, DYCoord;
	public static double HXCoord, HYCoord;
	public static double DogDistance, GDistance;
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		Scanner Input = new Scanner(System.in);
		
		while(Input.hasNext()) {
			OK = false;
			NumberOfHoles = Input.nextInt();
			GXCoord = Input.nextDouble();
			GYCoord = Input.nextDouble();
			DXCoord = Input.nextDouble();
			DYCoord = Input.nextDouble();
			
			for(int i = 0; i < NumberOfHoles; i++) {
				HXCoord = Input.nextDouble();
				HYCoord = Input.nextDouble();
				DogDistance = (DXCoord - HXCoord) * (DXCoord - HXCoord) + (DYCoord - HYCoord) * (DYCoord - HYCoord);
				GDistance   = (GXCoord - HXCoord) * (GXCoord - HXCoord) + (GYCoord - HYCoord) * (GYCoord - HYCoord);
				
				if(4.0 * GDistance <= DogDistance) {
					System.out.printf(Locale.US, "The gopher can escape through the hole at (%.3f,%.3f).%n", HXCoord, HYCoord);
					OK = true;
				}
			}
			if(!OK)	System.out.println("The gopher cannot escape.");
		}

			
	}
	
 	
	
	

}
