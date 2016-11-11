 // (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#ifndef _RGBCOLOR_HPP_
#define _RGBCOLOR_HPP_

/*****************************************************************************/

#include <iostream>



/*****************************************************************************/

class RGBColor
{
private:
	unsigned char red, green, blue, cyan, magenta, yellow, blackkey;
	unsigned int packedColor;

public:

	RGBColor(unsigned char red_color, unsigned char green_color, unsigned char blue_color)// конструктор класса с тремя переменными

	{
		setRed(red_color); // вызов функции установки красного
		setGreen(green_color); // вызов функции установки зеленого
		setBlue(blue_color); // вызов функции установки синего
		unsigned int p_color = packed_color();
		setPackedRGB(p_color);
		setCyanColor(cyan_color);
		setMagentaColor(magenta_color);
		setYellowColor(yellow_color);
		setBlackKey(blackkey_color);

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
			std::cout << "\n You have entered not a valid color.\n";
			exit(EXIT_FAILURE);
		}

		unsigned int packed_color = packedColor;

		unsigned char red_color = (packed_color / 65536);
		packed_color = packed_color - (int)(packed_color / 65536) * 65536;

		unsigned char green_color = (int)(packed_color / 256);
		packed_color = packed_color - (int)(packed_color / 256) * 256;

		unsigned char blue_color = (packed_color / 1);

		//std::cout << "\nRed is  " << (int)red_color <<" \n";
		//std::cout << "Green is  " << (int)green_color <<" \n";
		//std::cout << "Blue is  " << (int)blue_color <<" \n";


		setRed(red_color);
		setGreen(green_color);
		setBlue(blue_color);

		void setCyanColor(unsigned char cyan_color) {
			cyan = cyan_color; // инициализация желтого 
		}
		void setMagentaColor(unsigned char magenta_color) {
				magenta = magenta_color; // инициализация пурпурного 
		}
		void setYellowColor(unsigned char yellow_color) {
				yellow = yellow_color; // инициализация желтого 
		}
		void setBlackKey(unsigned char blackkey_color) {
				blackkey = blackkey_color; // инициализация черного
		}



		unsigned char getCyan() {
			return C = (1 - R / 255.0 - K) / (1 - K);
			}
		unsigned char getMagentColor() {
			return M = (1 - G / 255.0 - K) / (1 - K);
			}
		unsigned char getYellowColor() {
			return Y = (1 - B / 255.0 - K) / (1 - K);
			}
		unsigned char  getBlackKey() {
			return  K = 1 - max(R / 255.0, G / 255.0, B / 255.0);
			}
		}



		};

/*****************************************************************************/

#endif //  _RGBCOLOR_HPP_