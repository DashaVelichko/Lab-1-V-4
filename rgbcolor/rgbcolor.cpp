// (C) 2013-2015, Sergei Zaychenko, KNURE, Kharkiv, Ukraine

#include "rgbcolor.hpp"

/*****************************************************************************/
RGBColor void setRed(unsigned char red_color) {
	red = red_color; // инициализация красного
}
RGBColor void setGreen(unsigned char green_color) {
	green = green_color; // инициализация зеленого
}
RGBColor void setBlue(unsigned char blue_color) {
	blue = blue_color; // инициализация синего
}

RGBColor void setPackedRGB(unsigned int packed_color) {
	packedColor = packed_color; // инициализация packedColor
}

RGBColor unsigned int packed_color() {
	unsigned int packed_color;
	packed_color = ((red * 65536) + (green * 256) + blue);

	return packed_color;
}

RGBColor unsigned char getRed() {
	return red; // доступ к private переменной red
}
RGBColor unsigned char getGreen() {
	return green; // доступ к private переменной green
}

RGBColor unsigned char getBlue() {
	return blue; // доступ к private переменной blue
}

RGBColor unsigned int getPackedRGB() {
	return packedColor; // доступ к private переменной packedColor
}

RGBColor void setRGBFromPackedColor() { // посчитать реальное значение здесь

	if (packedColor > 16777215) {
		//std::cout « "You have entered not a valid color.\n";
		//exit(EXIT_FAILURE);
	}

	RGBColor	unsigned int packed_color = packedColor;

	RGBColor	unsigned char red_color = (packed_color / 65536);
	packed_color = packed_color - (int)(packed_color / 65536) * 65536;

	RGBColor unsigned char green_color = (int)(packed_color / 256);
	packed_color = packed_color - (int)(packed_color / 256) * 256;

	RGBColor unsigned char blue_color = (packed_color / 1);


	RGBColor setRed(red_color);
	RGBColor setGreen(green_color);
	RGBColor setBlue(blue_color);
}

RGBColor double blackKey() {
	double blackKey = 0.000;


	double max = findMax((double)((int)red / 255.0), ((int)green / 255.0), ((int)blue / 255.0));
	blackKey = 1 - max;
	blackKey = round(blackKey * 1000.0) / 1000.0;

	return blackKey;

}

RGBColor double findMax(double n1, double n2, double n3) {


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

RGBColor double cyan_color() {
	double cyan_color = 0.0;
	if (BlackKey != 1.0) {
		cyan_color = (1.0 - red / 255.0 - BlackKey) / (1.0 - BlackKey);
	}
	return cyan_color;
}

RGBColor double magent_color() {
	double magent_color = 0.0;
	if (BlackKey != 1.0) {
		magent_color = (1.0 - green / 255.0 - BlackKey) / (1.0 - BlackKey);
	}
	return magent_color;
}

RGBColor double yellow_color() {
	double yellow_color = 0.0;
	if (BlackKey != 1.0) {
		yellow_color = (1.0 - blue / 255.0 - BlackKey) / (1.0 - BlackKey);
	}
	return yellow_color;

}
RGBColor double getBlackKey() {

	return BlackKey;
}
RGBColor double getCyanColor() {
	return CaynColor;
}
RGBColor double getMagentaColor() {
	return MagentColor;
}
RGBColor double getYellowColor() {
	return YellowColor;
}

RGBColor bool operator == (RGBColor const & _color) const
{
	return red == _color.red && blue == _color.blue && green == _color.green;
}

RGBColor bool operator != (RGBColor const & _color) const
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