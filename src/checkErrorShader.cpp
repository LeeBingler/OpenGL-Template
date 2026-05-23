#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int checkErrorShader(unsigned int shaderID) {
    int  success;
    char infoLog[512];
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

    if(!success) {
        glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::WRITING::COMPILATION_FAILED\n" << infoLog << std::endl;
        return -1;
    }

    return 0;
}

int checkErrorLinkShader(unsigned int shaderProgramID) {
    int  success;
    char infoLog[512];
    glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);

    if(!success) {
        glGetProgramInfoLog(shaderProgramID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::LINK::COMPILATION_FAILED\n" << infoLog << std::endl;
        return -1;
    }
    return 0;
}
