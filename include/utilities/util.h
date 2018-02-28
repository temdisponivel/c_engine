//
// Created by temdisponivel on 27/02/2018.
//

#ifndef ENGINE_UTIL_H
#define ENGINE_UTIL_H

#include "core/core.h"
#include <cstdio>

int hash(const char *str);
char *read_file_text(const char *file_path);
ubyte *read_file_content(const char *file_path, long *length, bool is_string);
void free_file_content(char *content);
char *copy_string(std::string string);

#endif //ENGINE_UTIL_H
