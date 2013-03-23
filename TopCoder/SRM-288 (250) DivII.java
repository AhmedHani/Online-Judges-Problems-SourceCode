import java.util.*;
import java.util.regex.*;
import java.text.*;
import java.math.*;


public class AccountBalance
{
  public int processTransactions(int startingBalance, String[] transactions)
	{
		int REsult = startingBalance;
		for(int i = 0; i < transactions.length; i++) {
			String[] tr = transactions[i].split(" ");
			int Num = Integer.parseInt(tr[i]);
			if(tr[0].equals("C"))	REsult += Num;
			else					REsult -= Num;
		}
		return REsult;
		
	}
	
}
