#include "Text.h"
#include <iostream>
#include <sstream>

Text::Text(Vec3f pos, std::string text) : GUIElement(pos)
{
	
	_text = text;
}

Text::Text(Vec3f pos, std::string text, unsigned int * value) : GUIElement(pos)
{
	_text = text;
	_value = value;
}

void Text::Draw(int DeltaTime) {
	Sprint();
}

// This prints a string to the screen
void Text::Sprint()
{
	int l, i;
	Vec3f pos = GetPosition();
	std::string temp = _text;
	if (_value != nullptr) {
		temp = SSTR(_value);
	}
	const char *st = temp.c_str();
	l = strlen(st); // see how many characters are in text string.
	glRasterPos2i(pos.x, pos.y); // location to start printing text
	for (i = 0; i < l; i++) // loop until i is greater then l
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]); // Print a character on the screen
	}

}