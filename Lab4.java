// Son Huynh
// This program will demonstrate the use of methods(functions)

import java.awt.*;
import java.applet.*;


public class Lab4 extends Applet
{

	public void paint(Graphics g)
	{
		drawPyramid(g);										//Function call for Draw Pyramid
		drawBullseye(g);									//Function call for Draw Bullseye
		drawArrow(g);										//Function call for Draw Arrow
	}
	
	// ***** DRAWS PYRAMID *****
	public void drawPyramid(Graphics g)
	{
		g.drawLine(50, 180, 150, 60);						//Draws left side of Pyramid
		g.drawLine(150, 60, 250, 180);						//Draws middle line of Pyramid
		g.drawLine(250, 180, 50, 180);						//Draws bottom line of Pyramid
		
		g.drawLine(150, 60, 275, 100);						//Draws right line of Pyramid
		g.drawLine(275, 100, 250, 180);						//Draws 2nd line of Pyramid
	}
	
	// ***** DRAWS BULLSEYE *****
	public void drawBullseye(Graphics g)
	{
		g.setColor(Color.black);							//Sets Color to Black
		g.fillOval(400, 60, 250, 250);						//Draws Black Circle
		
		g.setColor(new Color(255, 255, 255));				//Sets Color to White
		g.fillOval(425, 85, 200, 200);						//Draws White Circle
		
		g.setColor(Color.blue);								//Sets Color to Blue
		g.fillOval(450, 110, 150, 150);						//Draws Blue Circle
		
		g.setColor(Color.red);								//Sets Color to Red
		g.fillOval(475, 135, 100, 100);						//Draws Red Circle
		
		g.setColor(Color.yellow);							//Sets Color to Yellow
		g.fillOval(500, 160, 50, 50);						//Draws Yellow Circle
		
	}
	
	// ***** DRAWS ARROW *****
	public void drawArrow(Graphics g)
	{
		g.setColor(Color.black);							//Sets Color to Black
		g.drawLine(525, 185, 585, 245);						//Draws Body of Arrow
		g.drawLine(525, 185, 540, 185);						//Draws Right Tip of Top
		g.drawLine(525, 185, 525, 200);						//Draws Left Tip of Top
		g.drawLine(585, 245, 600, 245);						//Draws Right Tip of Bottom
		g.drawLine(585, 245, 585, 260);						//Draws Left Tip of Bottom
	}

}
