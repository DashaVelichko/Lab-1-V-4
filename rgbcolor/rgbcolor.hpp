// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _RGBCOLOR_HPP_
#define _RGBCOLOR_HPP_

/*****************************************************************************/

#include <iostream> 

/*****************************************************************************/

class RGBColor
{
private:
	char red, green, blue;
	unsigned int packedColor;

public:

	RGBColor(unsigned char red_color, unsigned char green_color, unsigned char blue_color)// конструктор класса с тремя переменными 

	{
		setRed(red_color); // вызов функции установки красного 
		setGreen(green_color); // вызов функции установки зеленого 
		setBlue(blue_color); // вызов функции установки синего 
		packed_color = packed_color();
		setPackedRGB(packed_color);
	}
	RGBColor(unsigned int packed_color) // конструктор класса с одной переменной 
	{
		setPackedRGB(packed_color); // вызов функции установки запаковоного цвета 
		setRGBFromPackedColor();
	}
	void setRed(unsigned char red_color) {
		red = red_color; // инициализация красного 
	}
	void setGreen(unsigned char green_color) {
		green = green_color; // инициализация зеленого 
	}
	void setBlue(unsigned char blue_color) {
		blue = blue_color; // инициализация синего 
	}

	void setPackedRGB(unsigned int packed_color) {
		packedColor = packed_color; // инициализация packedColor 
	}

	unsigned int packed_color() {

		packed_color = ((red * 65536) + (green * 256) + blue);

		return packed_color;
	}

	unsigned char getRed() {
		return red; // доступ к private переменной red 
	}
	unsigned char getGreen() {
		return green; // доступ к private переменной green 
	}

	unsigned char getBlue() {
		return blue; // доступ к private переменной blue 
	}




	unsigned int getPackedRGB() {
		return packedColor; // доступ к private переменной packedColor 
	}

	void setRGBFromPackedColor() { // посчитать реальное значение здесь
		red_color = 0;
		green_color = 0;
		blue_color = 0;
		setRed(red_color);
		setGreen(green_color);
		setBlue(blue_color);
	}



};


/*****************************************************************************/

#endif //  _RGBCOLOR_HPP_
