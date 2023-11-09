#ifndef __GESTURE_PARSER_HPP__
#define __GESTURE_PARSER_HPP__

#include <stdint.h>

class RandomForest {
public:
    static int predictWiggle( float *x );
    static int predictToast( float *x );
};

#endif