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
    unsigned int packedColor;
    public:

RGBColor(char red_color, char blue_color, char green_color)// конструктор класса с тремя переменными 

{
    setRed(red_color); // вызов функции установки красного
	setGreen (green_color); // вызов функции установки зеленого
	setBlue (blue_color); // вызов функции установки синего
	
void setRGBColor (char red_color, char blue_color, char green_color) // установка цвета
{
   red=red_color; // инициализация красного
   green=green_color; // инициализация зеленого
   blue=blue_color; // инициализация синего
}
	char getRed(){
        return red;
	} 
	char getGreen(){
        return green;
	} 
	
	char getBlue(){
        return blue;
	} 
	
}

RGBColor (unsigned int packed_Color); // конструктор класса с одной переменной 
{
	setRGBColor(packed_Color); // вызов функции установки запаковоного цвета
	
    void setRGBColor (unsigned int packed_Color) // установка цвета
 
    unsigned int getPackedRGB(){
         return white;
}
	
};

};


/*****************************************************************************/

#endif //  _RGBCOLOR_HPP_
