#include <scene/camera.h>

Camera::Camera(float fov, float aspect_ratio, float near, float far)
    : camera_transform_{}, fov_{fov}, aspect_ratio_{aspect_ratio}, near_{near}, far_{far}, view_{1.0f}, dirty_view_{true}
{
}

glm::mat4 Camera::view() const
{
    if (not dirty_view_)
        return view_;

    view_ =  glm::inverse(camera_transform_.matrix());
    dirty_view_ = false;
    return view_;
}

glm::mat4 Camera::projection() const
{
    return glm::perspective(glm::radians(fov_), aspect_ratio_, near_, far_);
}

Transform &Camera::transform()
{
    dirty_view_ = true;
    return camera_transform_;
}

Transform const &Camera::transform() const
{
    return camera_transform_;
}