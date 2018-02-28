//
// Created by Morpheus on 06-Oct-17.
//

#ifndef CYNICAL_ENGINE_CYNICAL_LOG_H
#define CYNICAL_ENGINE_CYNICAL_LOG_H

#include <cstdio>
#include <csignal>
#include <cstdarg>
#include "core/core.h"

#if unix
#define ERROR_COLOR   "\x1B[31m"
#define WARNING_COLOR  "\x1B[33m"
#define NORMAL_COLOR "\x1B[0m"
#elif _WIN32
#define ERROR_COLOR
#define WARNING_COLOR
#define NORMAL_COLOR
#endif

#define INT_TO_STR_2(X) #X
#define INT_TO_STR(X) INT_TO_STR_2(X)

#define LOG_HEADER(COLOR, TYPE) COLOR "[" TYPE "]: "
#define LOG_FOOTER "\n-> " __FILE__ ":" INT_TO_STR(__LINE__) "\n\n"; NORMAL_COLOR
#define FILE_LINE "\n-> " __FILE__ ":" INT_TO_STR(__LINE__)

#define LOG_MESSAGE 0
#define LOG_WARNING 1
#define LOG_ERROR 2

#if DEV

void MESSAGEF(const char *format, ...);

void WARNINGF(const char *format, ...);

void ERRORF(const char *format, ...);

#else

#define MESSAGEF(format,...)
#define WARNINGF(format,...)
#define ERRORF(format,...)

#endif

#define FORMAT_VARARGS(format) {  \
    va_list args; \
    va_start(args, format); \
    vsnprintf(STRING_BUFF_HELPER, STRING_BUFF_HELPER_SIZE, format, args); \
    va_end(args); \
} \


#ifdef DEV

#define MESSAGE(MSG) {\
    char header[] = LOG_HEADER(NORMAL_COLOR,"MESSAGE");\
    char footer[] = LOG_FOOTER;\
    printf("%s%s%s",header, MSG, footer);\
}

#define WARNING(WARN_MESSAGE) {\
    char header[] = LOG_HEADER(WARNING_COLOR,"WARNING");\
    char footer[] = LOG_FOOTER;\
    char message[sizeof(header) + sizeof((WARN_MESSAGE)) + sizeof(footer)];\
    sprintf(message, "%s%s%s",header, (WARN_MESSAGE), footer);\
    printf(message);\
}

#define ERROR(ERR_MESSAGE) {\
    char header[] = LOG_HEADER(ERROR_COLOR,"ERROR");\
    char footer[] = LOG_FOOTER;\
    char message[sizeof(header) + sizeof((ERR_MESSAGE)) + sizeof(footer)];\
    sprintf(message, "%s%s%s",header, (ERR_MESSAGE), footer);\
    fprintf(stderr,message);\
}

#define ENSURE(RESULT) {\
    if (!(RESULT)) {\
        ERROR("Assertion failed!");\
    }\
}

#define ENSURE_BREAK(RESULT) {\
    if (!(RESULT)) {\
        ERROR("Assertion failed! Breaking into debugger!");\
        BREAK();\
    }\
}

#define ENSURE_EXIT(RESULT, EXIT_CODE) {\
    if (!(RESULT)) {\
        ERROR("Assertion failed! Exiting program!");\
        exit(EXIT_CODE);\
    }\
}

#define BREAK() __asm__("int $3")

#define LOG(MSG, TYPE) {\
    switch (TYPE) {\
        case LOG_WARNING:\
            WARNING((MSG)); \
            break;\
        case LOG_ERROR:\
            ERROR((MSG)); \
            break;\
        default:\
            MESSAGE((MSG)); \
            break;\
    }\
}

#define PRINT_GL_ERROR(MSG, ERR) {\
    if ((ERR) != GL_NO_ERROR){\
        switch ((ERR)) {\
            case GL_INVALID_ENUM:\
                ERROR(MSG "GL_INVALID_ENUM");\
                break;\
            case GL_INVALID_OPERATION:\
                ERROR(MSG "GL_INVALID_OPERATION");\
                break;\
            case GL_INVALID_VALUE:\
                ERROR(MSG "GL_INVALID_VALUE");\
                break;\
            default:\
                ERROR("UNKOWN GL ERROR!");\
                break;\
        }\
    }\
}\

#define PRINT_AL_ERROR(MSG,ERR) {\
    if ((ERR) != AL_NO_ERROR) {\
        switch ((ERR)) {\
            case AL_INVALID_ENUM:\
                ERROR(MSG "AL_INVALID_ENUM");\
                break;\
            case AL_INVALID_NAME:\
                ERROR(MSG "AL_INVALID_NAME");\
                break;\
            case AL_INVALID_OPERATION:\
                ERROR(MSG "AL_INVALID_OPERATION");\
                break;\
            case AL_INVALID_VALUE:\
                ERROR(MSG "AL_INVALID_VALUE");\
                break;\
            default:\
                ERROR("UNKOWN AL ERROR");\
                break;\
        }\
    }\
}\

