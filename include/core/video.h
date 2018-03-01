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

INIT_VIDEO_RESULT init_video(video_state_t *result, init_video_params_t params);

void release_video(video_state_t *video_state);

window_t get_window(const video_state_t *video_state);

video_info_t get_video_info(const video_state_t *video_state);

glm::ivec2 get_video_size(const video_state_t *video_state);

float get_video_ratio(const video_state_t *video_state);

void update_video(video_state_t *state);

void swap_windows_buffers(const video_state_t *state);

#endif //ENGINE_VIDEO_H
