//
// Created by temdisponivel on 01/03/2018.
//

#include "core/input.h"


void key_callback(const input_state_t *state, GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (action == GLFW_REPEAT)
        return;

    glfwGetKey

    keyboard_state_t *state = &input_state->keyboard_state;

    if (key == KEY_SPACE) { state->key_space_state = get_key_updated_state(state->key_space_state, action); }
    if (key == KEY_APOSTROPHE) {
        state->key_apostrophe_state = get_key_updated_state(state->key_apostrophe_state, action);
    }
    if (key == KEY_COMMA) { state->key_comma_state = get_key_updated_state(state->key_comma_state, action); }
    if (key == KEY_MINUS) { state->key_minus_state = get_key_updated_state(state->key_minus_state, action); }
    if (key == KEY_PERIOD) { state->key_period_state = get_key_updated_state(state->key_period_state, action); }
    if (key == KEY_SLASH) { state->key_slash_state = get_key_updated_state(state->key_slash_state, action); }
    if (key == KEY_0) { state->key_0_state = get_key_updated_state(state->key_0_state, action); }
    if (key == KEY_1) { state->key_1_state = get_key_updated_state(state->key_1_state, action); }
    if (key == KEY_2) { state->key_2_state = get_key_updated_state(state->key_2_state, action); }
    if (key == KEY_3) { state->key_3_state = get_key_updated_state(state->key_3_state, action); }
    if (key == KEY_4) { state->key_4_state = get_key_updated_state(state->key_4_state, action); }
    if (key == KEY_5) { state->key_5_state = get_key_updated_state(state->key_5_state, action); }
    if (key == KEY_6) { state->key_6_state = get_key_updated_state(state->key_6_state, action); }
    if (key == KEY_7) { state->key_7_state = get_key_updated_state(state->key_7_state, action); }
    if (key == KEY_8) { state->key_8_state = get_key_updated_state(state->key_8_state, action); }
    if (key == KEY_9) { state->key_9_state = get_key_updated_state(state->key_9_state, action); }
    if (key == KEY_SEMICOLON) {
        state->key_semicolon_state = get_key_updated_state(state->key_semicolon_state, action);
    }
    if (key == KEY_EQUAL) { state->key_equal_state = get_key_updated_state(state->key_equal_state, action); }
    if (key == KEY_A) { state->key_a_state = get_key_updated_state(state->key_a_state, action); }
    if (key == KEY_B) { state->key_b_state = get_key_updated_state(state->key_b_state, action); }
    if (key == KEY_C) { state->key_c_state = get_key_updated_state(state->key_c_state, action); }
    if (key == KEY_D) { state->key_d_state = get_key_updated_state(state->key_d_state, action); }
    if (key == KEY_E) { state->key_e_state = get_key_updated_state(state->key_e_state, action); }
    if (key == KEY_F) { state->key_f_state = get_key_updated_state(state->key_f_state, action); }
    if (key == KEY_G) { state->key_g_state = get_key_updated_state(state->key_g_state, action); }
    if (key == KEY_H) { state->key_h_state = get_key_updated_state(state->key_h_state, action); }
    if (key == KEY_I) { state->key_i_state = get_key_updated_state(state->key_i_state, action); }
    if (key == KEY_J) { state->key_j_state = get_key_updated_state(state->key_j_state, action); }
    if (key == KEY_K) { state->key_k_state = get_key_updated_state(state->key_k_state, action); }
    if (key == KEY_L) { state->key_l_state = get_key_updated_state(state->key_l_state, action); }
    if (key == KEY_M) { state->key_m_state = get_key_updated_state(state->key_m_state, action); }
    if (key == KEY_N) { state->key_n_state = get_key_updated_state(state->key_n_state, action); }
    if (key == KEY_O) { state->key_o_state = get_key_updated_state(state->key_o_state, action); }
    if (key == KEY_P) { state->key_p_state = get_key_updated_state(state->key_p_state, action); }
    if (key == KEY_Q) { state->key_q_state = get_key_updated_state(state->key_q_state, action); }
    if (key == KEY_R) { state->key_r_state = get_key_updated_state(state->key_r_state, action); }
    if (key == KEY_S) { state->key_s_state = get_key_updated_state(state->key_s_state, action); }
    if (key == KEY_T) { state->key_t_state = get_key_updated_state(state->key_t_state, action); }
    if (key == KEY_U) { state->key_u_state = get_key_updated_state(state->key_u_state, action); }
    if (key == KEY_V) { state->key_v_state = get_key_updated_state(state->key_v_state, action); }
    if (key == KEY_W) { state->key_w_state = get_key_updated_state(state->key_w_state, action); }
    if (key == KEY_X) { state->key_x_state = get_key_updated_state(state->key_x_state, action); }
    if (key == KEY_Y) { state->key_y_state = get_key_updated_state(state->key_y_state, action); }
    if (key == KEY_Z) { state->key_z_state = get_key_updated_state(state->key_z_state, action); }
    if (key == KEY_LEFT_BRACKET) {
        state->key_left_bracket_state = get_key_updated_state(state->key_left_bracket_state, action);
    }
    if (key == KEY_BACKSLASH) {
        state->key_backslash_state = get_key_updated_state(state->key_backslash_state, action);
    }
    if (key == KEY_RIGHT_BRACKET) {
        state->key_right_bracket_state = get_key_updated_state(state->key_right_bracket_state, action);
    }
    if (key == KEY_GRAVE_ACCENT) {
        state->key_grave_accent_state = get_key_updated_state(state->key_grave_accent_state, action);
    }
    if (key == KEY_WORLD_1) {
        state->key_world_1_state = get_key_updated_state(state->key_world_1_state, action);
    }
    if (key == KEY_WORLD_2) {
        state->key_world_2_state = get_key_updated_state(state->key_world_2_state, action);
    }
    if (key == KEY_ESCAPE) { state->key_escape_state = get_key_updated_state(state->key_escape_state, action); }
    if (key == KEY_ENTER) { state->key_enter_state = get_key_updated_state(state->key_enter_state, action); }
    if (key == KEY_TAB) { state->key_tab_state = get_key_updated_state(state->key_tab_state, action); }
    if (key == KEY_BACKSPACE) {
        state->key_backspace_state = get_key_updated_state(state->key_backspace_state, action);
    }
    if (key == KEY_INSERT) { state->key_insert_state = get_key_updated_state(state->key_insert_state, action); }
    if (key == KEY_DELETE) { state->key_delete_state = get_key_updated_state(state->key_delete_state, action); }
    if (key == KEY_RIGHT) { state->key_right_state = get_key_updated_state(state->key_right_state, action); }
    if (key == KEY_LEFT) { state->key_left_state = get_key_updated_state(state->key_left_state, action); }
    if (key == KEY_DOWN) { state->key_down_state = get_key_updated_state(state->key_down_state, action); }
    if (key == KEY_UP) { state->key_up_state = get_key_updated_state(state->key_up_state, action); }
    if (key == KEY_PAGE_UP) {
        state->key_page_up_state = get_key_updated_state(state->key_page_up_state, action);
    }
    if (key == KEY_PAGE_DOWN) {
        state->key_page_down_state = get_key_updated_state(state->key_page_down_state, action);
    }
    if (key == KEY_HOME) { state->key_home_state = get_key_updated_state(state->key_home_state, action); }
    if (key == KEY_END) { state->key_end_state = get_key_updated_state(state->key_end_state, action); }
    if (key == KEY_CAPS_LOCK) {
        state->key_caps_lock_state = get_key_updated_state(state->key_caps_lock_state, action);
    }
    if (key == KEY_SCROLL_LOCK) {
        state->key_scroll_lock_state = get_key_updated_state(state->key_scroll_lock_state, action);
    }
    if (key == KEY_NUM_LOCK) {
        state->key_num_lock_state = get_key_updated_state(state->key_num_lock_state, action);
    }
    if (key == KEY_PRINT_SCREEN) {
        state->key_print_screen_state = get_key_updated_state(state->key_print_screen_state, action);
    }
    if (key == KEY_PAUSE) { state->key_pause_state = get_key_updated_state(state->key_pause_state, action); }
    if (key == KEY_F1) { state->key_f1_state = get_key_updated_state(state->key_f1_state, action); }
    if (key == KEY_F2) { state->key_f2_state = get_key_updated_state(state->key_f2_state, action); }
    if (key == KEY_F3) { state->key_f3_state = get_key_updated_state(state->key_f3_state, action); }
    if (key == KEY_F4) { state->key_f4_state = get_key_updated_state(state->key_f4_state, action); }
    if (key == KEY_F5) { state->key_f5_state = get_key_updated_state(state->key_f5_state, action); }
    if (key == KEY_F6) { state->key_f6_state = get_key_updated_state(state->key_f6_state, action); }
    if (key == KEY_F7) { state->key_f7_state = get_key_updated_state(state->key_f7_state, action); }
    if (key == KEY_F8) { state->key_f8_state = get_key_updated_state(state->key_f8_state, action); }
    if (key == KEY_F9) { state->key_f9_state = get_key_updated_state(state->key_f9_state, action); }
    if (key == KEY_F10) { state->key_f10_state = get_key_updated_state(state->key_f10_state, action); }
    if (key == KEY_F11) { state->key_f11_state = get_key_updated_state(state->key_f11_state, action); }
    if (key == KEY_F12) { state->key_f12_state = get_key_updated_state(state->key_f12_state, action); }
    if (key == KEY_F13) { state->key_f13_state = get_key_updated_state(state->key_f13_state, action); }
    if (key == KEY_F14) { state->key_f14_state = get_key_updated_state(state->key_f14_state, action); }
    if (key == KEY_F15) { state->key_f15_state = get_key_updated_state(state->key_f15_state, action); }
    if (key == KEY_F16) { state->key_f16_state = get_key_updated_state(state->key_f16_state, action); }
    if (key == KEY_F17) { state->key_f17_state = get_key_updated_state(state->key_f17_state, action); }
    if (key == KEY_F18) { state->key_f18_state = get_key_updated_state(state->key_f18_state, action); }
    if (key == KEY_F19) { state->key_f19_state = get_key_updated_state(state->key_f19_state, action); }
    if (key == KEY_F20) { state->key_f20_state = get_key_updated_state(state->key_f20_state, action); }
    if (key == KEY_F21) { state->key_f21_state = get_key_updated_state(state->key_f21_state, action); }
    if (key == KEY_F22) { state->key_f22_state = get_key_updated_state(state->key_f22_state, action); }
    if (key == KEY_F23) { state->key_f23_state = get_key_updated_state(state->key_f23_state, action); }
    if (key == KEY_F24) { state->key_f24_state = get_key_updated_state(state->key_f24_state, action); }
    if (key == KEY_F25) { state->key_f25_state = get_key_updated_state(state->key_f25_state, action); }
    if (key == KEY_KP_0) { state->key_kp_0_state = get_key_updated_state(state->key_kp_0_state, action); }
    if (key == KEY_KP_1) { state->key_kp_1_state = get_key_updated_state(state->key_kp_1_state, action); }
    if (key == KEY_KP_2) { state->key_kp_2_state = get_key_updated_state(state->key_kp_2_state, action); }
    if (key == KEY_KP_3) { state->key_kp_3_state = get_key_updated_state(state->key_kp_3_state, action); }
    if (key == KEY_KP_4) { state->key_kp_4_state = get_key_updated_state(state->key_kp_4_state, action); }
    if (key == KEY_KP_5) { state->key_kp_5_state = get_key_updated_state(state->key_kp_5_state, action); }
    if (key == KEY_KP_6) { state->key_kp_6_state = get_key_updated_state(state->key_kp_6_state, action); }
    if (key == KEY_KP_7) { state->key_kp_7_state = get_key_updated_state(state->key_kp_7_state, action); }
    if (key == KEY_KP_8) { state->key_kp_8_state = get_key_updated_state(state->key_kp_8_state, action); }
    if (key == KEY_KP_9) { state->key_kp_9_state = get_key_updated_state(state->key_kp_9_state, action); }
    if (key == KEY_KP_DECIMAL) {
        state->key_kp_decimal_state = get_key_updated_state(state->key_kp_decimal_state, action);
    }
    if (key == KEY_KP_DIVIDE) {
        state->key_kp_divide_state = get_key_updated_state(state->key_kp_divide_state, action);
    }
    if (key == KEY_KP_MULTIPLY) {
        state->key_kp_multiply_state = get_key_updated_state(state->key_kp_multiply_state, action);
    }
    if (key == KEY_KP_SUBTRACT) {
        state->key_kp_subtract_state = get_key_updated_state(state->key_kp_subtract_state, action);
    }
    if (key == KEY_KP_ADD) { state->key_kp_add_state = get_key_updated_state(state->key_kp_add_state, action); }
    if (key == KEY_KP_ENTER) {
        state->key_kp_enter_state = get_key_updated_state(state->key_kp_enter_state, action);
    }
    if (key == KEY_KP_EQUAL) {
        state->key_kp_equal_state = get_key_updated_state(state->key_kp_equal_state, action);
    }
    if (key == KEY_LEFT_SHIFT) {
        state->key_left_shift_state = get_key_updated_state(state->key_left_shift_state, action);
    }
    if (key == KEY_LEFT_CONTROL) {
        state->key_left_control_state = get_key_updated_state(state->key_left_control_state, action);
    }
    if (key == KEY_LEFT_ALT) {
        state->key_left_alt_state = get_key_updated_state(state->key_left_alt_state, action);
    }
    if (key == KEY_LEFT_SUPER) {
        state->key_left_super_state = get_key_updated_state(state->key_left_super_state, action);
    }
    if (key == KEY_RIGHT_SHIFT) {
        state->key_right_shift_state = get_key_updated_state(state->key_right_shift_state, action);
    }
    if (key == KEY_RIGHT_CONTROL) {
        state->key_right_control_state = get_key_updated_state(state->key_right_control_state, action);
    }
    if (key == KEY_RIGHT_ALT) {
        state->key_right_alt_state = get_key_updated_state(state->key_right_alt_state, action);
    }
    if (key == KEY_RIGHT_SUPER) {
        state->key_right_super_state = get_key_updated_state(state->key_right_super_state, action);
    }


    if ((MOD_SHIFT & mods) == MOD_SHIFT)
        state->mod_shift_state = get_key_updated_state(state->mod_shift_state, GLFW_PRESS);
    else
        state->mod_shift_state = get_key_updated_state(state->mod_shift_state, GLFW_RELEASE);

    if ((MOD_CONTROL & mods) == MOD_CONTROL)
        state->mod_control_state = get_key_updated_state(state->mod_control_state, GLFW_PRESS);
    else
        state->mod_control_state = get_key_updated_state(state->mod_control_state, GLFW_RELEASE);

    if ((MOD_ALT & mods) == MOD_ALT)
        state->mod_alt_state = get_key_updated_state(state->mod_alt_state, GLFW_PRESS);
    else
        state->mod_alt_state = get_key_updated_state(state->mod_alt_state, GLFW_RELEASE);

    if ((MOD_SUPER & mods) == MOD_SUPER)
        state->mod_super_state = get_key_updated_state(state->mod_super_state, GLFW_PRESS);
    else
        state->mod_super_state = get_key_updated_state(state->mod_super_state, GLFW_RELEASE);
}

