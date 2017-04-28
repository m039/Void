//
// Created by Dmitry Mozgin on 28/04/2017.
//

#include "Camera.h"

#include "../../VoidApp.h"

using namespace vd;

Camera::Camera(const VoidApp &app)
        : VoidAppObject(app),
          _nearClipPlane(0.1f),
          _backgroundColor(Color::White),
          _transform(std::make_shared<Transform>()) {
    Setup();
}

Camera::~Camera() {
}

const ITransformRef vd::Camera::GetTransform() const {
    return _transform;
}

void Camera::SetNearClipPlane(float nearClipPlane) {
    _nearClipPlane = nearClipPlane;
    Setup();
}

float Camera::GetNearClipPlane() const {
    return _nearClipPlane;
}

void Camera::SetBackgroundColor(const Color &color) {
    _backgroundColor = color;
}

Color Camera::GetBackgroundColor() const {
    return _backgroundColor;
}

void Camera::Setup() {
    auto windowSize = app.getWindow()->getSize();
    auto aspectRatio = (float) windowSize.x / (float) windowSize.y;

    auto p = GetTransform()->GetPosition();

    _camera.lookAt(ci::vec3(p.x, p.y, p.z), ci::vec3(p.x, p.y, p.z + 1));
    _camera.setPerspective(35, aspectRatio, _nearClipPlane, 1000.0f);
}

void Camera::LoadMatrices() {
    ci::gl::setMatrices(_camera);
    app.getShader()->SetMatrices(_camera);
}

CameraTransform::CameraTransform(Camera &camera)
        : _camera(camera) {
}

void CameraTransform::SetPosition(const Vector3 &position) {
    Transform::SetPosition(position);
    _camera.Setup();
}
