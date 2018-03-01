//
// Created by temdisponivel on 01/03/2018.
//

#ifndef ENGINE_INPUT_H
#define ENGINE_INPUT_H

#include "core.h"

enum INIT_INPUT_RESULT {
    INIT_INPUT_OK,
    INIT_INPUT_FAIL
};

enum KEY {
    KEY_SPACE = GLFW_KEY_SPACE,
    KEY_APOSTROPHE = GLFW_KEY_APOSTROPHE,
    KEY_COMMA = GLFW_KEY_COMMA,
    KEY_MINUS = GLFW_KEY_MINUS,
    KEY_PERIOD = GLFW_KEY_PERIOD,
    KEY_SLASH = GLFW_KEY_SLASH,
    KEY_0 = GLFW_KEY_0,
    KEY_1 = GLFW_KEY_1,
    KEY_2 = GLFW_KEY_2,
    KEY_3 = GLFW_KEY_3,
    KEY_4 = GLFW_KEY_4,
    KEY_5 = GLFW_KEY_5,
    KEY_6 = GLFW_KEY_6,
    KEY_7 = GLFW_KEY_7,
    KEY_8 = GLFW_KEY_8,
    KEY_9 = GLFW_KEY_9,
    KEY_SEMICOLON = GLFW_KEY_SEMICOLON,
    KEY_EQUAL = GLFW_KEY_EQUAL,
    KEY_A = GLFW_KEY_A,
    KEY_B = GLFW_KEY_B,
    KEY_C = GLFW_KEY_C,
    KEY_D = GLFW_KEY_D,
    KEY_E = GLFW_KEY_E,
    KEY_F = GLFW_KEY_F,
    KEY_G = GLFW_KEY_G,
    KEY_H = GLFW_KEY_H,
    KEY_I = GLFW_KEY_I,
    KEY_J = GLFW_KEY_J,
    KEY_K = GLFW_KEY_K,
    KEY_L = GLFW_KEY_L,
    KEY_M = GLFW_KEY_M,
    KEY_N = GLFW_KEY_N,
    KEY_O = GLFW_KEY_O,
    KEY_P = GLFW_KEY_P,
    KEY_Q = GLFW_KEY_Q,
    KEY_R = GLFW_KEY_R,
    KEY_S = GLFW_KEY_S,
    KEY_T = GLFW_KEY_T,
    KEY_U = GLFW_KEY_U,
    KEY_V = GLFW_KEY_V,
    KEY_W = GLFW_KEY_W,
    KEY_X = GLFW_KEY_X,
    KEY_Y = GLFW_KEY_Y,
    KEY_Z = GLFW_KEY_Z,
    KEY_LEFT_BRACKET = GLFW_KEY_LEFT_BRACKET,
    KEY_BACKSLASH = GLFW_KEY_BACKSLASH,
    KEY_RIGHT_BRACKET = GLFW_KEY_RIGHT_BRACKET,
    KEY_GRAVE_ACCENT = GLFW_KEY_GRAVE_ACCENT,
    KEY_WORLD_1 = GLFW_KEY_WORLD_1,
    KEY_WORLD_2 = GLFW_KEY_WORLD_2,
    KEY_ESCAPE = GLFW_KEY_ESCAPE,
    KEY_ENTER = GLFW_KEY_ENTER,
    KEY_TAB = GLFW_KEY_TAB,
    KEY_BACKSPACE = GLFW_KEY_BACKSPACE,
    KEY_INSERT = GLFW_KEY_INSERT,
    KEY_DELETE = GLFW_KEY_DELETE,
    KEY_RIGHT = GLFW_KEY_RIGHT,
    KEY_LEFT = GLFW_KEY_LEFT,
    KEY_DOWN = GLFW_KEY_DOWN,
    KEY_UP = GLFW_KEY_UP,
    KEY_PAGE_UP = GLFW_KEY_PAGE_UP,
    KEY_PAGE_DOWN = GLFW_KEY_PAGE_DOWN,
    KEY_HOME = GLFW_KEY_HOME,
    KEY_END = GLFW_KEY_END,
    KEY_CAPS_LOCK = GLFW_KEY_CAPS_LOCK,
    KEY_SCROLL_LOCK = GLFW_KEY_SCROLL_LOCK,
    KEY_NUM_LOCK = GLFW_KEY_NUM_LOCK,
    KEY_PRINT_SCREEN = GLFW_KEY_PRINT_SCREEN,
    KEY_PAUSE = GLFW_KEY_PAUSE,
    KEY_F1 = GLFW_KEY_F1,
    KEY_F2 = GLFW_KEY_F2,
    KEY_F3 = GLFW_KEY_F3,
    KEY_F4 = GLFW_KEY_F4,
    KEY_F5 = GLFW_KEY_F5,
    KEY_F6 = GLFW_KEY_F6,
    KEY_F7 = GLFW_KEY_F7,
    KEY_F8 = GLFW_KEY_F8,
    KEY_F9 = GLFW_KEY_F9,
    KEY_F10 = GLFW_KEY_F10,
    KEY_F11 = GLFW_KEY_F11,
    KEY_F12 = GLFW_KEY_F12,
    KEY_F13 = GLFW_KEY_F13,
    KEY_F14 = GLFW_KEY_F14,
    KEY_F15 = GLFW_KEY_F15,
    KEY_F16 = GLFW_KEY_F16,
    KEY_F17 = GLFW_KEY_F17,
    KEY_F18 = GLFW_KEY_F18,
    KEY_F19 = GLFW_KEY_F19,
    KEY_F20 = GLFW_KEY_F20,
    KEY_F21 = GLFW_KEY_F21,
    KEY_F22 = GLFW_KEY_F22,
    KEY_F23 = GLFW_KEY_F23,
    KEY_F24 = GLFW_KEY_F24,
    KEY_F25 = GLFW_KEY_F25,
    KEY_KP_0 = GLFW_KEY_KP_0,
    KEY_KP_1 = GLFW_KEY_KP_1,
    KEY_KP_2 = GLFW_KEY_KP_2,
    KEY_KP_3 = GLFW_KEY_KP_3,
    KEY_KP_4 = GLFW_KEY_KP_4,
    KEY_KP_5 = GLFW_KEY_KP_5,
    KEY_KP_6 = GLFW_KEY_KP_6,
    KEY_KP_7 = GLFW_KEY_KP_7,
    KEY_KP_8 = GLFW_KEY_KP_8,
    KEY_KP_9 = GLFW_KEY_KP_9,
    KEY_KP_DECIMAL = GLFW_KEY_KP_DECIMAL,
    KEY_KP_DIVIDE = GLFW_KEY_KP_DIVIDE,
    KEY_KP_MULTIPLY = GLFW_KEY_KP_MULTIPLY,
    KEY_KP_SUBTRACT = GLFW_KEY_KP_SUBTRACT,
    KEY_KP_ADD = GLFW_KEY_KP_ADD,
    KEY_KP_ENTER = GLFW_KEY_KP_ENTER,
    KEY_KP_EQUAL = GLFW_KEY_KP_EQUAL,
    KEY_LEFT_SHIFT = GLFW_KEY_LEFT_SHIFT,
    KEY_LEFT_CONTROL = GLFW_KEY_LEFT_CONTROL,
    KEY_LEFT_ALT = GLFW_KEY_LEFT_ALT,
    KEY_LEFT_SUPER = GLFW_KEY_LEFT_SUPER,
    KEY_RIGHT_SHIFT = GLFW_KEY_RIGHT_SHIFT,
    KEY_RIGHT_CONTROL = GLFW_KEY_RIGHT_CONTROL,
    KEY_RIGHT_ALT = GLFW_KEY_RIGHT_ALT,
    KEY_RIGHT_SUPER = GLFW_KEY_RIGHT_SUPER,
    KEY_MENU = GLFW_KEY_MENU,
    MOD_SHIFT = GLFW_MOD_SHIFT,
    MOD_CONTROL = GLFW_MOD_CONTROL,
    MOD_ALT = GLFW_MOD_ALT,
    MOD_SUPER = GLFW_MOD_SUPER,
};

