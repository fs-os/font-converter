
#include <stdio.h>
#include <stdint.h>
#include "font.h"

#include "input.h"

/*
 * Vim macro for comments:
 *   Ev€@7€kly257k€@7p258j€kh
 */

int main() {
    /* Target (y8, x7) font */
    Font* g_font = &main_font;

    /* Each char */
    for (unsigned char c = 0; c < 255; c++) {
        /* Start of the line, we convert height 8 to 10. We add one now and one after
         */
        printf("\"x00");

        /* Font px loop */
        for (uint8_t fy = 0; fy < g_font->h; fy++) {
            /* Final byte containing the bits of the row */
            uint8_t new_byte = 0;

            /* Because we are from 1 to 7, the first bit (rightmost bit, but leftmost
             * in px), should be set to 0 to reach the new 8 bits that form the new
             * width. Thats why we add 1 to fx */
            for (uint8_t fx = 0; fx < g_font->w; fx++) {
                /* We check if the current bit of the current column is 1.
                 * Depending on that, set it to foreground or background. For
                 * more information see: src/kernel/include/kernel/font.h */
                if (get_font_bit(g_font, c, fy, fx)) {
                    new_byte |= (1 << (fx + 1));
                }

                /* We don't need else because ignored bits will be 0 */
            }

            printf("\\x%02x", new_byte);
        }

        /* End of line. Last "\x00" and close str */
        printf("\\x00\"\n");
    }

    return 0;
}

