//
// Created by Dmitry Mozgin on 25/04/2017.
//

#pragma once

#include <string>
#include <Common/Mesh.h>
#include <Common/Color.h>
#include "Common/Components/ITransform.h"

namespace vd {

class IVoidObject {

    /**
     * Commentary:
     *
     * What is a good point not to return Color (or other instances) by a const reference?
     * Or is it better to add additional getters?
     */

public:

    virtual const Color& GetColor() const = 0;

    virtual void SetColor(Color& color) = 0;

    virtual const std::string& GetName() const = 0;

    virtual void SetName(const std::string& name) = 0;

    virtual bool IsEnabled() const = 0;

    virtual void SetEnabled(bool value) = 0;

    virtual bool IsHidden() const = 0;

    virtual void SetHidden(bool value) = 0;

    virtual ITransform& GetTransform() = 0;

    virtual const IMeshRef& GetMesh() const = 0;

    virtual void SetMesh(const IMeshRef& mesh) = 0;

    //! Hides the object in hierarchy: enabled, but invisible.
    virtual void Hide() = 0;

    //! Shows the object.
    virtual void Show() = 0;

    virtual void Destroy() = 0;

    virtual ~IVoidObject() {}
};

class IObjectPool;

class VoidObject
        : public virtual IVoidObject
{
    class Transform : public ITransform {

    public:

        Transform();

        //region Implementation of ITransform.

        virtual const Vector3& GetLocalScale() const override;

        virtual void SetLocaleScale(const Vector3& scale) override;

        virtual const Vector3& GetPosition() const override;

        virtual void SetPosition(const Vector3& position) override;

        virtual void Rotate(float xAngle, float yAngle, float zAngle) override;

        //endregion

    private:

        Vector3 _localScale;

        Vector3 _position;
    };

public:

    /*!
     * \param pool a pool to which this object belongs to.
     * \param name the object's name (currently used only for debugging).
     */
    VoidObject(const IObjectPool& pool, const std::string& name);

    //region Implementation of IVoidObject.

    const Color& GetColor() const override;
    
    void SetColor(Color& color) override;
    
    const std::string& GetName() const override;
    
    void SetName(const std::string& name) override;
    
    bool IsEnabled() const override;
    
    void SetEnabled(bool value) override;
    
    bool IsHidden() const override;
    
    void SetHidden(bool value) override;
    
    ITransform& GetTransform() override;
    
    const IMeshRef& GetMesh() const override;
    
    void SetMesh(const IMeshRef& mesh) override;
    
    void Hide() override;
    
    void Show() override;
    
    void Destroy() override;

    //endregion

private:

    void InitDefault();

    IMeshRef _mesh;

    Color _color;

    Transform _transform;

    std::string _name;

    bool _isEnabled;

};

}
