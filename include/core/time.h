//
// Created by temdisponivel on 02/04/2018.
//

#ifndef ENGINE_TIME_H
#define ENGINE_TIME_H

#include "core.h"


typedef struct time_state {
    double time;
    float dt;
} time_state_t;

void init_time();

float get_dt();

void update_time();

void time_start_frame();

void time_finish_frame();

#endif //ENGINE_TIME_H
