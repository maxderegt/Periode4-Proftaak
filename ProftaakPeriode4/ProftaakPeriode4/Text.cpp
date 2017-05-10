#include "Text.h"
#include <iostream>
#include <sstream>

Text::Text(Vec3f pos, Vec3f col, std::string text) : GUIElement(pos)
{
	_color = col;
	_text = text;
}

Text::Text(Vec3f pos, Vec3f col, std::string text, unsigned int * value) : GUIElement(pos)
{
	_color = col;
	_text = text;
	_value = value;
}

void Text::Draw() {
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(0.0, 800, 600, 0.0, -1.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_DEPTH_BUFFER_BIT);

	glPushAttrib(GL_CURRENT_BIT);
	glColor3f(_color.x,_color.y,_color.z);
	Sprint();
	glPopAttrib();
}

// This prints a string to the screen
void Text::Sprint()
{
	Vec3f pos = GetPosition();
	std::string temp = _text + " ";
	if (_value != nullptr) {
		temp = SSTR(temp << *_value);
	}
	const char *st = temp.c_str();
	size_t l = strlen(st); // see how many characters are in text string.
	glRasterPos2f(pos.x, pos.y); // location to start printing text
	for (size_t i = 0; i < l; i++) // loop until i is greater then l
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]); // Print a character on the screen
		std::cout << st[i] << std::endl;
	}

}