void mouse_button_callback(const input_state_t *state, GLFWwindow *window, int button, int action, int mods) {
    if (action == GLFW_REPEAT)
        return;

    mouse_state_t *state = &input_state->mouse_state;
    if (button == MOUSE_BUTTON_1) {
        state->mouse_button_1_state = get_mouse_updated_state(state->mouse_button_1_state, action);
    }
    if (button == MOUSE_BUTTON_2) {
        state->mouse_button_2_state = get_mouse_updated_state(state->mouse_button_2_state, action);
    }
    if (button == MOUSE_BUTTON_3) {
        state->mouse_button_3_state = get_mouse_updated_state(state->mouse_button_3_state, action);
    }
    if (button == MOUSE_BUTTON_4) {
        state->mouse_button_4_state = get_mouse_updated_state(state->mouse_button_4_state, action);
    }
    if (button == MOUSE_BUTTON_5) {
        state->mouse_button_5_state = get_mouse_updated_state(state->mouse_button_5_state, action);
    }
    if (button == MOUSE_BUTTON_6) {
        state->mouse_button_6_state = get_mouse_updated_state(state->mouse_button_6_state, action);
    }
    if (button == MOUSE_BUTTON_7) {
        state->mouse_button_7_state = get_mouse_updated_state(state->mouse_button_7_state, action);
    }
    if (button == MOUSE_BUTTON_8) {
        state->mouse_button_8_state = get_mouse_updated_state(state->mouse_button_8_state, action);
    }
    if (button == MOUSE_BUTTON_LEFT) {
        state->mouse_button_left_state = get_mouse_updated_state(state->mouse_button_left_state, action);
    }
    if (button == MOUSE_BUTTON_RIGHT) {
        state->mouse_button_right_state = get_mouse_updated_state(state->mouse_button_right_state, action);
    }
    if (button == MOUSE_BUTTON_MIDDLE) {
        state->mouse_button_middle_state = get_mouse_updated_state(state->mouse_button_middle_state, action);
    }
}

