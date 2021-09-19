/** @file Rectangle.cpp */

#include "Rectangle.h"

Rectangle::Rectangle()
{
	length=width=1.0;
}
bool Rectangle::setDimension(double newL, double newW)
{
	if (newL > 0.0 && newW > 0.0)
	{
		length=newL;
		width=newW;
		return true;
	}
	else
	{
		return false;
	}
}
double Rectangle::getLength() const
{	return length;	}
double Rectangle::getWidth() const
{	return width;	}
double Rectangle::getArea() const
{	return length*width;	}
