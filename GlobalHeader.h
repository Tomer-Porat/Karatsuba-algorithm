#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
using namespace std;
#include "Stack.h"
#include "Karatsuba.h"
#include "schoolMultiplication.h"

static constexpr int MAX_SIZE = 1000;
static constexpr int START = 1;
static constexpr int AFTER_FIRST = 2;
static constexpr int AFTER_SECOND = 3;
static constexpr int AFTER_THIRD = 4;