void mouse_scroll_callback(GLFWwindow *window, double xoffset, double yoffset) {
    input_state->mouse_state.delta_scroll = glm::vec2((float) xoffset, (float) yoffset);
}

void mouse_position_callback(GLFWwindow *window, double x, double y) {
    input_state->mouse_state.screen_position = glm::vec2((float) x, (float) y);
}

void prepare_input(const GLFWwindow *window) {
    input_state = (input_state_t *) memalloc(sizeof(input_state_t));
    memset(input_state, 0, sizeof(input_state_t));

    glfwSetKeyCallback((GLFWwindow *) window, &key_callback);
    glfwSetCursorPosCallback((GLFWwindow *) window, &mouse_position_callback);
    glfwSetScrollCallback((GLFWwindow *) window, &mouse_scroll_callback);
    glfwSetMouseButtonCallback((GLFWwindow *) window, &mouse_button_callback);
}

void release_input() {
    memfree(input_state);

    // TODO: maybe we need to set the callbacks to null here?!
}

void update_input() {
    update_keyboard_state(&input_state->keyboard_state);
    update_mouse_state(&input_state->mouse_state);

    glfwPollEvents();
}

KEY_STATE get_next_key_state(KEY_STATE current_state) {
    if (current_state == KEY_STATE_PRESSED)
        return KEY_STATE_DOWN;
    else if (current_state == KEY_STATE_RELEASED)
        return KEY_STATE_NORMAL;
    else
        return current_state;
}