#define PRINT_FBO_STATUS(MSG, STATUS) {\
    switch((STATUS)) {\
        case GL_FRAMEBUFFER_UNDEFINED:\
            ERROR(MSG "GL_FRAMEBUFFER_UNDEFINED");\
            break;\
        case GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT:\
            ERROR(MSG "GL_FRAMEBUFFER_INCOMPLETE_ATTACHMENT");\
            break;\
        case GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT:\
            ERROR(MSG "GL_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT");\
            break;\
        case GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER:\
            ERROR(MSG "GL_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER");\
            break;\
        case GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER:\
            ERROR(MSG "GL_FRAMEBUFFER_INCOMPLETE_READ_BUFFER");\
            break;\
        case GL_FRAMEBUFFER_UNSUPPORTED:\
            ERROR(MSG "GL_FRAMEBUFFER_UNSUPPORTED");\
            break;\
        case GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE:\
            ERROR(MSG "GL_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE");\
            break;\
        case GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS:\
            ERROR(MSG "GL_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS");\
            break;\
        default:\
            ERROR("UNKOWN FBO STATUS");\
            break;\
    }\
}\

#define CHECK_SHADER_COMPILE_STATUS(SHADER, SOURCE_CODE) {\
    if (glIsShader(SHADER)) {\
        GLint compile_status = GL_FALSE;\
        glGetShaderiv(SHADER, GL_COMPILE_STATUS, &compile_status);\
        if (compile_status != GL_TRUE) {\
            const char *format = "Unable to compile shader!\nError message: \n '%s' \n Shader source: \n %s \n.";\
            int info_log_length = 0;\
            glGetShaderiv(SHADER, GL_INFO_LOG_LENGTH, &info_log_length);\
            glGetShaderInfoLog(SHADER, STRING_BUFF_HELPER_SIZE, &info_log_length, STRING_BUFF_HELPER);\
            char header[] = LOG_HEADER(ERROR_COLOR,"ERROR");\
            fprintf(stderr, header); \
            fprintf(stderr, format, STRING_BUFF_HELPER, SOURCE_CODE); \
            char footer[] = LOG_FOOTER;\
            fprintf(stderr, footer); \
        }\
    }\
}\

#define CHECK_SHADER_LINK_STATUS(PROGRAM) {\
    if (glIsProgram(PROGRAM)) {\
        GLint link_status = GL_FALSE;\
        glGetProgramiv(PROGRAM, GL_LINK_STATUS, &link_status);\
        if (link_status != GL_TRUE) {\
            const char *format = "Unable to link program!\nError message: \n %s \n";\
            int info_log_length = 0;\
            glGetProgramiv(PROGRAM, GL_INFO_LOG_LENGTH, &info_log_length);\
            glGetProgramInfoLog(PROGRAM, STRING_BUFF_HELPER_SIZE, &info_log_length, STRING_BUFF_HELPER);\
            char header[] = LOG_HEADER(ERROR_COLOR,"ERROR");\
            fprintf(stderr, header); \
            fprintf(stderr, format, STRING_BUFF_HELPER); \
            char footer[] = LOG_FOOTER;\
            fprintf(stderr, footer); \
        }\
    }\
}\

#define CHECK_GL_ERROR() {\
    GLenum error = glGetError();\
    if (error != GL_NO_ERROR) {\
        PRINT_GL_ERROR("Gl error: ", error);\
    }\
}\

#define CHECK_FBO_STATUS() {\
    uint status = glCheckFramebufferStatus(GL_FRAMEBUFFER);\
    if (status != GL_FRAMEBUFFER_COMPLETE) {\
        PRINT_FBO_STATUS("FBO ERROR: ", status);\
    }\
}\

#define CHECK_AL_ERROR() {\
    ALenum error = alGetError();\
    if (error != AL_NO_ERROR) {\
        PRINT_AL_ERROR("Al error: ", error);\
    }\
}\

#else

#define MESSAGE(MSG)
#define WARNING(WARN_MESSAGE)
#define ERROR(ERR_MESSAGE)
#define ENSURE(RESULT)
#define LOG(MESSAGE,TYPE)
#define ASSERT_BREAK(RESULT)
#define BREAK()
#define ASSERT_EXIT(RESULT,EXIT_CODE)
#define PRING_GL_ERROR(MSG,ERROR)
#define PRINT_SHADER_ERROR(SHADER)
#define PRINT_PROGRAM_ERROR(PROGRAM)
#define CHECK_SHADER_COMPILE_STATUS(SHADER,SOURCE_CODE)
#define CHECK_SHADER_LINK_STATUS(PROG_HANDLE)
#define CHECK_GL_ERROR()
#define CHECK_FBO_STATUS()
#define PRINT_AL_ERROR(MSG,ERROR)
#define CHECK_AL_ERROR()

#endif

#endif //CYNICAL_ENGINE_CYNICAL_LOG_H