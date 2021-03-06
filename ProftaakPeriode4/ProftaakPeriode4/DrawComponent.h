#pragma once
#include "Component.h"



/** Interface for drawing to View
 * \brief Drawing Interface
 * Draw() needs to be implemented in subclasses
 * Not for direct initialisation
 */
class DrawComponent : public Component
{
public:
	/** Constructor for DrawComponent
	 * \brief For creating DrawCompent as DRAW_COMPONENT type
	 */
	DrawComponent() : Component(DRAW_COMPONENT)
	{
		
	};
	/** Destructor of DrawComponent
	 * \brief DrawComponent Destructor
	 */
	~DrawComponent(){};

	/**
	 *Function for drawing to view
	 * \brief Drawing to View
	 * Needs to be implemented in subclasses like MeshDrawComponent
	 */
	virtual void Draw() = 0;
};

