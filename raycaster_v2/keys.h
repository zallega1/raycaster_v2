#ifndef KEYS_H
#define KEYS_H

//define keys struct, used in main.c for input
struct Keys {
	int w, a, s, d, space, e, p, up, down, left, right, enter, esc;
	int g0, g1; //weapon switch hotkeys
};
struct Keys k;

#endif