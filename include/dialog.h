#ifndef DIALOG_H
#define DIALOG_H

/* Clears the screen and prints the message inside a box */
void dialog(char *title, char *message);

#define PANIC(message) dialog("Error", message)

#endif