void update_keyboard_state(keyboard_state_t *state) {
    state->key_space_state = get_next_key_state(state->key_space_state);
    state->key_apostrophe_state = get_next_key_state(state->key_apostrophe_state);
    state->key_comma_state = get_next_key_state(state->key_comma_state);
    state->key_minus_state = get_next_key_state(state->key_minus_state);
    state->key_period_state = get_next_key_state(state->key_period_state);
    state->key_slash_state = get_next_key_state(state->key_slash_state);
    state->key_0_state = get_next_key_state(state->key_0_state);
    state->key_1_state = get_next_key_state(state->key_1_state);
    state->key_2_state = get_next_key_state(state->key_2_state);
    state->key_3_state = get_next_key_state(state->key_3_state);
    state->key_4_state = get_next_key_state(state->key_4_state);
    state->key_5_state = get_next_key_state(state->key_5_state);
    state->key_6_state = get_next_key_state(state->key_6_state);
    state->key_7_state = get_next_key_state(state->key_7_state);
    state->key_8_state = get_next_key_state(state->key_8_state);
    state->key_9_state = get_next_key_state(state->key_9_state);
    state->key_semicolon_state = get_next_key_state(state->key_semicolon_state);
    state->key_equal_state = get_next_key_state(state->key_equal_state);
    state->key_a_state = get_next_key_state(state->key_a_state);
    state->key_b_state = get_next_key_state(state->key_b_state);
    state->key_c_state = get_next_key_state(state->key_c_state);
    state->key_d_state = get_next_key_state(state->key_d_state);
    state->key_e_state = get_next_key_state(state->key_e_state);
    state->key_f_state = get_next_key_state(state->key_f_state);
    state->key_g_state = get_next_key_state(state->key_g_state);
    state->key_h_state = get_next_key_state(state->key_h_state);
    state->key_i_state = get_next_key_state(state->key_i_state);
    state->key_j_state = get_next_key_state(state->key_j_state);
    state->key_k_state = get_next_key_state(state->key_k_state);
    state->key_l_state = get_next_key_state(state->key_l_state);
    state->key_m_state = get_next_key_state(state->key_m_state);
    state->key_n_state = get_next_key_state(state->key_n_state);
    state->key_o_state = get_next_key_state(state->key_o_state);
    state->key_p_state = get_next_key_state(state->key_p_state);
    state->key_q_state = get_next_key_state(state->key_q_state);
    state->key_r_state = get_next_key_state(state->key_r_state);
    state->key_s_state = get_next_key_state(state->key_s_state);
    state->key_t_state = get_next_key_state(state->key_t_state);
    state->key_u_state = get_next_key_state(state->key_u_state);
    state->key_v_state = get_next_key_state(state->key_v_state);
    state->key_w_state = get_next_key_state(state->key_w_state);
    state->key_x_state = get_next_key_state(state->key_x_state);
    state->key_y_state = get_next_key_state(state->key_y_state);
    state->key_z_state = get_next_key_state(state->key_z_state);
    state->key_left_bracket_state = get_next_key_state(state->key_left_bracket_state);
    state->key_backslash_state = get_next_key_state(state->key_backslash_state);
    state->key_right_bracket_state = get_next_key_state(state->key_right_bracket_state);
    state->key_grave_accent_state = get_next_key_state(state->key_grave_accent_state);
    state->key_world_1_state = get_next_key_state(state->key_world_1_state);
    state->key_world_2_state = get_next_key_state(state->key_world_2_state);
    state->key_escape_state = get_next_key_state(state->key_escape_state);
    state->key_enter_state = get_next_key_state(state->key_enter_state);
    state->key_tab_state = get_next_key_state(state->key_tab_state);
    state->key_backspace_state = get_next_key_state(state->key_backspace_state);
    state->key_insert_state = get_next_key_state(state->key_insert_state);
    state->key_delete_state = get_next_key_state(state->key_delete_state);
    state->key_right_state = get_next_key_state(state->key_right_state);
    state->key_left_state = get_next_key_state(state->key_left_state);
    state->key_down_state = get_next_key_state(state->key_down_state);
    state->key_up_state = get_next_key_state(state->key_up_state);
    state->key_page_up_state = get_next_key_state(state->key_page_up_state);
    state->key_page_down_state = get_next_key_state(state->key_page_down_state);
    state->key_home_state = get_next_key_state(state->key_home_state);
    state->key_end_state = get_next_key_state(state->key_end_state);
    state->key_caps_lock_state = get_next_key_state(state->key_caps_lock_state);
    state->key_scroll_lock_state = get_next_key_state(state->key_scroll_lock_state);
    state->key_num_lock_state = get_next_key_state(state->key_num_lock_state);
    state->key_print_screen_state = get_next_key_state(state->key_print_screen_state);
    state->key_pause_state = get_next_key_state(state->key_pause_state);
    state->key_f1_state = get_next_key_state(state->key_f1_state);
    state->key_f2_state = get_next_key_state(state->key_f2_state);
    state->key_f3_state = get_next_key_state(state->key_f3_state);
    state->key_f4_state = get_next_key_state(state->key_f4_state);
    state->key_f5_state = get_next_key_state(state->key_f5_state);
    state->key_f6_state = get_next_key_state(state->key_f6_state);
    state->key_f7_state = get_next_key_state(state->key_f7_state);
    state->key_f8_state = get_next_key_state(state->key_f8_state);
    state->key_f9_state = get_next_key_state(state->key_f9_state);
    state->key_f10_state = get_next_key_state(state->key_f10_state);
    state->key_f11_state = get_next_key_state(state->key_f11_state);
    state->key_f12_state = get_next_key_state(state->key_f12_state);
    state->key_f13_state = get_next_key_state(state->key_f13_state);
    state->key_f14_state = get_next_key_state(state->key_f14_state);
    state->key_f15_state = get_next_key_state(state->key_f15_state);
    state->key_f16_state = get_next_key_state(state->key_f16_state);
    state->key_f17_state = get_next_key_state(state->key_f17_state);
    state->key_f18_state = get_next_key_state(state->key_f18_state);
    state->key_f19_state = get_next_key_state(state->key_f19_state);
    state->key_f20_state = get_next_key_state(state->key_f20_state);
    state->key_f21_state = get_next_key_state(state->key_f21_state);
    state->key_f22_state = get_next_key_state(state->key_f22_state);
    state->key_f23_state = get_next_key_state(state->key_f23_state);
    state->key_f24_state = get_next_key_state(state->key_f24_state);
    state->key_f25_state = get_next_key_state(state->key_f25_state);
    state->key_kp_0_state = get_next_key_state(state->key_kp_0_state);
    state->key_kp_1_state = get_next_key_state(state->key_kp_1_state);
    state->key_kp_2_state = get_next_key_state(state->key_kp_2_state);
    state->key_kp_3_state = get_next_key_state(state->key_kp_3_state);
    state->key_kp_4_state = get_next_key_state(state->key_kp_4_state);
    state->key_kp_5_state = get_next_key_state(state->key_kp_5_state);
    state->key_kp_6_state = get_next_key_state(state->key_kp_6_state);
    state->key_kp_7_state = get_next_key_state(state->key_kp_7_state);
    state->key_kp_8_state = get_next_key_state(state->key_kp_8_state);
    state->key_kp_9_state = get_next_key_state(state->key_kp_9_state);
    state->key_kp_decimal_state = get_next_key_state(state->key_kp_decimal_state);
    state->key_kp_divide_state = get_next_key_state(state->key_kp_divide_state);
    state->key_kp_multiply_state = get_next_key_state(state->key_kp_multiply_state);
    state->key_kp_subtract_state = get_next_key_state(state->key_kp_subtract_state);
    state->key_kp_add_state = get_next_key_state(state->key_kp_add_state);
    state->key_kp_enter_state = get_next_key_state(state->key_kp_enter_state);
    state->key_kp_equal_state = get_next_key_state(state->key_kp_equal_state);
    state->key_left_shift_state = get_next_key_state(state->key_left_shift_state);
    state->key_left_control_state = get_next_key_state(state->key_left_control_state);
    state->key_left_alt_state = get_next_key_state(state->key_left_alt_state);
    state->key_left_super_state = get_next_key_state(state->key_left_super_state);
    state->key_right_shift_state = get_next_key_state(state->key_right_shift_state);
    state->key_right_control_state = get_next_key_state(state->key_right_control_state);
    state->key_right_alt_state = get_next_key_state(state->key_right_alt_state);
    state->key_right_super_state = get_next_key_state(state->key_right_super_state);
    state->key_menu_state = get_next_key_state(state->key_menu_state);
    state->mod_shift_state = get_next_key_state(state->mod_shift_state);
    state->mod_control_state = get_next_key_state(state->mod_control_state);
    state->mod_alt_state = get_next_key_state(state->mod_alt_state);
    state->mod_super_state = get_next_key_state(state->mod_super_state);
}

