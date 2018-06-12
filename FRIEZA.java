/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class FRIEZA
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		Set<String> goodChars = new HashSet<>(Arrays.asList("f","r","i","e","z","a"));
		
		while(t>0){
			t--;
			
			String s = sc.next();
		//	System.out.println(s);
		
		int goodCounter = 0;
		int badCounter = 0;
		
		String character = Character.toString(s.charAt(0));
		if(goodChars.contains(character)){
		goodCounter = 1;	
		}else{
		badCounter = 1;	
		}
		
		for (int i=1;i<s.length();i++){
			 character = Character.toString(s.charAt(i));
			//System.out.println(character);
			
			if(goodChars.contains(character) && badCounter>0){
				System.out.print(badCounter);
				badCounter = 0;
				goodCounter++;
			}else if(goodChars.contains(character) && goodCounter>0){
			    	goodCounter++;
			}else if(!(goodChars.contains(character)) && goodCounter>0){
				System.out.print(goodCounter);
				goodCounter = 0;
				badCounter++;
			}else if(!(goodChars.contains(character)) && badCounter>0){
				badCounter++;
			}
			
			
				
		}
		if(goodCounter==0){
				System.out.print(badCounter);
			}else{
				System.out.print(goodCounter);	
			}
		
			System.out.println();
			
		}
	}
}