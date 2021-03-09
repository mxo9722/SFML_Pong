#include "pch.h"
#include "Ball.h"


Ball::Ball(float startX, float startY)
{
	position.x = startX;
	position.y = startY;

	ballShape.setSize(Vector2f(10,10));
	ballShape.setPosition(position);
}


Ball::~Ball()
{
}

FloatRect Ball::getPosition()
{
	return ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape()
{
	return ballShape;
}

float Ball::getXVelocity()
{
	return xVelocity;
}

void Ball::reboundSides()
{
	xVelocity *= -1;
}

void Ball::reboundBatOrTop()
{
	position.y -= (yVelocity * 30);
	yVelocity *= -1;
}

void Ball::hitBottom()
{
	position.y = 1;
	position.x = 500;
}

void Ball::update()
{
	position.y += yVelocity;
	position.x += xVelocity;

	ballShape.setPosition(position);
}
