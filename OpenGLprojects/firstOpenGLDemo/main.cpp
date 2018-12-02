#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Shader.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

float rectVertices[] = {
    0.5f, 0.5f, 0.0f,		//右上角
    0.5f, -0.5f, 0.0f,		//右下角
    -0.5f, -0.5f, 0.0f,		//左下角
    -0.5f, 0.5f, 0.0f		//左上角
};

unsigned int indices[] = {
    0, 1, 3,		//第一个三角形
    1, 2, 3			//第二个三角形
};

float vertices[] = {
    //位置				//颜色
    -0.5f, -0.5f, 0.0f, //1.0f, 0.0f, 0.0f,		//左
    0.5f, -0.5f, 0.0f,	//0.0f, 1.0f, 0.0f,		//右
    0.0f, 0.5f, 0.0f//,	0.0f, 0.0f, 1.0f		//上
};

float mulvertices[] = {
    //位置				//颜色
    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,		//左
    0.5f, -0.5f, 0.0f,	0.0f, 1.0f, 0.0f,		//右
    0.0f, 0.5f, 0.0f,	0.0f, 0.0f, 1.0f		//上
};

// 设置
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

int main() {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    //获取最大属性数量
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "最大支持的属性数量为：" << nrAttributes << std::endl;

    //！创建我们的着色器
    Shader shader("Shader.vs", "Shader.fs");

    //第一个环境
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(mulvertices), mulvertices, GL_STATIC_DRAW);

//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, /*6 * sizeof(float)*/0, (void*)0);
//    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    //第二个环境
//    unsigned int VBO1, VAO1;
//    glGenVertexArrays(1, &VAO1);
//    glBindVertexArray(VAO1);

//    glGenBuffers(1, &VBO1);
//    glBindBuffer(GL_ARRAY_BUFFER, VBO1);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(rectVertices) / 2, rectVertices + 9, GL_STATIC_DRAW);

//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//    glEnableVertexAttribArray(1);

//    unsigned int EBO;
//    glGenBuffers(1, &EBO);
//    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
//    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        float timeValue = glfwGetTime();
        float redValue = (-std::sin(timeValue) / 2.0f) + 0.5f;
        float greenValue = (std::cos(timeValue) / 2.0f) + 0.5f;
        float blueValue = (std::sin(timeValue) / 2.0f) + 0.5f;

        // set shader values
        shader.use();
        shader.setFloat("uniformColor", redValue, greenValue, blueValue, 1.0f);
//        float offset = 0.5f;
//        shader.setFloat("xOffset", offset);

        /*
        * 这里是一个习惯，上面的操作把属性都保存到了VAO中，这里只需要绑定就可以
        * 如果要显示的东西不同，也只需要在这里绑定不同的东西就可以显示
        */
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

//        shader.use();
//        glBindVertexArray(VAO1);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glBindVertexArray(0);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
