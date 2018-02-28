//
// Created by temdisponivel on 27/02/2018.
//

#ifndef ENGINE_MODELS_H
#define ENGINE_MODELS_H

#include <core/core.h>
#include "materials.h"

typedef struct model_data {
    list<float> vertices;
    list<float> uvs;
    list<float> colors;
    list<float> normals;
    list<int> indices;

    char *material_name;
} model_data_t;

typedef struct model {
    list<model_data_t> childs;

    char *model_name;
} model_t;

typedef struct mesh_data {
    gl_handle vao_handle;
    gl_handle vbo_handle;
    gl_handle vio_handle;

    model_data_t model;
    material_t material;
} mesh_data_t;

typedef struct mesh {
    list<mesh_data_t> childs;
} mesh_t;

#endif //ENGINE_MODELS_H
