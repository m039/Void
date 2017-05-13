//
// Created by Dmitry Mozgin on 28/04/2017.
//

#include "CameraImpl.h"

#include "../../VoidApp.h"

using namespace vd;

CameraImpl::CameraImpl(VoidApp &app)
        : VoidAppObject(app),
          _nearClipPlane(0.1f),
          _backgroundColor(Color::White),
          _transform(std::make_shared<CameraTransform>(*this)) {
    Setup();
}

const ITransformRef vd::CameraImpl::GetTransform() const {
    return _transform;
}

void CameraImpl::SetNearClipPlane(float nearClipPlane) {
    _nearClipPlane = nearClipPlane;
    Setup();
}

float CameraImpl::GetNearClipPlane() const {
    return _nearClipPlane;
}

void CameraImpl::SetBackgroundColor(const Color &color) {
    _backgroundColor = color;
}

Color CameraImpl::GetBackgroundColor() const {
    return _backgroundColor;
}

void CameraImpl::Setup() {
    auto windowSize = app.getWindow()->getSize();
    auto aspectRatio = (float) windowSize.x / (float) windowSize.y;

    auto p = GetTransform()->GetPosition();

    // The game uses left-handed coordinates, but OpenGL is right-handed
    _camera.lookAt(ci::vec3(-p.x, p.y, p.z), ci::vec3(-p.x, p.y, p.z + 1));
    _camera.setPerspective(60, aspectRatio, _nearClipPlane, 1000.0f);
}

void CameraImpl::LoadMatrices() {
    ci::gl::setMatrices(_camera);
    app.GetShader()->SetMatrices(_camera);
}

CameraTransform::CameraTransform(CameraImpl &camera)
        : _camera(camera) {
}

void CameraTransform::SetPosition(const Vector3 &position) {
    Transform::SetPosition(position);
    _camera.Setup();
}
