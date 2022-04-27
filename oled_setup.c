/*
 * Copyright QMK Community
 * Copyright 2021 Tyler Thrailkill (@snowe/@snowe2010) <tyler.b.thrailkill@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef OLED_ENABLE

#    include QMK_KEYBOARD_H
#    include "quantum.h"
#    include "ocean_dream.c"
#    include "ocean_dream.h"
/* #    include "bongocat.c" */

#    include <stdio.h>  // for keylog?

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
    }
    return OLED_ROTATION_0;
}

char wpm_str[10];

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        /* render_stars(); */
        /* render_anim();  // renders pixelart */
        oled_set_cursor(7, 2);                            // sets cursor to (row, column) using charactar spacing (5 rows on 128x32 screen, anything more will overflow back to the top)
        /* oled_set_cursor(0, 0);                            // sets cursor to (row, column) using charactar spacing (5 rows on 128x32 screen, anything more will overflow back to the top) */
        sprintf(wpm_str, "WPM:%03d", get_current_wpm());  // edit the string to change wwhat shows up, edit %03d to change how many digits show up
        oled_write(wpm_str, false);                       // writes wpm on top left corner of string

        /* led_t led_state = host_keyboard_led_state();  // caps lock stuff, prints CAPS on new line if caps led is on */
        /* oled_set_cursor(0, 1); */
        /* oled_write_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("       "), false); */
    } else {
        /* render_stars(); */
        oled_set_cursor(8, 7);                            // sets cursor to (row, column) using charactar spacing (5 rows on 128x32 screen, anything more will overflow back to the top)
        oled_write("<3", false);                       // writes wpm on top left corner of string
    }
    return false;
}

#endif
