#include <termios.h> 
#include <unistd.h> 
#include <stdio.h> 

#ifdef _WIN32
    #include <conio.h>
#endif
/* reads from keypress, doesn't echo */ 
namespace std {
    int getch(void) 
    {
        #ifdef _WIN32
            return getch();
        #endif
        #ifdef __linux__
            struct termios oldattr, newattr; 
            int ch; 
            tcgetattr(STDIN_FILENO, &oldattr); 
            newattr = oldattr; 
            newattr.c_lflag &= ~(ICANON | ECHO); 
            tcsetattr(STDIN_FILENO, TCSANOW, &newattr); 
            ch = getchar(); 
            tcsetattr(STDIN_FILENO, TCSANOW, &oldattr); 
            return ch;
        #endif
    }
}