MOUSE_BUTTON_STATE get_next_mouse_state(MOUSE_BUTTON_STATE current_state) {
    if (current_state == MOUSE_BUTTON_STATE_PRESSED)
        return MOUSE_BUTTON_STATE_DOWN;
    else if (current_state == MOUSE_BUTTON_STATE_RELEASED)
        return MOUSE_BUTTON_STATE_NORMAL;
    else
        return current_state;
}

void update_mouse_state(mouse_state_t *state) {
    // TODO: make a falloff functions, not just reset
    state->delta_scroll = glm::vec2(0, 0);

    state->mouse_button_1_state = get_next_mouse_state(state->mouse_button_1_state);
    state->mouse_button_2_state = get_next_mouse_state(state->mouse_button_2_state);
    state->mouse_button_3_state = get_next_mouse_state(state->mouse_button_3_state);
    state->mouse_button_4_state = get_next_mouse_state(state->mouse_button_4_state);
    state->mouse_button_5_state = get_next_mouse_state(state->mouse_button_5_state);
    state->mouse_button_6_state = get_next_mouse_state(state->mouse_button_6_state);
    state->mouse_button_7_state = get_next_mouse_state(state->mouse_button_7_state);
    state->mouse_button_8_state = get_next_mouse_state(state->mouse_button_8_state);
    state->mouse_button_left_state = get_next_mouse_state(state->mouse_button_left_state);
    state->mouse_button_right_state = get_next_mouse_state(state->mouse_button_right_state);
    state->mouse_button_middle_state = get_next_mouse_state(state->mouse_button_middle_state);
}

