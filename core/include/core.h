#pragma once
#ifdef LIBRARY_EXPORTS
#    define CORE __declspec(dllexport)
#else
#    define CORE __declspec(dllimport)
#endif
void message (void);

void core_create_window(void);
void core_loop(void);
void core_close_window(void);