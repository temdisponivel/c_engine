//
// Created by temdisponivel on 28/02/2018.
//

#ifndef ENGINE_VIDEO_H
#define ENGINE_VIDEO_H

#include "core/core.h"
#include "video.h"

typedef struct view_port {
    glm::vec2 size;
    glm::vec2 position;
} view_port_t;

typedef struct video_info {
    glm::ivec2 size;
    float ratio;
} video_info_t;

enum WINDOW_STATE {
    WINDOW_OK,
    WINDOW_DESTROYED,
    WINDOW_SHOULD_BE_CLOSED,
};

typedef struct window {
    video_info_t vide_info;
    WINDOW_STATE state;
    GLFWwindow *glfw_window;
} window_t;

typedef struct init_video_params {
    glm::ivec2 size;
    char *title;
} init_video_params_t;

enum INIT_VIDEO_RESULT {
    INIT_VIDEO_OK,
    INIT_VIDEO_FAIL
};

typedef struct video_state {
    window_t main_window;
} video_state_t;

INIT_VIDEO_RESULT init_video(init_video_params_t params);

void release_video();

window_t get_window();

video_info_t get_video_info();

glm::ivec2 get_video_size();

float get_video_ratio();

void update_video();

void swap_windows_buffers();

glm::vec3 pixel_to_world(glm::vec3 size);

#endif //ENGINE_VIDEO_H
