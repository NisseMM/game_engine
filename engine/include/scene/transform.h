#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <math/math.h>

class Transform
{
public:
    Transform();

    glm::mat4 matrix() const;

    void rotate(glm::vec3 const &rot);
    void translate(glm::vec3 const &pos);
    void scale(float factor);

private:
    mutable glm::mat4 matrix_;

    glm::vec3 position_;
    glm::quat rotation_;
    glm::vec3 scale_;

    mutable bool dirty_;
};

#endif // TRANSFORM_H