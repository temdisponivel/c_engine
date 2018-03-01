//
// Created by temdisponivel on 28/02/2018.
//

#include "core/video.h"

INIT_VIDEO_RESULT init_video(video_state_t *result, init_video_params_t params) {

    // TODO: Get this from params
    glfwWindowHint(GLFW_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_VERSION_MINOR, 0);

    GLFWwindow *glfw_window = glfwCreateWindow(params.size.x, params.size.y, params.title, null, null);
    if (glfw_window == null) {
        ERROR("COULDN'T CREATE GLFW WINDOW!");
        return INIT_VIDEO_FAIL;
    }

    glfwMakeContextCurrent(glfw_window);

    // TODO: Do we always do this?
    glfwSwapInterval(1);

    window_t window;

    window.state = WINDOW_OK;
    window.vide_info.size = params.size;
    window.vide_info.ratio = params.size.x / (params.size.y * 1.f);
    window.glfw_window = glfw_window;

    result->main_window = window;
}

void release_video(video_state_t *video_state) {
    video_state->main_window.state = WINDOW_DESTROYED;
    glfwDestroyWindow(video_state->main_window.glfw_window);
}

window_t get_window(const video_state_t *video_state) {
    return video_state->main_window;
}

video_info_t get_video_info(const video_state_t *video_state) {
    return video_state->main_window.vide_info;
}

glm::ivec2 get_video_size(const video_state_t *video_state) {
    return video_state->main_window.vide_info.size;
}

float get_video_ratio(const video_state_t *video_state) {
    return video_state->main_window.vide_info.ratio;
}

void update_video(video_state_t *state) {
    glfwPollEvents();

    window_t *window = &state->main_window;
    glfwGetWindowSize(window->glfw_window, &window->vide_info.size.x, &window->vide_info.size.y);
    window->vide_info.ratio = window->vide_info.size.x / (window->vide_info.size.y * 1.0f);

    if (glfwWindowShouldClose(window->glfw_window))
        window->state =  WINDOW_SHOULD_BE_CLOSED;
    else
        window->state = WINDOW_OK;
}

void swap_windows_buffers(const video_state_t *state) {
    glfwSwapBuffers(state->main_window.glfw_window);
}