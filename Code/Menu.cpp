#include "Menu.h"

// Konstruktos klasy Menu
Menu::Menu(int sizeX, int sizeY, Font defaultFont, GameStatus status)
{
	SetWindowSize(sizeX, sizeY);
	font = defaultFont;
	defalutFontSize = windowSizeY * 0.2f;
	this->status = status;
}

// Funkcja sk�adowa rysuje wybran� cz�� menu
void Menu::draw(RenderWindow& window) const
{
	for (int i = 0; i < amountOfOptions; i++)
	{
		window.draw(options[i]);
	}
}

int Menu::GetOptionNumber() const
{
	return selectedOption;
}

// Funkcja sk�adowa odpowiada za obs�ug� przes�wania wyboru w menu w d�
void Menu::MoveDown()
{
	if (selectedOption == amountOfOptions - 1)
	{
		options[selectedOption].setFillColor(firstColor);
		selectedOption = 0;
		options[selectedOption].setFillColor(secoundColor);
	}
	else
	{
		options[selectedOption].setFillColor(firstColor);
		selectedOption++;
		options[selectedOption].setFillColor(secoundColor);
	}
}

// Funkcja sk�adowa odpowiada za obs�ug� przes�wania wyboru w menu do g�ry
void Menu::MoveUp()
{
	if (selectedOption == 0)
	{
		options[selectedOption].setFillColor(firstColor);
		selectedOption = amountOfOptions - 1;
		options[selectedOption].setFillColor(secoundColor);
	}
	else
	{
		options[selectedOption].setFillColor(firstColor);
		selectedOption--;
		options[selectedOption].setFillColor(secoundColor);
	}
}

// Funkcja sk�adowa zapisuje wielko�� okna
void Menu::SetWindowSize(int sizeX, int sizeY)
{
	windowSizeX = sizeX;
	windowSizeY = sizeY;
}