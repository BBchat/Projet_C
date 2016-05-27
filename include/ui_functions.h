#ifndef UI_FUNCTIONS_H_INCLUDED
#define UI_FUNCTIONS_H_INCLUDED

#ifdef _WIN32
#define WINDOWS 1
#else
#define WINDOWS 0
#endif


void clear_screen();
void draw_title();
void draw_mode1_ui();

#endif // UI_FUNCTIONS_H_INCLUDED
