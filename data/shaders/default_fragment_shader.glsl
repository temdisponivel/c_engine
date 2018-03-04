#version 150
// It was expressed that some drivers required this next line to function properly
precision highp float;

in vec3 pos;
in vec3 color;
in vec2 uv;

out vec4 out_color;

void main(void) {
    out_color = vec4(1, 1, 1, 1);
}