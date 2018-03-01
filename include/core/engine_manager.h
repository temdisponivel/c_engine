//
// Created by temdisponivel on 01/03/2018.
//

#ifndef ENGINE_ENGINE_MANAGER_H
#define ENGINE_ENGINE_MANAGER_H

#include "core.h"
#include "video.h"
#include "input.h"

typedef struct internal_engine_state {
    bool should_break;
} internal_engine_state_t;

typedef struct engine_state {
    internal_engine_state_t engine_state;
    video_state_t video_state;
    input_state_t input_state;
} engine_state_t;

enum INIT_ENGINE_RESULT {
    INIT_ENGINE_OK,
    INIT_ENGINE_FAIL,
};

typedef struct init_engine_params {
    init_video_params_t video_params;
} init_engine_params_t;

INIT_ENGINE_RESULT init_engine(init_engine_params_t params);
void release_engine();

void loop();
void stop_loop();

const video_state_t *get_video_state();

#endif //ENGINE_ENGINE_MANAGER_H