input_state_t get_input_state() {
    return *input_state;
}

KEY_STATE get_key_updated_state(KEY_STATE current_state, int glfw_state) {
    KEY_STATE updated_state = current_state;
    if (glfw_state == GLFW_PRESS) {
        if (current_state == KEY_STATE_DOWN || current_state == KEY_STATE_PRESSED) {
            updated_state = KEY_STATE_DOWN;
        } else if (current_state == KEY_STATE_RELEASED || current_state == KEY_STATE_NORMAL) {
            updated_state = KEY_STATE_PRESSED;
        }
    } else if (glfw_state == GLFW_RELEASE) {
        if (current_state == KEY_STATE_DOWN || current_state == KEY_STATE_PRESSED) {
            updated_state = KEY_STATE_RELEASED;
        } else if (current_state == KEY_STATE_RELEASED || current_state == KEY_STATE_NORMAL) {
            updated_state = KEY_STATE_NORMAL;
        }
    }

    return updated_state;
}

KEY_STATE get_key_state(KEY key) {
    if (key == KEY_SPACE) { return input_state->keyboard_state.key_space_state; }
    if (key == KEY_APOSTROPHE) { return input_state->keyboard_state.key_apostrophe_state; }
    if (key == KEY_COMMA) { return input_state->keyboard_state.key_comma_state; }
    if (key == KEY_MINUS) { return input_state->keyboard_state.key_minus_state; }
    if (key == KEY_PERIOD) { return input_state->keyboard_state.key_period_state; }
    if (key == KEY_SLASH) { return input_state->keyboard_state.key_slash_state; }
    if (key == KEY_0) { return input_state->keyboard_state.key_0_state; }
    if (key == KEY_1) { return input_state->keyboard_state.key_1_state; }
    if (key == KEY_2) { return input_state->keyboard_state.key_2_state; }
    if (key == KEY_3) { return input_state->keyboard_state.key_3_state; }
    if (key == KEY_4) { return input_state->keyboard_state.key_4_state; }
    if (key == KEY_5) { return input_state->keyboard_state.key_5_state; }
    if (key == KEY_6) { return input_state->keyboard_state.key_6_state; }
    if (key == KEY_7) { return input_state->keyboard_state.key_7_state; }
    if (key == KEY_8) { return input_state->keyboard_state.key_8_state; }
    if (key == KEY_9) { return input_state->keyboard_state.key_9_state; }
    if (key == KEY_SEMICOLON) { return input_state->keyboard_state.key_semicolon_state; }
    if (key == KEY_EQUAL) { return input_state->keyboard_state.key_equal_state; }
    if (key == KEY_A) { return input_state->keyboard_state.key_a_state; }
    if (key == KEY_B) { return input_state->keyboard_state.key_b_state; }
    if (key == KEY_C) { return input_state->keyboard_state.key_c_state; }
    if (key == KEY_D) { return input_state->keyboard_state.key_d_state; }
    if (key == KEY_E) { return input_state->keyboard_state.key_e_state; }
    if (key == KEY_F) { return input_state->keyboard_state.key_f_state; }
    if (key == KEY_G) { return input_state->keyboard_state.key_g_state; }
    if (key == KEY_H) { return input_state->keyboard_state.key_h_state; }
    if (key == KEY_I) { return input_state->keyboard_state.key_i_state; }
    if (key == KEY_J) { return input_state->keyboard_state.key_j_state; }
    if (key == KEY_K) { return input_state->keyboard_state.key_k_state; }
    if (key == KEY_L) { return input_state->keyboard_state.key_l_state; }
    if (key == KEY_M) { return input_state->keyboard_state.key_m_state; }
    if (key == KEY_N) { return input_state->keyboard_state.key_n_state; }
    if (key == KEY_O) { return input_state->keyboard_state.key_o_state; }
    if (key == KEY_P) { return input_state->keyboard_state.key_p_state; }
    if (key == KEY_Q) { return input_state->keyboard_state.key_q_state; }
    if (key == KEY_R) { return input_state->keyboard_state.key_r_state; }
    if (key == KEY_S) { return input_state->keyboard_state.key_s_state; }
    if (key == KEY_T) { return input_state->keyboard_state.key_t_state; }
    if (key == KEY_U) { return input_state->keyboard_state.key_u_state; }
    if (key == KEY_V) { return input_state->keyboard_state.key_v_state; }
    if (key == KEY_W) { return input_state->keyboard_state.key_w_state; }
    if (key == KEY_X) { return input_state->keyboard_state.key_x_state; }
    if (key == KEY_Y) { return input_state->keyboard_state.key_y_state; }
    if (key == KEY_Z) { return input_state->keyboard_state.key_z_state; }
    if (key == KEY_LEFT_BRACKET) { return input_state->keyboard_state.key_left_bracket_state; }
    if (key == KEY_BACKSLASH) { return input_state->keyboard_state.key_backslash_state; }
    if (key == KEY_RIGHT_BRACKET) { return input_state->keyboard_state.key_right_bracket_state; }
    if (key == KEY_GRAVE_ACCENT) { return input_state->keyboard_state.key_grave_accent_state; }
    if (key == KEY_WORLD_1) { return input_state->keyboard_state.key_world_1_state; }
    if (key == KEY_WORLD_2) { return input_state->keyboard_state.key_world_2_state; }
    if (key == KEY_ESCAPE) { return input_state->keyboard_state.key_escape_state; }
    if (key == KEY_ENTER) { return input_state->keyboard_state.key_enter_state; }
    if (key == KEY_TAB) { return input_state->keyboard_state.key_tab_state; }
    if (key == KEY_BACKSPACE) { return input_state->keyboard_state.key_backspace_state; }
    if (key == KEY_INSERT) { return input_state->keyboard_state.key_insert_state; }
    if (key == KEY_DELETE) { return input_state->keyboard_state.key_delete_state; }
    if (key == KEY_RIGHT) { return input_state->keyboard_state.key_right_state; }
    if (key == KEY_LEFT) { return input_state->keyboard_state.key_left_state; }
    if (key == KEY_DOWN) { return input_state->keyboard_state.key_down_state; }
    if (key == KEY_UP) { return input_state->keyboard_state.key_up_state; }
    if (key == KEY_PAGE_UP) { return input_state->keyboard_state.key_page_up_state; }
    if (key == KEY_PAGE_DOWN) { return input_state->keyboard_state.key_page_down_state; }
    if (key == KEY_HOME) { return input_state->keyboard_state.key_home_state; }
    if (key == KEY_END) { return input_state->keyboard_state.key_end_state; }
    if (key == KEY_CAPS_LOCK) { return input_state->keyboard_state.key_caps_lock_state; }
    if (key == KEY_SCROLL_LOCK) { return input_state->keyboard_state.key_scroll_lock_state; }
    if (key == KEY_NUM_LOCK) { return input_state->keyboard_state.key_num_lock_state; }
    if (key == KEY_PRINT_SCREEN) { return input_state->keyboard_state.key_print_screen_state; }
    if (key == KEY_PAUSE) { return input_state->keyboard_state.key_pause_state; }
    if (key == KEY_F1) { return input_state->keyboard_state.key_f1_state; }
    if (key == KEY_F2) { return input_state->keyboard_state.key_f2_state; }
    if (key == KEY_F3) { return input_state->keyboard_state.key_f3_state; }
    if (key == KEY_F4) { return input_state->keyboard_state.key_f4_state; }
    if (key == KEY_F5) { return input_state->keyboard_state.key_f5_state; }
    if (key == KEY_F6) { return input_state->keyboard_state.key_f6_state; }
    if (key == KEY_F7) { return input_state->keyboard_state.key_f7_state; }
    if (key == KEY_F8) { return input_state->keyboard_state.key_f8_state; }
    if (key == KEY_F9) { return input_state->keyboard_state.key_f9_state; }
    if (key == KEY_F10) { return input_state->keyboard_state.key_f10_state; }
    if (key == KEY_F11) { return input_state->keyboard_state.key_f11_state; }
    if (key == KEY_F12) { return input_state->keyboard_state.key_f12_state; }
    if (key == KEY_F13) { return input_state->keyboard_state.key_f13_state; }
    if (key == KEY_F14) { return input_state->keyboard_state.key_f14_state; }
    if (key == KEY_F15) { return input_state->keyboard_state.key_f15_state; }
    if (key == KEY_F16) { return input_state->keyboard_state.key_f16_state; }
    if (key == KEY_F17) { return input_state->keyboard_state.key_f17_state; }
    if (key == KEY_F18) { return input_state->keyboard_state.key_f18_state; }
    if (key == KEY_F19) { return input_state->keyboard_state.key_f19_state; }
    if (key == KEY_F20) { return input_state->keyboard_state.key_f20_state; }
    if (key == KEY_F21) { return input_state->keyboard_state.key_f21_state; }
    if (key == KEY_F22) { return input_state->keyboard_state.key_f22_state; }
    if (key == KEY_F23) { return input_state->keyboard_state.key_f23_state; }
    if (key == KEY_F24) { return input_state->keyboard_state.key_f24_state; }
    if (key == KEY_F25) { return input_state->keyboard_state.key_f25_state; }
    if (key == KEY_KP_0) { return input_state->keyboard_state.key_kp_0_state; }
    if (key == KEY_KP_1) { return input_state->keyboard_state.key_kp_1_state; }
    if (key == KEY_KP_2) { return input_state->keyboard_state.key_kp_2_state; }
    if (key == KEY_KP_3) { return input_state->keyboard_state.key_kp_3_state; }
    if (key == KEY_KP_4) { return input_state->keyboard_state.key_kp_4_state; }
    if (key == KEY_KP_5) { return input_state->keyboard_state.key_kp_5_state; }
    if (key == KEY_KP_6) { return input_state->keyboard_state.key_kp_6_state; }
    if (key == KEY_KP_7) { return input_state->keyboard_state.key_kp_7_state; }
    if (key == KEY_KP_8) { return input_state->keyboard_state.key_kp_8_state; }
    if (key == KEY_KP_9) { return input_state->keyboard_state.key_kp_9_state; }
    if (key == KEY_KP_DECIMAL) { return input_state->keyboard_state.key_kp_decimal_state; }
    if (key == KEY_KP_DIVIDE) { return input_state->keyboard_state.key_kp_divide_state; }
    if (key == KEY_KP_MULTIPLY) { return input_state->keyboard_state.key_kp_multiply_state; }
    if (key == KEY_KP_SUBTRACT) { return input_state->keyboard_state.key_kp_subtract_state; }
    if (key == KEY_KP_ADD) { return input_state->keyboard_state.key_kp_add_state; }
    if (key == KEY_KP_ENTER) { return input_state->keyboard_state.key_kp_enter_state; }
    if (key == KEY_KP_EQUAL) { return input_state->keyboard_state.key_kp_equal_state; }
    if (key == KEY_LEFT_SHIFT) { return input_state->keyboard_state.key_left_shift_state; }
    if (key == KEY_LEFT_CONTROL) { return input_state->keyboard_state.key_left_control_state; }
    if (key == KEY_LEFT_ALT) { return input_state->keyboard_state.key_left_alt_state; }
    if (key == KEY_LEFT_SUPER) { return input_state->keyboard_state.key_left_super_state; }
    if (key == KEY_RIGHT_SHIFT) { return input_state->keyboard_state.key_right_shift_state; }
    if (key == KEY_RIGHT_CONTROL) { return input_state->keyboard_state.key_right_control_state; }
    if (key == KEY_RIGHT_ALT) { return input_state->keyboard_state.key_right_alt_state; }
    if (key == KEY_RIGHT_SUPER) { return input_state->keyboard_state.key_right_super_state; }
    if (key == KEY_MENU) { return input_state->keyboard_state.key_menu_state; }
    if (key == MOD_SHIFT) { return input_state->keyboard_state.mod_shift_state; }
    if (key == MOD_CONTROL) { return input_state->keyboard_state.mod_control_state; }
    if (key == MOD_ALT) { return input_state->keyboard_state.mod_alt_state; }
    if (key == MOD_SUPER) { return input_state->keyboard_state.mod_super_state; }
}

