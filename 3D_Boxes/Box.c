#include <assert.h>
#include <cab202_graphics.h>
#include <math.h>
#include "Box.h"

box b;

// create and initialize the box
box create_box(double x, double y, double z, double width, double height, double depth) {
	assert(width > 0 && height > 0 && depth > 0);
	
	box b = malloc(sizeof(Box));
	
	if (b != NULL) {
		b->x = x;
		b->y = y;
		b->z = z;
		b->width = width;
		b->height = height;
		b->depth = depth;
		
		// The points of the box
		double points[9][3] = {
			{-1, -1, -1}, 
			{-1, -1, 1}, 
			{-1, 1, -1}, 
			{-1, 1, 1}, 
			{1, -1, -1}, 
			{1, -1, 1}, 
			{1, 1, -1}, 
			{1, 1, 1}};
		// Indices for the points of each line
		int lines[12][2] = {
			{0, 1}, 
			{1, 3}, 
			{3, 2}, 
			{2, 0}, 
			{4, 5}, 
			{5, 7}, 
			{7, 6}, 
			{6, 4}, 
			{0, 4}, 
			{1, 5}, 
			{2, 6}, 
			{3, 7}};
		
		memcpy(b->points,points,sizeof(b->points));
		memcpy(b->lines,lines,sizeof(b->lines));
		
		scale_box(b, width/2, height/2, depth/2);
	}
	
	return b;
}

// rotate the box by the specified angle
void rotate_box(box b, double angle_x, double angle_y) {
	for (int i = 0; i < sizeof(b->points)/sizeof(b->points[0]); i++) {
		double x = b->points[i][0];
		double y = b->points[i][1];
		double z = b->points[i][2];

		b->points[i][0] = x * cos(angle_x) - z * sin(angle_x);
		b->points[i][2] = z * cos(angle_x) + x * sin(angle_x);
		z = b->points[i][2];
		b->points[i][1] = y * cos(angle_y) - z * sin(angle_y);
		b->points[i][2] = z * cos(angle_y) + y * sin(angle_y);
	}
}

// Draw the box in the middle of the screen
void draw_box(box b) {
	for (int i = 0; i < sizeof(b->lines)/sizeof(b->lines[0]); i++) {
		double x1 = b->points[b->lines[i][0]][0]; // x value of the first point
		double y1 = b->points[b->lines[i][0]][1]; // y value of the first point
		double x2 = b->points[b->lines[i][1]][0]; // x value of the second point
		double y2 = b->points[b->lines[i][1]][1]; // y value of the second point
		
		// get the smallest z value
		double smallest = b->points[0][2];
		for (int i = 0; i < sizeof(b->points)/sizeof(b->points[0]); i++) {
			if (smallest > b->points[i][2]){
				smallest = b->points[i][2];
			}
		}

		// if the line's view isn't obstructed by the rest of the box
		if (b->points[b->lines[i][0]][2] > smallest && b->points[b->lines[i][1]][2] > smallest) {
			draw_line((int) round(x1)+b->x, (int) round(y1)+b->y,
					  (int) round(x2)+b->x, (int) round(y2)+b->y, '*');
		}
	}
}

// scales the box width, height and depth by the specified value
void scale_box(box b, double width, double height, double depth) {
	for (int i = 0; i < sizeof(b->points)/sizeof(b->points[0]); i++) {
		b->points[i][0] *= b->width;
		b->points[i][1] *= b->height;
		b->points[i][2] *= b->depth;
    }
}