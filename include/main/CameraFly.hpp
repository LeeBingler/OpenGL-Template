#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Default camera values
const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class CameraFly {
    public:
        glm::vec3 Position;
        glm::vec3 Front;
        glm::vec3 Up;
        glm::vec3 Right;
        glm::vec3 WorldUp;
        // euler Angles
        float Yaw;
        float Pitch;
        // camera options
        float MovementSpeed;
        float MouseSensitivity;
        float Zoom;

        // constructor
        CameraFly(glm::vec3 position, glm::vec3 up, float yaw, float pitch);
        CameraFly(float posX, float posY ,float posZ, float upX, float upY ,float upZ, float yaw, float pitch);

        // attributs
        glm::mat4 GetViewMatrix();
        void ProcessKeyboard(Camera_Movement direction, float deltaTime);
        void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch);
        void ProcessMouseScroll(float yoffset);

        // setter
        void setMouseSensitivity(float sensitivity);
        void setMovementSpeed(float movementSpeed);
        void setZoom(float zoom);

    private:
        void updateCameraVectors();
};