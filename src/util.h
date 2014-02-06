#ifndef _util_h_
#define _util_h_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLuint gen_buffer(GLsizei size, GLfloat *data);
void del_buffer(GLuint buffer);

#endif
