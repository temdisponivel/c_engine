#version 150

uniform mat4 MVP;
uniform mat4 Projection;
uniform mat4 View;
uniform mat4 Object;

in vec3 v_position;
in vec3 v_color;
in vec3 v_normal;
in vec2 v_tex_coord;

out vec3 pos;
out vec3 color;
out vec2 uv;

void main(void) {
    gl_Position = MVP * vec4(v_position, 1.0);

    color = v_color;// vec3(1, 1, 1);
    uv = v_tex_coord;
    pos = v_position;
}