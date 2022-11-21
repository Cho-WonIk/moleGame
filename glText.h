#pragma once
#include <windows.h> // Header File For Windows
#include <stdio.h>   // Header File For Standard Input/Output
#include <stdarg.h>  // Header File For Variable Argument Routines
#include <gl\gl.h>   // Header File For The OpenGL32 Library
#include <gl\glu.h>  // Header File For The GLu32 Library

enum FONT
{
    ARIAL = 1,      // Arial = 1
    COURIERNEW,     // Courier New = 2
    CALIBRI,        // Calibri = 3
    TIMESNEWROMAN,  // Times New Roman = 4
    BOOKANTIQUA,    // Book Antiqua = 5
    TREBUCHETMS     // Trebuchet MS = 6
};

HDC hDC;              // Private GDI Device Context
HGLRC hRC;            // Permanent Rendering Context
HWND hWnd;            // Holds Our Window Handle
HINSTANCE hInstance;  // Holds The Instance Of The Application

GLuint  base;  // Base Display List For The Font Set

GLvoid BuildFontWithEnum(FONT fontEnum, int fontSize);
GLvoid BuildFont(const char* fontName, int fontSize);
GLvoid KillFont(GLvoid);
GLvoid glPrint(const char* fmt, ...);
int InitFont(GLvoid);