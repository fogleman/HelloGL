#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "matrix.h"
#include "shader.h"
#include "util.h"

int main(void) {
    if (!glfwInit()) {
        return -1;
    }

    GLFWwindow *window = glfwCreateWindow(800, 800, "HelloGL", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glEnable(GL_DEPTH_TEST);

    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        return -1;
    }

    GLuint program = load_program(
        "shaders/vertex.glsl", "shaders/fragment.glsl");
    GLuint position = glGetAttribLocation(program, "position");
    GLuint matrix = glGetUniformLocation(program, "matrix");

    float data[] = {
        -0.5, -0.5,
        0.5, -0.5,
        0, 0.5
    };
    GLuint buffer = gen_buffer(sizeof(data), data);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float mat[16];
        mat_identity(mat);
        mat_translate(mat, 0, -0.5, 0);
        mat_rotate(mat, 0, 0, 1, glfwGetTime());
        mat_ortho(mat, -2, 2, -2, 2, -2, 2);

        glUseProgram(program);
        glUniformMatrix4fv(matrix, 1, GL_FALSE, mat);
        glBindBuffer(GL_ARRAY_BUFFER, buffer);
        glEnableVertexAttribArray(position);
        glVertexAttribPointer(position, 2, GL_FLOAT, GL_FALSE, 0, 0);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableVertexAttribArray(position);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
