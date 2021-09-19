#ifndef RECTANGLE_INTERFACE_H
#define RECTANGLE_INTERFACE_H

/** @file RectangleInterface.h */

class RectangleInterface
{
	public:
		virtual bool setDimension(double newL, double newW) = 0;
		/** Gets the length of this Rectangle
			@return: length of this rectangle */
		virtual double getLength() const = 0;
		/** Gets the radius  of this rectangle
	 	@return The radius of this rectangle. */
		virtual double getWidth() const = 0;
		/** Gets the area  of this rectangle
	 	@return: The area of this rectangle */
		virtual double getArea() const = 0;
		/** Destroys this Circle and frees its assigned memory. */
		virtual ~RectangleInterface()  {}
};
#endif
