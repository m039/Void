//
// Created by Dmitry Mozgin on 20/04/2017.
//

#include "DrawHelper.h"
#include "VoidApp.h"

using namespace ci;
using namespace vd;

void DrawHelper::Draw(const VoidApp &app, std::vector<GLfloat> &vertices, std::vector<GLubyte> &elements) {
    auto* context = gl::context();
    auto numberOfElements = static_cast<GLuint>(elements.size());
    auto sizeOfVertices = vertices.size();
    auto glslProg = app.GetShader()->GetInternalShader();

    gl::ScopedGlslProg glslScp(glslProg);

    bool hasPositions = glslProg->hasAttribSemantic(geom::Attrib::POSITION);

    size_t totalArrayBufferSize = 0;
    if( hasPositions )
        totalArrayBufferSize += sizeof(float) * sizeOfVertices;

    context->pushVao();
    context->getDefaultVao()->replacementBindBegin();

    ci::gl::VboRef defaultArrayVbo = context->getDefaultArrayVbo(totalArrayBufferSize);
    ci::gl::ScopedBuffer vboScp(defaultArrayVbo);
    ci::gl::VboRef elementVbo = context->getDefaultElementVbo(numberOfElements);
    // we seem to need to orphan the existing element vbo on AMD on OS X
    elementVbo->bufferData(numberOfElements, nullptr, GL_STREAM_DRAW);

    elementVbo->bind();
    if( hasPositions ) {
        auto loc = static_cast<GLuint>(glslProg->getAttribSemanticLocation(geom::Attrib::POSITION));
        gl::enableVertexAttribArray(loc);
        gl::vertexAttribPointer(loc, 3, GL_FLOAT, GL_FALSE, 0, 0);
        defaultArrayVbo->bufferSubData(0, sizeof(float) * sizeOfVertices, vertices.data());
    }

    elementVbo->bufferSubData(0, numberOfElements, elements.data());
    context->getDefaultVao()->replacementBindEnd();
    context->drawElements(GL_TRIANGLES, numberOfElements, GL_UNSIGNED_BYTE, 0);
    context->popVao();
}
