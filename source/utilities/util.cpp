//
// Created by temdisponivel on 27/02/2018.
//


#include "utilities/util.h"

char *read_file_text(const char *file_path) {
    long len;
    return (char *) read_file_content(file_path, &len, true);
}

ubyte *read_file_content(const char *file_path, long *length, bool is_string) {
    FILE *file = fopen(file_path, "rb");

    ENSURE(file != null);

    fseek(file, 0, SEEK_END);
    long len = ftell(file);

    long total_length = len;
    if (is_string)
        total_length += 1;

    ubyte *buffer = (ubyte *) memalloc(sizeof(ubyte) * (total_length));
    fseek(file, 0, SEEK_SET);
    fread(buffer, (uint) total_length, 1, file);

    if (is_string)
        buffer[len] = '\0';

    fclose(file);

    *length = len;
    return buffer;
}

void free_file_content(char *content) {
    memfree(content);
}

int hash(const char *str) {
    int hash = 0;
    char c;
    while ((c = *str++) != '\0') {
        hash += c;
    }
    return hash;
}

char *copy_string(std::string string) {
    char *name = (char *) memalloc(sizeof(char) * string.size());
    memcpy(name, string.c_str(), sizeof(char) * string.size());
    return name;
}