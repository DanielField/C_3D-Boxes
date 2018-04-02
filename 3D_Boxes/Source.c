// Author: Daniel Field
#include <cab202_timers.h>
#include <cab202_graphics.h>
#include "Box.h"

#define DELAY 33

box b[2];

/*
* Create the boxes and store them in the box array.
*/
void setup() {
	b[0] = create_box(screen_width()*2/6, screen_height()*2/4, 1, 10, 10, 10);
	b[1] = create_box(screen_width()*3/4, screen_height()*2/4, 1, 13, 13, 13);
}

/*
* Rotate the boxes and update the screen.
*/
void process() {
	clear_screen();
	
	rotate_box(b[0],0.01, -0.005);
	rotate_box(b[1], 0.1, 0.1);

	draw_box(b[0]);
	draw_box(b[1]);

	show_screen();
}

int main() {
	setup_screen();
    setup();
	
    while (true) {
        process();
        timer_pause(DELAY);
    }
	
	return 0;
}