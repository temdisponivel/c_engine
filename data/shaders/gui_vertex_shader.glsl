#version 150

in vec3 v_position;
in vec3 v_color;
in vec3 v_tex_coord;

out vec3 position;
out vec3 color;
out vec3 tex_coord;

void main() {
    gl_Position = v_position;
    position = v_position;
    color = v_color;
    tex_coord = v_tex_coord;
}

