//
// Created by temdisponivel on 02/03/2018.
//

#ifndef ENGINE_ENGINE_MANAGER_H
#define ENGINE_ENGINE_MANAGER_H

#include "video.h"
#include "input.h"

typedef struct engine_state {
    bool break_loop;
} engine_state_t;

enum INITIALIZE_ENGINE_RESULT {
    INIT_ENGINE_OK,
    INIT_ENGINE_FAIL
};

typedef struct init_engine_params {
    init_video_params_t video_params;
} init_engine_params_t;

INITIALIZE_ENGINE_RESULT init_engine(init_engine_params_t params);
void release_engine();

void loop();

#endif //ENGINE_ENGINE_MANAGER_H
