#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <cab202_graphics.h>
#include <cab202_timers.h>
#include <math.h>
#include <string.h>

// Define the box structure
typedef struct Box {
	double x;
	double y;
	double z;
	double width;
	double height;
	double depth;
	double points[9][3];
	int lines[12][2];
} Box;

// Create a pointer to the box struct.
typedef Box *box;

// scales the box width, height and depth by the specified value
void scale_box(box b, double width, double height, double depth);
// create and initialize the box
box create_box(double x, double y, double z, double width, double height, double depth);
// rotate the box by the specified angle
void rotate_box(box b, double angle_x, double angle_y);
// Draw the box in the middle of the screen
void draw_box(box b);