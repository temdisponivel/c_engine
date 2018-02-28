//
// Created by temdisponivel on 27/02/2018.
//

#include "graphics/materials.h"

void send_uniform_to_gl(uniform_t *uniform) {

    // The shader doesn't have the material uniform defined on the material file
    if (uniform->handle < 0)
        return;

    switch (uniform->type) {

        case UNIFORM_BOOLEAN:
            glUniform1i(uniform->handle, uniform->value.bool_value);
            break;
        case UNIFORM_BYTE:
            glUniform1i(uniform->handle, uniform->value.byte_value);
            break;
        case UNIFORM_UBYTE:
            glUniform1ui(uniform->handle, uniform->value.ubyte_value);
            break;
        case UNIFORM_SHORT:
            glUniform1i(uniform->handle, uniform->value.short_value);
            break;
        case UNIFORM_USHORT:
            glUniform1ui(uniform->handle, uniform->value.ushort_value);
            break;
        case UNIFORM_INT:
            glUniform1i(uniform->handle, uniform->value.int_value);
            break;
        case UNIFORM_UINT:
            glUniform1ui(uniform->handle, uniform->value.uint_value);
            break;
        case UNIFORM_LONG:
            glUniform1i(uniform->handle, uniform->value.long_value);
            break;
        case UNIFORM_FLOAT:
            glUniform1f(uniform->handle, uniform->value.float_value);
            break;
        case UNIFORM_DOUBLE:
            glUniform1d(uniform->handle, uniform->value.double_value);
            break;
        case UNIFORM_VEC2:
            glUniform2fv(uniform->handle, 1, (const GLfloat *) glm::value_ptr(uniform->value.vector2_value));
            break;
        case UNIFORM_VEC3:
            glUniform3fv(uniform->handle, 1, (const GLfloat *) glm::value_ptr(uniform->value.vector3_value));
            break;
        case UNIFORM_VEC4:
            glUniform4fv(uniform->handle, 1, (const GLfloat *) glm::value_ptr(uniform->value.vector4_value));
            break;
        case UNIFORM_MATRIX:
            glUniformMatrix4fv(
                    uniform->handle,
                    1,
                    GL_FALSE,
                    (const GLfloat *) glm::value_ptr(uniform->value.matrix_value)
            );

            break;
        case UNIFORM_TEXTURE2D:
            glActiveTexture(uniform->value.texture_value.index);
            gl_handle handle = 0;
            if (uniform->value.texture_value.texture.handle > 0)
                handle = uniform->value.texture_value.texture.handle;

            glBindTexture(GL_TEXTURE_2D, handle);

            // texture target index is GL_TEXTURE0, GL_TEXTURE1, GL_TEXTURE{X}
            // But the parameter must be 0, 1, {x}. So we subtract the index from the GL_TEXTURE0
            // to get only the "{x}"
            // NOTE: this don't need to be done every frame
            glUniform1i(uniform->handle, uniform->value.texture_value.index - GL_TEXTURE0);
            break;
    }

    CHECK_GL_ERROR();
}

void send_all_uniforms_to_gl(list<uniform_t> *uniforms) {
    for (int i = 0; i < uniforms->length; ++i) {
        send_uniform_to_gl(&uniforms->items[i]);
    }
}

int get_uniform_id(const char *name) {
    return hash(name);
}

uniform_t *get_uniform(list<uniform_t> *uniforms, const char *name) {
    int id = get_uniform_id(name);
    for (int i = 0; i < uniforms->length; ++i) {
        uniform_t uniform = uniforms->items[i];
        if (uniform.id == id) {
            return &uniforms->items[i];
        }
    }
}

uint create_gl_shader(
        const char *code,
        uint type
) {
    uint shader = glCreateShader(type);
    glShaderSource(shader, 1, &code, 0);
    glCompileShader(shader);
    CHECK_SHADER_COMPILE_STATUS(shader, code);
    return shader;
}

shader_program_t create_shader(
        const char *vertex_shader_code,
        const char *fragment_shader_code,
        const char *geometry_shader_code,
        vertex_attrib_names_t vertex_attrib_names
) {
    uint vertex_shader = 0;
    uint fragment_shader = 0;
    uint geometry_shader = 0;

    if (vertex_shader_code != 0){
        vertex_shader = create_gl_shader(vertex_shader_code, GL_VERTEX_SHADER);
    }

    if (fragment_shader_code != 0) {
        fragment_shader = create_gl_shader(fragment_shader_code, GL_FRAGMENT_SHADER);
    }

    if (geometry_shader_code != 0) {
        geometry_shader = create_gl_shader(geometry_shader_code, GL_GEOMETRY_SHADER);
    }

#if DEV
    if (vertex_shader == 0 && fragment_shader == 0 && geometry_shader == 0) {
        ERROR("CREATING SHADER WITH NO SHADER PROGRAM!!")
    }
#endif

    uint program = glCreateProgram();
    if (vertex_shader > 0) {
        glAttachShader(program, vertex_shader);
    }

    if (fragment_shader > 0) {
        glAttachShader(program, fragment_shader);
    }

    if (geometry_shader > 0) {
        glAttachShader(program, geometry_shader);
    }

    glBindAttribLocation(program, POSITION_ATTRIBUTE_INDEX, vertex_attrib_names.position_name);
    glBindAttribLocation(program, TEX_COORD_ATTRIBUTE_INDEX, vertex_attrib_names.tex_coord_name);
    glBindAttribLocation(program, NORMAL_ATTRIBUTE_INDEX, vertex_attrib_names.normal_name);
    glBindAttribLocation(program, COLOR_ATTRIBUTE_INDEX, vertex_attrib_names.color_name);

    glLinkProgram(program);
    CHECK_SHADER_LINK_STATUS(program);

    shader_program_t result;
    result.program = program;
    result.vertex_handle = vertex_shader;
    result.fragment_handle = fragment_shader;
    result.geometry_handle = geometry_shader;
    return result;
}