enum MOUSE_BUTTON {
    MOUSE_BUTTON_1 = GLFW_MOUSE_BUTTON_1,
    MOUSE_BUTTON_2 = GLFW_MOUSE_BUTTON_2,
    MOUSE_BUTTON_3 = GLFW_MOUSE_BUTTON_3,
    MOUSE_BUTTON_4 = GLFW_MOUSE_BUTTON_4,
    MOUSE_BUTTON_5 = GLFW_MOUSE_BUTTON_5,
    MOUSE_BUTTON_6 = GLFW_MOUSE_BUTTON_6,
    MOUSE_BUTTON_7 = GLFW_MOUSE_BUTTON_7,
    MOUSE_BUTTON_8 = GLFW_MOUSE_BUTTON_8,
    MOUSE_BUTTON_LEFT = GLFW_MOUSE_BUTTON_1,
    MOUSE_BUTTON_RIGHT = GLFW_MOUSE_BUTTON_2,
    MOUSE_BUTTON_MIDDLE = GLFW_MOUSE_BUTTON_3,
};

enum KEY_STATE {
    KEY_STATE_NORMAL = 10, // to prevent conflict with GLFW_PRESS/GLFW_RELEASE
    KEY_STATE_DOWN = 20, // to prevent conflict with GLFW_PRESS/GLFW_RELEASE
    KEY_STATE_PRESSED = GLFW_PRESS,
    KEY_STATE_RELEASED = GLFW_RELEASE,
};

