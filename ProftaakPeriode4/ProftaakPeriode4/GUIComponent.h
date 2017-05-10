#pragma once
#include "Component.h"
#include <vector>
#include "GUIElement.h"
#include "DrawComponent.h"

class GUIComponent: public DrawComponent
{
public:
	GUIComponent();
	~GUIComponent() {};

	void LateUpdate(float deltaTime) override;
	void Draw() override;

	void AddElement(GUIElement * element);

	std::vector<GUIElement *> _elements;

private:

};
