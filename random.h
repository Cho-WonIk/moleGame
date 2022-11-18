#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

srand(time(NULL));
extern int randInt = (rand() % 9) + 1;  // 10 미만의 랜덤 함수

