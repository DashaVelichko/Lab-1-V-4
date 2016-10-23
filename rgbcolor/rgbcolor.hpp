// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _RGBCOLOR_HPP_
#define _RGBCOLOR_HPP_

/*****************************************************************************/

#include <iostream>

/*****************************************************************************/

class RGBColor
{
    private:
    char red,green,blue;
    unsigned int PackedColor;
    public:

RGBColor(char red_color, char green_color, char blue_color)// конструктор класса с тремя переменными 

{
    setRed(red_color); // вызов функции установки красного
	setGreen (green_color); // вызов функции установки зеленого
	setBlue (blue_color); // вызов функции установки синего
}
RGBColor (unsigned int packed_Color); // конструктор класса с одной переменной 
{
	setpackedColor(packed_Color); // вызов функции установки запаковоного цвета
}
	void setRed (char red_color) {
		red = red_color; // инициализация красного
	}
	void setGreen (char green_color) {
		green = green_color; // инициализация зеленого
	}
	void setBlue (char blue_color) {
		blue = blue_color; // инициализация синего
	}
	
    void setPackedColor (unsigned int packed_Color) {
		PackedColor = packed_Color; // инициализация packedColor
	}
	 
	 
	char getRed(){ 
        return red; // доступ к private переменной red
	} 
	char getGreen(){
        return green; // доступ к private переменной green
	} 
	
	char getBlue(){
        return blue; // доступ к private переменной blue
	} 
	



    unsigned int getPackedColor(){
         return PackedColor; // доступ к private переменной packedColor
}
	
};




/*****************************************************************************/

#endif //  _RGBCOLOR_HPP_
