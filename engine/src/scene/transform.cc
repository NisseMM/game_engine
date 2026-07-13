
#include <scene/transform.h>

#include <math/math.h>

Transform::Transform()
    : matrix_{1.0f}, position_{}, rotation_{1.0f, 0.0f, 0.0f, 0.0f}, scale_{1.0f}, dirty_{true}
{}

glm::mat4 Transform::matrix() const
{
    if (not dirty_)
        return matrix_;

    matrix_ = {1.0f};
    matrix_ = glm::translate(matrix_, position_);
    matrix_ *= glm::mat4_cast(rotation_);
    matrix_ = glm::scale(matrix_, scale_);
    dirty_ = false;

    return matrix_;
}

void Transform::rotate(glm::vec3 const& degrees)
{
    dirty_ = true;
    rotation_ *= glm::quat(glm::radians(degrees));
}

void Transform::translate(glm::vec3 const& offset)
{
    dirty_ = true;
    position_ += offset;
}

void Transform::scale(float factor)
{
    dirty_ = true;
    scale_ *= factor;
}