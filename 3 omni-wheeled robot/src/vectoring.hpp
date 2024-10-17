#pragma once

#include <Arduino.h>
#include <math.h>

long vectoringOneWheel(long x, long y, long n);

long vectoringOneWheel(long x, long y, long n) {
    long result = 0;
    long center = 57800;
    result = sin(sinh((170*sin(n))/sqrt(center - center * cos(n))))*sqrt(center - center * cos(n));
    return result;
}