//
// Created by temdisponivel on 27/02/2018.
//

#ifndef ENGINE_MAIN_GL_H
#define ENGINE_MAIN_GL_H

#include <core/core.h>
#include "gl/gl.h"

#define HANDLE_NONE 0

#define POSITION_ATTRIBUTE_INDEX 0
#define COLOR_ATTRIBUTE_INDEX 1
#define NORMAL_ATTRIBUTE_INDEX 2
#define TEX_COORD_ATTRIBUTE_INDEX 3

#define POSITION_ATTRIBUTE_NAME ((char *) "v_positions")
#define COLOR_ATTRIBUTE_NAME ((char *) "v_color")
#define NORMAL_ATTRIBUTE_NAME ((char *) "v_normal")
#define TEX_COORD_ATTRIBUTE_NAME ((char *) "v_tex_coord")

#define MVP_UNIFORM_NAME ((char *) "MVP")
#define MODEL_UNIFORM_NAME ((char *) "Object")
#define VIEW_UNIFORM_NAME ((char *) "View")
#define PROJECTION_UNIFORM_NAME ((char *) "Projection")


enum COMPARE_FUNCTIONS {
    COMPARE_DISABLED,
    COMPARE_LESS = GL_LESS,
    COMPARE_LESS_OR_EQUAL = GL_LEQUAL,
    COMPARE_EQUAL = GL_EQUAL,
    COMPARE_GREATER = GL_GREATER,
    COMPARE_GREATER_OR_EQUAL = GL_GEQUAL,
    COMPARE_DIFFERENT = GL_NOTEQUAL,
    COMPARE_ALWAYS_TRUE = GL_ALWAYS,
    COMPARE_NEVER_TRUE = GL_NEVER,
    COMPARE_DEFAULT = COMPARE_DISABLED,
};

#endif //ENGINE_MAIN_GL_H
