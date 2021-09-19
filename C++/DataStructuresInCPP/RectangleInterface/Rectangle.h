/**	@file Rectamgle.h */

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "RectangleInterface.h"

class Rectangle : public RectangleInterface
{
	private:
		double length, width;
	public:
		/****************************************
			Rectangle::Rectangle()
		: default constuctor only works when
		no values are give so this sets
		length and width to 1.0.
		***************************************/
		Rectangle();
		/** Updates the length and width of the rectangle
		@param: newL the new length of Rectangle
					 newW the new width of the Rectangle
		@pre.: new length and width bust be larger than 0.0
		@post.: if newL and newW are valid, the rectangles width and length are set
					otherwise, object is not updated
		@return	True if both values are larger than 0.0
					False otherwise. */
		bool setDimension(double newL, double newW);
		/** Gets the length of this Rectangle
		@return: length of this rectangle */
		double getLength() const;
		/****************************************
		double Rectangle::getWidth() const
	: 	@return private var width
		****************************************/
		double getWidth() const;
		/****************************************
		double Rectangle::getArea() const
		: returns area (length times width)
	****************************************/
		double getArea() const;
};
#endif
