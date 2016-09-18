// D23.java
// This program will demonstrate what the recursion process is
import java.awt.*;
import java.util.*;

public class D23 extends java.applet.Applet
{	
	Graphics g;
	int appletWidth, appletHeight;
	int r, n, d;
	
	Random rnd = new Random(255);
	
	public void paint(Graphics g)
	{
		int x = 0, y = 0, x1 = 0, y1, width, height;
		
		background(g);											//Call Background
					
		width = appletWidth / 5;								//Calculates Width
		height = appletHeight / 5;								//Calculates Height

		
		drawrectangles(g, x, y, width, height);					//Call Draw Rectangles
		
		y1 = appletHeight - (appletHeight / 5);					//Calculates Starting Point from 2nd
		drawrectangles2(g, x1, y1, width, height);				//Call Draw Rectangles 2
		
	}
	
	//This function will draw rectangles
	public void drawrectangles(Graphics g, int x, int y, int width, int height)
	{
		r = rnd.nextInt(255);
		n = rnd.nextInt(255);
		d = rnd.nextInt(255);
		
		g.setColor(new Color(r,n,d));
		g.fillRect(x, y, width, height);
		
		if (width > 1)
		{
			x += width;											//Increases x by width
			y += height;										//Increases y by height
			width *= 0.8;										//Calculates Width 80% of previous
			height *= 0.8;										//Calculates Height 80% of previous
			
			drawrectangles(g, x, y, width, height);				//Re-Call the function
		}
	}
	
	//This function will draw rectangles upward
	public void drawrectangles2(Graphics g, int x1, int y1, int width, int height)
	{
		r = rnd.nextInt(255);
		n = rnd.nextInt(255);
		d = rnd.nextInt(255);
		
		g.setColor(new Color(r,n,d));
		g.fillRect(x1, y1, width, height);
		
		if (width > 1)
		{
			height *= 0.8;										//Calculates Height 80% of previous
			x1 += width;										//Increases x by width
			y1 -= height;										//Increases y by height
			width *= 0.8;										//Calculates Width 80% of previous
			
			drawrectangles2(g, x1, y1, width, height);			//Re-Call the function
		}
	}
	
    public void delay(int n)
    {
	   long startDelay = System.currentTimeMillis();
	   long endDelay = 0;
	   while (endDelay - startDelay < n)
		 endDelay = System.currentTimeMillis();
    }
    
    //This function will set the background
    public void background(Graphics g)
    {
    	appletWidth = getWidth();								//Gets Width of Screen
    	appletHeight = getHeight();								//Gets Height of Screen
    	
    	g.setColor(Color.black);								//Sets Background Color
    	g.fillRect(0, 0, appletWidth, appletHeight);			//Fills Background
    }
							
}