#pragma once

struct Vector2f {

	Vector2f()
		:x(0.0), y(0.0)
	{}
	
	Vector2f(int X, int Y)
		:x(X), y(Y)
	{}

	double x;

	double y;

};