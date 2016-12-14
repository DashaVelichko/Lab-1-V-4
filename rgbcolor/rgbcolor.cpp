// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "rgbcolor.hpp"

/*****************************************************************************/
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
void CaynColor == MagentColor
if (1.0 - red / 255.0 - BlackKey) / (1.0 - BlackKey) == (1.0 - green / 255.0 - BlackKey) / (1.0 - BlackKey);

void YellowColor != MagentColor
if (1.0 - blue / 255.0 - BlackKey) / (1.0 - BlackKey) != (1.0 - green / 255.0 - BlackKey) / (1.0 - BlackKey);

RGBColor  getInvertedColor() {
	return RGBColor(255 - red, 255 - green, 255 - blue);
}
/*****************************************************************************/