#version 100

uniform mat4 cModel;
uniform mat4 cView;
uniform mat4 cProjView;

attribute vec4 ciPosition;

varying float _viewSpaceVertex;

void main(void)
{
  mat4 mvp = cProjView * cModel;
  mat4 mv =  cView * cModel;

  gl_Position = mvp * ciPosition;
  _viewSpaceVertex = abs((mv * ciPosition).z);
}