#include "GUIComponent.h"

GUIComponent::GUIComponent() : Component(GUI_COMPONENT)
{
}

void GUIComponent::LateUpdate(int DeltaTime)
{
	//UPDATE GUI, CHECK FOR INPUT
	for (GUIElement element : _elements)
	{
		element.Update();
	}
}

void GUIComponent::Draw(int DeltaTime) {
	for (GUIElement element : _elements)
	{
		element.Draw(0);
	}
}

void GUIComponent::AddElement(GUIElement element) {
	_elements.push_back(element);
}
