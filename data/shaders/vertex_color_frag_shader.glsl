#version 150

in vec3 position;
in vec3 color;
in vec2 tex_coord;

out vec3 out_color;

void main() {
    out_color = color + vec3(tex_coord, 1);
}