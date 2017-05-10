#pragma once
#include "Component.h"
#include <vector>
#include "GUIElement.h"

class GUIComponent:Component
{
public:
	GUIComponent();
	~GUIComponent() {};

	void LateUpdate(float deltaTime) override;
	void Draw(int DeltaTime);

	void AddElement(GUIElement * element);

	std::vector<GUIElement *> _elements;

private:

};