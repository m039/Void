#version 150

uniform mat4 cModel;
uniform mat4 cView;
uniform mat4 cProjView;

in vec4 ciPosition;

out float _viewSpaceVertex;

void main(void)
{
  mat4 mvp = cProjView * cModel;
  mat4 mv =  cView * cModel;

  gl_Position = mvp * ciPosition;
  _viewSpaceVertex = abs((mv * ciPosition).z);
}