#pragma once
#include "GUIElement.h"
#include <GL/freeglut.h>
#include "Vec.h"
#include <string>

#define SSTR( x ) static_cast< std::ostringstream & >( \
			( std::ostringstream() << std::dec << x )).str()

class Text : public GUIElement
{	
public:
	Text(Vec3f pos, Vec3f col, std::string text);
	Text(Vec3f pos, Vec3f col, std::string text, unsigned int * value);
	void Draw() override;

private:
	Vec3f _color;
	std::string _text = "";
	unsigned int * _value = nullptr;
	void Sprint();

};