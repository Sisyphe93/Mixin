#ifndef CLASSESS_HPP
#define CLASSESS_HPP

#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <fstream>
#include "iostream"
using namespace std;

class Window
{
public:
	SDL_Renderer *renderer;
	SDL_Window *window;
};

class Vector2
{
public:
	float x, y;

	Vector2(float _x = 0.0f, float _y = 0.0f)
		: x(_x), y(_y) {}

	float getX() const { return x; }
	float getY() const { return y; }
};

// Define a Transform component to store position, rotation, and scale in 2D
class Transform2D
{
public:
	Vector2 position;
	float rotation; // Rotation angle in degrees
	Vector2 scale;

	Transform2D(const Vector2 &_position = Vector2(), float _rotation = 0.0f, const Vector2 &_scale = Vector2(1.0f, 1.0f))
		: position(_position), rotation(_rotation), scale(_scale) {}

	const Vector2 &getPosition() const { return position; }
	float getRotation() const { return rotation; }
	const Vector2 &getScale() const { return scale; }
};

// Define the Entity class for 2D objects
class Entity
{
public:
	std::string name;
	Transform2D transform;
	SDL_Texture *texture;

	Entity(const std::string &_name, const Vector2 &position = Vector2(), float rotation = 0.0f, const Vector2 &scale = Vector2(1.0f, 1.0f))
		: name(_name), transform(position, rotation, scale) {}

	const std::string &getName() const { return name; }
	const Vector2 &GetPosition() const
	{
		return transform.position;
	}
	const Vector2 &GetScale() const
	{
		return transform.scale;
	}
};

#endif