bool is_key_pressed(KEY key) {
    return get_key_state(key) == KEY_STATE_PRESSED;
}

bool is_key_down(KEY key) {
    return get_key_state(key) == KEY_STATE_DOWN;
}

bool is_key_released(KEY key) {
    return get_key_state(key) == KEY_STATE_RELEASED;
}

bool is_key_normal(KEY key) {
    return get_key_state(key) == KEY_STATE_NORMAL;
}

const char *get_key_name(KEY key) {
    return glfwGetKeyName(key, 0);
}

MOUSE_BUTTON_STATE get_mouse_updated_state(MOUSE_BUTTON_STATE current_state, uint glfw_state) {
    MOUSE_BUTTON_STATE updated_state = current_state;
    if (glfw_state == GLFW_PRESS) {
        if (current_state == MOUSE_BUTTON_STATE_DOWN || current_state == MOUSE_BUTTON_STATE_PRESSED) {
            updated_state = MOUSE_BUTTON_STATE_DOWN;
        } else if (current_state == MOUSE_BUTTON_STATE_RELEASED || current_state == MOUSE_BUTTON_STATE_NORMAL) {
            updated_state = MOUSE_BUTTON_STATE_PRESSED;
        }
    } else if (glfw_state == GLFW_RELEASE) {
        if (current_state == MOUSE_BUTTON_STATE_DOWN || current_state == MOUSE_BUTTON_STATE_PRESSED) {
            updated_state = MOUSE_BUTTON_STATE_RELEASED;
        } else if (current_state == MOUSE_BUTTON_STATE_RELEASED || current_state == MOUSE_BUTTON_STATE_NORMAL) {
            updated_state = MOUSE_BUTTON_STATE_NORMAL;
        }
    }

    return updated_state;
}