void destroy_shader(shader_program_t shader) {
    if (shader.vertex_handle > 0) {
        glDeleteShader(shader.vertex_handle);
    }

    if (shader.fragment_handle > 0) {
        glDeleteShader(shader.fragment_handle);
    }

    if (shader.geometry_handle > 0) {
        glDeleteShader(shader.geometry_handle);
    }

    glDeleteProgram(shader.program);
}

uniform_t get_uniform_from_definition(shader_program_t shader, uniform_definition_t *definition) {
    uniform_t uniform = {};
    uniform.id = get_uniform_id(definition->name);
    uniform.value = definition->default_value;
    uniform.type = definition->type;
    uniform.handle = (uint) fmax(0, glGetUniformLocation(shader.program, definition->name));
    return uniform;
}

material_t create_material(material_definition_t definition) {
    material_t material = {};
    material.shader = create_shader(
            definition.vertex_code,
            definition.fragment_code,
            definition.geometry_code,
            definition.vertex_attrib_names
    );

    setup_list(&material.uniforms, definition.uniforms.length);
    for (int i = 0; i < definition.uniforms.length; ++i) {
        uniform_definition_t uniform_definition = definition.uniforms.items[i];
        uniform_t uniform = get_uniform_from_definition(material.shader, &uniform_definition);
        add(&material.uniforms, uniform);
    }
    return material;
}

void destroy_material(material_t material) {
    destroy_shader(material.shader);
    release_list(&material.uniforms);
}

// TODO: validate uniform type with the given type of value
void gl_set_bool(material_t *material, const char *uniform_name, bool value) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.bool_value = value;
    send_uniform_to_gl(uniform);
}

void gl_set_byte(material_t *material, const char *uniform_name, byte value) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.byte_value = value;
    send_uniform_to_gl(uniform);
}

void gl_set_ubyte(material_t *material, const char *uniform_name, ubyte value) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.ubyte_value = value;
    send_uniform_to_gl(uniform);
}

void gl_set_short(material_t *material, const char *uniform_name, short value) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.short_value = value;
    send_uniform_to_gl(uniform);
}

void gl_set_ushort(material_t *material, const char *uniform_name, ushort value) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.ushort_value = value;
    send_uniform_to_gl(uniform);
}

void gl_set_int(material_t *material, const char *uniform_name, int value) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.int_value = value;
    send_uniform_to_gl(uniform);
}

void gl_set_uint(material_t *material, const char *uniform_name, uint value) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.uint_value = value;
    send_uniform_to_gl(uniform);
}

void gl_set_long(material_t *material, const char *uniform_name, long value) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.long_value = value;
    send_uniform_to_gl(uniform);
}

void gl_set_float(material_t *material, const char *uniform_name, float value) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.float_value = value;
    send_uniform_to_gl(uniform);
}

void gl_set_double(material_t *material, const char *uniform_name, double value) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.double_value = value;
    send_uniform_to_gl(uniform);
}

void gl_set_vec2(material_t *material, const char *uniform_name, glm::vec2 value) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.vector2_value = value;
    send_uniform_to_gl(uniform);
}

void gl_set_vec3(material_t *material, const char *uniform_name, glm::vec3 value) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.vector3_value = value;
    send_uniform_to_gl(uniform);
}

void gl_set_vec4(material_t *material, const char *uniform_name, glm::vec4 value) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.vector4_value = value;
    send_uniform_to_gl(uniform);
}

void gl_set_matrix(material_t *material, const char *uniform_name, glm::mat4 value) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.matrix_value = value;
    send_uniform_to_gl(uniform);
}

void gl_set_texture(material_t *material, const char *uniform_name, texture_t texture) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.texture_value.texture = texture;
    send_uniform_to_gl(uniform);
}

void gl_set_texture_full(material_t *material, const char *uniform_name, texture_material_propery_t texture) {
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    uniform->value.texture_value = texture;
    send_uniform_to_gl(uniform);
}

bool gl_get_bool(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.bool_value;
}

byte gl_get_byte(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.byte_value;
}

ubyte gl_get_ubyte(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.ubyte_value;
}

short gl_get_short(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.short_value;
}

ushort gl_get_ushort(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.ushort_value;
}

int gl_get_int(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.int_value;
}

uint gl_get_uint(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.uint_value;
}

long gl_get_long(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.long_value;
}

float gl_get_float(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.float_value;
}

double gl_get_double(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.double_value;
}

glm::vec2 gl_get_vec2(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.vector2_value;
}

glm::vec3 gl_get_vec3(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.vector3_value;
}

glm::vec4 gl_get_vec4(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.vector4_value;
}

glm::mat4 gl_get_matrix(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.matrix_value;
}

texture_t gl_get_texture(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.texture_value.texture;
}

texture_material_propery_t gl_get_texture_full(material_t *material, const char *uniform_name){
    uniform_t *uniform = get_uniform(&material->uniforms, uniform_name);
    return uniform->value.texture_value;
}