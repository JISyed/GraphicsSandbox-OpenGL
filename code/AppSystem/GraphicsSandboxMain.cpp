#include "GraphicsSandboxMain.h"
//-----------------------------

#include <iostream>

#ifdef _WIN32
	#define GS_UNUSED_VAR(x) x
#else
	// macOS
	#define GS_UNUSED_VAR(x)
#endif

#include <GL/gl3w.h>


#include "glfw/glfw3.h"



#define STB_IMAGE_IMPLEMENTATION
#include "stb_image/stb_image.h"



#include <ft2build.h>
#include FT_FREETYPE_H 



#include "glm/glm.hpp"



#include "irrklang/irrKlang.h"
using namespace irrklang;





#include "oail/oail/Importer.hpp"
#include "oail/oail/scene.h"
#include "oail/oail/postprocess.h"




// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;





int gs_main(int argc, const char * argv[])
{
	GS_UNUSED_VAR(argc); 
    GS_UNUSED_VAR(argv);

	glm::mat4x4 modelMat(4);

	Assimp::Importer importer;
    ISoundEngine *SoundEngine = createIrrKlangDevice();

	SoundEngine->play2D("audio/breakout.mp3", GL_TRUE);

	std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Absolutly needed in OS X, otherwise GL version becomes 2.1
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);




	if (gl3wInit())
	{
		fprintf(stderr, "failed to initialize OpenGL\n");
		return -1;
	}
	if (!gl3wIsSupported(3, 3))
	{
		fprintf(stderr, "OpenGL 3.3 not supported\n");
		return -1;
	}
	printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION),
		   glGetString(GL_SHADING_LANGUAGE_VERSION));





	// Define the viewport dimensions
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}

	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}







// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	GS_UNUSED_VAR(mode);
	GS_UNUSED_VAR(scancode);
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
