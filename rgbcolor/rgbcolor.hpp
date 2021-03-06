﻿// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _RGBCOLOR_HPP_
#define _RGBCOLOR_HPP_

/*****************************************************************************/

#include <ostream>
#include <iomanip>
#include <math.h>
using namespace std;

/*****************************************************************************/

class RGBColor
{
private:
	unsigned char red, green, blue;
	unsigned int packedColor;
	double BlackKey, CaynColor, MagentColor, YellowColor;

public:

	RGBColor(unsigned char red_color, unsigned char green_color, unsigned char blue_color)// конструктор класса с тремя переменными

	{
		//std::cout << "\nRed in constructor is: " << (int)red_color << "\n";
		//std::cout << "\nGreen in constructor is: " << (int)green_color << "\n";
		//std::cout << "\nBlue in constructor is: " << (int)blue_color << "\n";
		setRed(red_color); // вызов функции установки красного
		setGreen(green_color); // вызов функции установки зеленого
		setBlue(blue_color); // вызов функции установки синего
		unsigned int p_color = packed_color();
		setPackedRGB(p_color);
		BlackKey = blackKey();
		CaynColor = cyan_color();
		MagentColor = magent_color();
		YellowColor = yellow_color();

	}

	RGBColor(unsigned int packed_color) // конструктор класса с одной переменной
	{
		setPackedRGB(packed_color); // вызов функции установки запаковоного цвета
		setRGBFromPackedColor();
		BlackKey = blackKey();
		CaynColor = cyan_color();
		MagentColor = magent_color();
		YellowColor = yellow_color();
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
		unsigned int packed_color;
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

		if (packedColor > 16777215) {
			//std::cout « "You have entered not a valid color.\n";
			//exit(EXIT_FAILURE);
		}

		unsigned int packed_color = packedColor;

		unsigned char red_color = (packed_color / 65536);
		packed_color = packed_color - (int)(packed_color / 65536) * 65536;

		unsigned char green_color = (int)(packed_color / 256);
		packed_color = packed_color - (int)(packed_color / 256) * 256;

		unsigned char blue_color = (packed_color / 1);


		setRed(red_color);
		setGreen(green_color);
		setBlue(blue_color);
	}

	double blackKey() {
		double blackKey = 0.000;


		double max = findMax((double)((int)red / 255.0), ((int)green / 255.0), ((int)blue / 255.0));
		blackKey = 1 - max;
		blackKey = round(blackKey * 1000.0) / 1000.0;

		return blackKey;

	}

	double findMax(double n1, double n2, double n3) {


		if (n1 >= n2)
		{
			if (n1 >= n3) {

				return n1;

			}
			else {

				return n3;

			}

		}
		else
		{
			if (n2 >= n3) {


				return n2;
			}
			else {

				return n3;

			}
		}

	}

	double cyan_color() {
		double cyan_color = 0.0;
		if (BlackKey != 1.0) {
			cyan_color = (1.0 - red / 255.0 - BlackKey) / (1.0 - BlackKey);
		}
		return cyan_color;
	}

	double magent_color() {
		double magent_color = 0.0;
		if (BlackKey != 1.0) {
			magent_color = (1.0 - green / 255.0 - BlackKey) / (1.0 - BlackKey);
		}
		return magent_color;
	}

	double yellow_color() {
		double yellow_color = 0.0;
		if (BlackKey != 1.0) {
			yellow_color = (1.0 - blue / 255.0 - BlackKey) / (1.0 - BlackKey);
		}
		return yellow_color;

	}
	double getBlackKey() {

		return BlackKey;
	}
	double getCyanColor() {
		return CaynColor;
	}
	double getMagentaColor() {
		return MagentColor;
	}
	double getYellowColor() {
		return YellowColor;
	}

	bool operator == (RGBColor const & _color) const
	{
		return red == _color.red && blue == _color.blue && green == _color.green;
	}

	bool operator != (RGBColor const & _color) const
	{
		return !(*this == _color);
	}

	RGBColor operator + (RGBColor const & _other) const
	{
		RGBColor result(*this);

		result += _other;

		return result;
	}

	RGBColor operator += (RGBColor const & _other)
	{
		red += _other.red;
		green += _other.green;
		blue += _other.blue;

		packedColor = packed_color();

		return *this;
	}

	RGBColor  getInvertedColor() {
		return RGBColor(255 - red, 255 - green, 255 - blue);
	}
};

/*****************************************************************************/

inline
std::ostream&
operator << (std::ostream & _stream, RGBColor & _color)
{
	_stream << "#" << std::setiosflags(std::ios::uppercase) << std::setfill('0') << std::setbase(16) << std::setw(6) << _color.getPackedRGB();
	return _stream;
}

/*****************************************************************************/

#endif // _RGBCOLOR_HPP_