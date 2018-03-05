#version 150
// It was expressed that some drivers required this next line to function properly
precision highp float;

in vec3 pos;
in vec3 color;
in vec2 uv;

uniform sampler2D diffuse_texture;

out vec4 out_color;

void main(void) {
    vec4 tex_color = texture(diffuse_texture, uv);
    out_color = tex_color;
}