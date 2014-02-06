#ifndef _shader_h_
#define _shader_h_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLuint make_shader(GLenum type, const char *source);
GLuint load_shader(GLenum type, const char *path);
GLuint make_program(GLuint shader1, GLuint shader2);
GLuint load_program(const char *path1, const char *path2);

#endif
