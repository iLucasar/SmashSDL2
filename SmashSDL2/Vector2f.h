#pragma once

struct Vector2f {

	Vector2f()
		:x(0), y(0)
	{}
	
	Vector2f(int X, int Y)
		:x(X), y(Y)
	{}

	void operator+(Vector2f s)
	{
	
		x += s.x;
		y += s.y;

	}

	int x;

	int y;

};