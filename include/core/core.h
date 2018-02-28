//
// Created by temdisponivel on 27/02/2018.
//

#ifndef ENGINE_CORE_H
#define ENGINE_CORE_H

#define STBI_MALLOC __default_allocator
#define STBI_FREE __default_deallocator
#define STBI_REALLOC __default_reallocator
#define STBI_ASSERT ENSURE

#define null NULL

#include "types.h"
#include <gl/glew.h>
#include <glfw/glfw3.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/detail/type_mat.hpp>
#include <glm/detail/type_mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <string>
#include <cstdlib>
#include <utilities/log.h>
#include <stb_image.h>
#include <memory.h>
#include <al/al.h>
#include <al/alc.h>
#include <math.h>
#include <utilities/collections.h>

#define STB_VORBIS_HEADER_ONLY
#include <stb_vorbis.c>

#define STRING_BUFF_HELPER_SIZE 2048
static char STRING_BUFF_HELPER[2048];

#endif //ENGINE_CORE_H