enum MOUSE_BUTTON_STATE {
    MOUSE_BUTTON_STATE_NORMAL = 10, // to prevent conflict with GLFW_PRESS/GLFW_RELEASE
    MOUSE_BUTTON_STATE_DOWN = 20, // to prevent conflict with GLFW_PRESS/GLFW_RELEASE
    MOUSE_BUTTON_STATE_PRESSED = GLFW_PRESS,
    MOUSE_BUTTON_STATE_RELEASED = GLFW_RELEASE,
};

typedef struct keyboard_state {
    KEY_STATE key_space_state;
    KEY_STATE key_apostrophe_state;
    KEY_STATE key_comma_state;
    KEY_STATE key_minus_state;
    KEY_STATE key_period_state;
    KEY_STATE key_slash_state;
    KEY_STATE key_0_state;
    KEY_STATE key_1_state;
    KEY_STATE key_2_state;
    KEY_STATE key_3_state;
    KEY_STATE key_4_state;
    KEY_STATE key_5_state;
    KEY_STATE key_6_state;
    KEY_STATE key_7_state;
    KEY_STATE key_8_state;
    KEY_STATE key_9_state;
    KEY_STATE key_semicolon_state;
    KEY_STATE key_equal_state;
    KEY_STATE key_a_state;
    KEY_STATE key_b_state;
    KEY_STATE key_c_state;
    KEY_STATE key_d_state;
    KEY_STATE key_e_state;
    KEY_STATE key_f_state;
    KEY_STATE key_g_state;
    KEY_STATE key_h_state;
    KEY_STATE key_i_state;
    KEY_STATE key_j_state;
    KEY_STATE key_k_state;
    KEY_STATE key_l_state;
    KEY_STATE key_m_state;
    KEY_STATE key_n_state;
    KEY_STATE key_o_state;
    KEY_STATE key_p_state;
    KEY_STATE key_q_state;
    KEY_STATE key_r_state;
    KEY_STATE key_s_state;
    KEY_STATE key_t_state;
    KEY_STATE key_u_state;
    KEY_STATE key_v_state;
    KEY_STATE key_w_state;
    KEY_STATE key_x_state;
    KEY_STATE key_y_state;
    KEY_STATE key_z_state;
    KEY_STATE key_left_bracket_state;
    KEY_STATE key_backslash_state;
    KEY_STATE key_right_bracket_state;
    KEY_STATE key_grave_accent_state;
    KEY_STATE key_world_1_state;
    KEY_STATE key_world_2_state;
    KEY_STATE key_escape_state;
    KEY_STATE key_enter_state;
    KEY_STATE key_tab_state;
    KEY_STATE key_backspace_state;
    KEY_STATE key_insert_state;
    KEY_STATE key_delete_state;
    KEY_STATE key_right_state;
    KEY_STATE key_left_state;
    KEY_STATE key_down_state;
    KEY_STATE key_up_state;
    KEY_STATE key_page_up_state;
    KEY_STATE key_page_down_state;
    KEY_STATE key_home_state;
    KEY_STATE key_end_state;
    KEY_STATE key_caps_lock_state;
    KEY_STATE key_scroll_lock_state;
    KEY_STATE key_num_lock_state;
    KEY_STATE key_print_screen_state;
    KEY_STATE key_pause_state;
    KEY_STATE key_f1_state;
    KEY_STATE key_f2_state;
    KEY_STATE key_f3_state;
    KEY_STATE key_f4_state;
    KEY_STATE key_f5_state;
    KEY_STATE key_f6_state;
    KEY_STATE key_f7_state;
    KEY_STATE key_f8_state;
    KEY_STATE key_f9_state;
    KEY_STATE key_f10_state;
    KEY_STATE key_f11_state;
    KEY_STATE key_f12_state;
    KEY_STATE key_f13_state;
    KEY_STATE key_f14_state;
    KEY_STATE key_f15_state;
    KEY_STATE key_f16_state;
    KEY_STATE key_f17_state;
    KEY_STATE key_f18_state;
    KEY_STATE key_f19_state;
    KEY_STATE key_f20_state;
    KEY_STATE key_f21_state;
    KEY_STATE key_f22_state;
    KEY_STATE key_f23_state;
    KEY_STATE key_f24_state;
    KEY_STATE key_f25_state;
    KEY_STATE key_kp_0_state;
    KEY_STATE key_kp_1_state;
    KEY_STATE key_kp_2_state;
    KEY_STATE key_kp_3_state;
    KEY_STATE key_kp_4_state;
    KEY_STATE key_kp_5_state;
    KEY_STATE key_kp_6_state;
    KEY_STATE key_kp_7_state;
    KEY_STATE key_kp_8_state;
    KEY_STATE key_kp_9_state;
    KEY_STATE key_kp_decimal_state;
    KEY_STATE key_kp_divide_state;
    KEY_STATE key_kp_multiply_state;
    KEY_STATE key_kp_subtract_state;
    KEY_STATE key_kp_add_state;
    KEY_STATE key_kp_enter_state;
    KEY_STATE key_kp_equal_state;
    KEY_STATE key_left_shift_state;
    KEY_STATE key_left_control_state;
    KEY_STATE key_left_alt_state;
    KEY_STATE key_left_super_state;
    KEY_STATE key_right_shift_state;
    KEY_STATE key_right_control_state;
    KEY_STATE key_right_alt_state;
    KEY_STATE key_right_super_state;
    KEY_STATE key_menu_state;
    KEY_STATE mod_shift_state;
    KEY_STATE mod_control_state;
    KEY_STATE mod_alt_state;
    KEY_STATE mod_super_state;
} keyboard_state_t;

