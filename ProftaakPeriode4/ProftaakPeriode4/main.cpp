#include "Model.h"
#include "View.h"
#include "Lanes.h"
#include "GUIComponent.h"
#include "GUIElement.h"
#include "Text.h"

#include <GL\freeglut.h>

Model model;
View view;
GUIComponent GUI;
unsigned int fps = 20;

// The displayFunc which will call the update of the view
// This function should only be called by OpenGL and NOT manually
void display()
{
	view.update();
}

// The reshapeFunc which will call the reshape of the view
// This function should only be called by OpenGL and NOT manually
void reshape(int w, int h)
{
	view.reshape(w, h);
}

// The idleFunc which will call the update of the model
// This function should only be called by OpenGL and NOT manually
void idle()
{
	model.update();
	GUI.Draw(0);
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	model = Model();
	view = View(&model);
	GUI = GUIComponent();
	Vec3f pos = Vec3f(0, 0, 0);
	Text fpstext = Text(pos, "fps", &fps);
	GUI.AddElement(fpstext);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutIdleFunc(idle);

	glutMainLoop();
	return 0;
}
