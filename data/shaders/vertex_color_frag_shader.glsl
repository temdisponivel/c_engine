#version 150

in vec3 position;
in vec3 color;
in vec2 tex_coord;

uniform sampler2D diffuse_texture;

out vec4 out_color;

void main() {
    vec4 tex_color = texture(diffuse_texture, tex_coord);
    out_color = tex_color * vec4(color, 1);
}