MOUSE_BUTTON_STATE get_mouse_button_state(MOUSE_BUTTON button) {
    if (button == MOUSE_BUTTON_1) { return input_state->mouse_state.mouse_button_1_state; }
    if (button == MOUSE_BUTTON_2) { return input_state->mouse_state.mouse_button_2_state; }
    if (button == MOUSE_BUTTON_3) { return input_state->mouse_state.mouse_button_3_state; }
    if (button == MOUSE_BUTTON_4) { return input_state->mouse_state.mouse_button_4_state; }
    if (button == MOUSE_BUTTON_5) { return input_state->mouse_state.mouse_button_5_state; }
    if (button == MOUSE_BUTTON_6) { return input_state->mouse_state.mouse_button_6_state; }
    if (button == MOUSE_BUTTON_7) { return input_state->mouse_state.mouse_button_7_state; }
    if (button == MOUSE_BUTTON_8) { return input_state->mouse_state.mouse_button_8_state; }
}

bool is_mouse_button_pressed(MOUSE_BUTTON button) {
    return get_mouse_button_state(button) == MOUSE_BUTTON_STATE_PRESSED;
}

bool is_mouse_button_down(MOUSE_BUTTON button) {
    return get_mouse_button_state(button) == MOUSE_BUTTON_STATE_DOWN;
}

bool is_mouse_button_release(MOUSE_BUTTON button) {
    return get_mouse_button_state(button) == MOUSE_BUTTON_STATE_RELEASED;
}

bool is_mouse_button_normal(MOUSE_BUTTON button) {
    return get_mouse_button_state(button) == MOUSE_BUTTON_STATE_NORMAL;
}

glm::vec2 get_mouse_screen_pos() {
    return input_state->mouse_state.screen_position;
}

glm::vec2 get_mouse_delta_scroll() {
    return input_state->mouse_state.delta_scroll;
}