#pragma once
#ifdef __cplusplus
#define EXTERNC extern "C"
#else
#define EXTERNC
#endif


EXTERNC void Print(const char* text);
EXTERNC char* ToString(int number, char* buffer, int bufferSize);