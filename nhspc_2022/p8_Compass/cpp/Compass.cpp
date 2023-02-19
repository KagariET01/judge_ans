#include "Compass.h"

void draw_circle(){
    
    set_col(5, 1, 3, 1);
    set_col(5, -3, 3, 1);
    or_row(6, 0, 5, 0, 4, 4, 1);
    set_row(-3, 5, 7, 1);
    and_col(0, 4, 0, 4, 0, 5, 2);
    not_row(-4, 4, -4, 4, 1);
    xor_col(-5, -3, 5, -3, -5, -3, 7);
    xor_col(-5, 0, 6, 0, -6, 0, 1);
    set_row(-3, -5, 7, 1);
    not_col(0, -6, 0, -6, 2);
    set_col(-4, -4, 1, 1);
    set_col(4, -4, 1, 1);

}
