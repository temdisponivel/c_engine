//
// Created by temdisponivel on 28/02/2018.
//

#include "core/video.h"

static video_state_t video_state = {};

void window_size_callback(GLFWwindow* window, int width, int height) {
    glfwGetWindowSize(
            window,
            &video_state.main_window.vide_info.size.x,
            &video_state.main_window.vide_info.size.y
    );

    video_info_t info = video_state.main_window.vide_info;
    info.ratio = info.size.x / (info.size.y * 1.0f);
    video_state.main_window.vide_info = info;
}

INIT_VIDEO_RESULT init_video(init_video_params_t params) {

    // TODO: Get this from params
    glfwWindowHint(GLFW_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_VERSION_MINOR, 0);

    GLFWwindow *glfw_window = glfwCreateWindow(params.size.x, params.size.y, params.title, null, null);
    if (glfw_window == null) {
        ERROR("COULDN'T CREATE GLFW WINDOW!");
        return INIT_VIDEO_FAIL;
    }

    glfwSetWindowSizeCallback(glfw_window, &window_size_callback);
    glfwMakeContextCurrent(glfw_window);

    // TODO: Do we always do this?
    glfwSwapInterval(1);

    window_t window;

    window.state = WINDOW_OK;
    window.vide_info.size = params.size;
    window.vide_info.ratio = params.size.x / (params.size.y * 1.f);
    window.glfw_window = glfw_window;

    video_state.main_window = window;
}

void release_video() {
    video_state.main_window.state = WINDOW_DESTROYED;
    glfwDestroyWindow(video_state.main_window.glfw_window);
}

void update_video() {
    if (glfwWindowShouldClose(video_state.main_window.glfw_window))
        video_state.main_window.state =  WINDOW_SHOULD_BE_CLOSED;
    else
        video_state.main_window.state = WINDOW_OK;
}

window_t get_window() {
    return video_state.main_window;
}

video_info_t get_video_info() {
    return video_state.main_window.vide_info;
}

glm::ivec2 get_video_size() {
    return video_state.main_window.vide_info.size;
}

float get_video_ratio() {
    return video_state.main_window.vide_info.ratio;
}

void swap_windows_buffers() {
    glfwSwapBuffers(video_state.main_window.glfw_window);
}