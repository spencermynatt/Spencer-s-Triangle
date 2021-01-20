#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
const char* vertex_shader =
"#version 430 core\n"
"layout (location = 0) in vec3 position;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
"}\0";
const char* fragment_shader =
"#version 430\n"
""
"out vec4 color;\n"
""
"void main()\n"
"{\n"
"color = vec4(1.0, 0.0, 1.0, 1.0);\n"
"}\n";

int main()
{
    glfwInit();
     GLFWwindow* window = glfwCreateWindow(800, 600, "Spencer's triangle", NULL, NULL);
    if (window == NULL)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);//initialize glad
    glViewport(0, 0, 800, 600);

    float points[]{

        -0.5f, -0.5f,
         0.5f, -0.5f,
         0.0f,  0.5f
    };
    int vertex = glCreateShader(GL_VERTEX_SHADER);
    int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    const char* string_arr[1];
    string_arr[0] = vertex_shader;
    glShaderSource(vertex, 1, string_arr, 0);
    string_arr[0] = fragment_shader;
    glShaderSource(fragment, 1, string_arr, 0);
    glCompileShader(vertex);
    glCompileShader(fragment);
    int program = glCreateProgram();
    glAttachShader(program, vertex);
    glAttachShader(program, fragment);
    glLinkProgram(program);
    glUseProgram(program);
    unsigned int storage;
    glGenBuffers(1, &storage);
    glGenVertexArrays(1, &storage);
    glBindVertexArray(storage);
    glBindBuffer(GL_ARRAY_BUFFER, storage);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);
    while (!glfwWindowShouldClose(window))
    {
        glUseProgram(program);
        glBindVertexArray(storage);
        glDrawArrays(GL_TRIANGLES, 0, 3);
       
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
    return 0;
}
