// Son Huynh
// This program will compute the hours, minutes, seconds, and milli seconds from Milli Sec
import java.awt.*;

public class Lab3 extends java.applet.Applet
{	
	public static void main(String args[])
	{
		int hours, minutes, seconds, remainderseconds;
		int startmilli = 10000123, millisec, remaindermilli;
		
		System.out.println("This program will compute the \nhours, minutes, seconds, and milli seconds from Milli Sec");		//Outputs Purpose
		System.out.println("Starting Milli-Seconds: " + startmilli);		//Inputs Starting Milli-Seconds
		
		hours = startmilli / 3600000;										//Computes Hours
		millisec = startmilli % 3600000;									//Computes Seconds
		seconds = millisec / 1000;											//Computes Seconds
		remaindermilli = millisec % 1000;									//Computes Remainder Milli
		minutes = seconds / 60;												//Computes Minutes
		remainderseconds = seconds % 60;									//Computes Remainder Seconds

		
		System.out.println("Hours: " + hours);								//Outputs Hours
		System.out.println("Minutes: " + minutes);							//Outputs Minutes
		System.out.println("Seconds: " + remainderseconds);					//Outputs Remainder Seconds
		System.out.println("Milli-Seconds: " + remaindermilli);				//Outputs Remainder Milli
	}
							
}