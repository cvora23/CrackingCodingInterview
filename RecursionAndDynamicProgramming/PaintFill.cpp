/*
 * PaintFill.cpp
 *
 *  Created on: Sep 13, 2017
 *      Author: chivora
 */
#include <iostream>
#include <vector>
#include <map>
#include <vector>
#include <list>
#include <set>

using namespace std;

/*
 * Paint Fill: Implement the "paint fill" function that one might see on many image editing programs.
 * That is, given a screen (represented by a two-dimensional array of colors), a point, and a new color,
 * fill in the surrounding area until the color changes from the original color.
 */

typedef enum _Color{
	Black,
	White,
	Red,
	Yellow,
	Green
}Color;

bool paintFill(Color screen[][3],int r,int c,Color oColor,Color nColor){

	if(r < 0 || r>= 3 || c < 0 || c >= 3){
		return false;
	}

	if(screen[r][c] == oColor){
		screen[r][c] = nColor;

		paintFill(screen,r-1,c,oColor,nColor); // Up
		paintFill(screen,r+1,c,oColor,nColor); // Down
		paintFill(screen,r,c-1,oColor,nColor); // Left
		paintFill(screen,r,c+1,oColor,nColor); // Right
	}

	return true;

}

bool paintFillColor(Color screen[][3],int r,int c,Color nColor){

	if(screen[r][c] == nColor){
		return false;
	}

	return paintFill(screen,r,c,screen[r][c],nColor);

}


int main(){

	Color screen[3][3];

	screen[0][0] = Black;
	screen[0][0] = Yellow;
	screen[0][0] = Red;

	screen[0][0] = White;
	screen[0][0] = Green;
	screen[0][0] = Yellow;

	screen[0][0] = Yellow;
	screen[0][0] = Green;
	screen[0][0] = Black;

	return 0;

}
