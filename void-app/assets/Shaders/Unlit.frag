#version 150

uniform int c_FogEnabled;
uniform float c_FogStartPosition;
uniform float c_FogDensity;
uniform vec4 c_FogColor;
uniform float c_MinFogFactor;

uniform vec4 cMainColor;

in float _viewSpaceVertex;

out vec4 	oColor;

void main(void)
{
    float fogFactor = 1.0;

    if (c_FogEnabled > 0) {
        float dist = _viewSpaceVertex - c_FogStartPosition;
        if (dist < 0.0) {
            fogFactor = 1.0;
        } else {
            float d = (dist * c_FogDensity);
            fogFactor = clamp(1.0 / exp(d * d), 0.0, 1.0);
        }
    } else {
        fogFactor = 1.0;
    }

    fogFactor = max(c_MinFogFactor, fogFactor);

    oColor = mix(c_FogColor, cMainColor, fogFactor);
}
