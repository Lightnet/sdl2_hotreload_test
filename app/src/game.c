// Simple C program to display "Hello World"
 
// Header file for input output functions
#include <stdio.h>
 #include "core.h"

// main function -
// where the execution of program begins
int main()
{
  // prints hello world
  printf("game app \n");
  message();
  
  core_create_window();
  core_loop();
  core_close_window();

  return 0;
}