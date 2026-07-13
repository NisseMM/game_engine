#ifndef CAMERA_H
#define CAMERA_H

#include <scene/transform.h>

#include <math/math.h>

class Camera
{
public:
    Camera(float fov, float aspect_ratio, float near, float far);

    glm::mat4 view() const;
    glm::mat4 projection() const;
    
    Transform& transform();
    Transform const& transform() const;

private:
    Transform camera_transform_;
    float fov_;
    float aspect_ratio_;
    float far_;
    float near_;
    mutable glm::mat4 view_;
    mutable bool dirty_view_;
};



#endif //CAMERA_H