typedef struct mouse_state {
    MOUSE_BUTTON_STATE mouse_button_1_state;
    MOUSE_BUTTON_STATE mouse_button_2_state;
    MOUSE_BUTTON_STATE mouse_button_3_state;
    MOUSE_BUTTON_STATE mouse_button_4_state;
    MOUSE_BUTTON_STATE mouse_button_5_state;
    MOUSE_BUTTON_STATE mouse_button_6_state;
    MOUSE_BUTTON_STATE mouse_button_7_state;
    MOUSE_BUTTON_STATE mouse_button_8_state;
    MOUSE_BUTTON_STATE mouse_button_left_state;
    MOUSE_BUTTON_STATE mouse_button_right_state;
    MOUSE_BUTTON_STATE mouse_button_middle_state;

    glm::vec2 screen_position;
    glm::vec2 delta_scroll;
} mouse_state_t;

typedef struct input_state {
    keyboard_state_t keyboard_state;
    mouse_state_t mouse_state;
} input_state_t;

INIT_INPUT_RESULT init_input(input_state_t *state);

void release_input(input_state_t *state);

void update_input(input_state_t *state);

KEY_STATE get_key_state(const input_state_t *state, KEY key);

bool is_key_pressed(const input_state_t *state, KEY key);

bool is_key_down(const input_state_t *state, KEY key);

bool is_key_released(const input_state_t *state, KEY key);

bool is_key_normal(const input_state_t *state, KEY key);

const char *get_key_name(const input_state_t *state, KEY key);

MOUSE_BUTTON_STATE get_mouse_updated_state(
        const input_state_t *state,
        MOUSE_BUTTON_STATE current_state,
        uint glfw_state
);

MOUSE_BUTTON_STATE get_mouse_button_state(const input_state_t *state, MOUSE_BUTTON button);

bool is_mouse_button_pressed(const input_state_t *state, MOUSE_BUTTON button);

bool is_mouse_button_down(const input_state_t *state, MOUSE_BUTTON button);

bool is_mouse_button_release(const input_state_t *state, MOUSE_BUTTON button);

bool is_mouse_button_normal(const input_state_t *state, MOUSE_BUTTON button);

glm::vec2 get_mouse_screen_pos(const input_state_t *state);

glm::vec2 get_mouse_delta_scroll(const input_state_t *state);

#endif //ENGINE_INPUT_H
