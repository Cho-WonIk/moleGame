#pragma once
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

srand(time(NULL));
extern int randInt = (rand() % 9) + 1;  // 1~9 사이의 랜덤 난수 생성
