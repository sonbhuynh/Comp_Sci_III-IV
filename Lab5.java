// Son Huynh
// This program will demonstrate the use of looping

import java.awt.*;
import java.applet.*;


public class Lab5 extends Applet
{
	int appletWidth, appletHeight;
	
	public void paint(Graphics g)
	{
		background(g);								//Call Background
		drawlines(g);								//Call Draw Lines

	}

	
	public void drawlines(Graphics g)
	{	
		for (int x = 0; x <= appletHeight; x += 20)
		{
			g.drawLine(0, 0, appletWidth, x);					//Draws from top left corner to right side
			g.drawLine(appletWidth, 0, 0, x);					//Draws from top right corner to left side
			g.drawLine(0, appletHeight, appletWidth, x);		//Draws from bottom left corner to right side
			g.drawLine(appletWidth, appletHeight, 0, x);		//Draws from bottom right corner to left side
		}		
	}
	
	public void background(Graphics g)
	{
		appletWidth = getWidth();
		appletHeight = getHeight();
	}


}
