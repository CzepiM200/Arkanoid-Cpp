#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Ball : public Drawable
{
public:
	Ball(int x, int y, int SizeX, int SizeY); // tworzenie naszego w�asnego konstruktora X,Y - koordynaty Ball
	Ball() = delete; // usuwanie standardoewgo konstruktora
	~Ball() = default; // ustawianie destruktora na domy�lny
	void Update();
	void ChangeVelocityVector(float x);
	void ChangeVelocityVector(short x, short y);	
	void RevertVelocityVecctor(bool x, bool y);	// To da si� wywali� do kontrolera
	float getSidePosition(char side) const;

	Vector2f GetPosition() const;
	void AddBallVelocity(int i);

private:
	int windowSizeX;
	int windowSizeY;

	CircleShape circle;
	float lenghtOfBallRay = { 8.0f };

	void draw(RenderTarget& target, RenderStates state) const override;

	float ballVelocity = {5.0f};
	Vector2f ballVelocityVector{ballVelocity, ballVelocity};
};

