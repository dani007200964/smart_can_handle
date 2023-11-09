#include "gestureParser.hpp"
int RandomForest::predictWiggle(float *x) {
    uint8_t votes[2] = { 0 };
    // tree #1
    if (x[7] <= -180.5) {
        if (x[8] <= -238.5) {
            votes[0] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    else {
        if (x[11] <= 153.5) {
            votes[0] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    // tree #2
    if (x[9] <= -178.0) {
        if (x[10] <= 84.5) {
            votes[1] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    else {
        if (x[10] <= -180.5) {
            votes[1] += 1;
        }

        else {
            votes[0] += 1;
        }
    }

    // tree #3
    if (x[13] <= -181.0) {
        if (x[14] <= 214.5) {
            votes[1] += 1;
        }

        else {
            votes[0] += 1;
        }
    }

    else {
        if (x[7] <= -187.0) {
            votes[1] += 1;
        }

        else {
            votes[0] += 1;
        }
    }

    // tree #4
    if (x[11] <= 147.0) {
        if (x[10] <= -190.5) {
            votes[1] += 1;
        }

        else {
            votes[0] += 1;
        }
    }

    else {
        if (x[0] <= 2.0) {
            votes[1] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    // tree #5
    if (x[0] <= 143.5) {
        if (x[12] <= -181.0) {
            votes[1] += 1;
        }

        else {
            votes[0] += 1;
        }
    }

    else {
        if (x[11] <= -28.5) {
            votes[1] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    // tree #6
    if (x[13] <= -182.0) {
        if (x[7] <= 41.5) {
            votes[1] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    else {
        if (x[12] <= -178.5) {
            votes[1] += 1;
        }

        else {
            votes[0] += 1;
        }
    }

    // tree #7
    if (x[7] <= -178.5) {
        if (x[13] <= 2.0) {
            votes[1] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    else {
        if (x[5] <= -166.5) {
            votes[1] += 1;
        }

        else {
            votes[0] += 1;
        }
    }

    // tree #8
    if (x[6] <= 150.5) {
        if (x[0] <= -195.0) {
            votes[1] += 1;
        }

        else {
            votes[0] += 1;
        }
    }

    else {
        if (x[13] <= -20.0) {
            votes[1] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    // tree #9
    if (x[8] <= 109.5) {
        if (x[8] <= -176.5) {
            votes[1] += 1;
        }

        else {
            votes[0] += 1;
        }
    }

    else {
        if (x[6] <= -46.5) {
            votes[1] += 1;
        }

        else {
            votes[0] += 1;
        }
    }

    // tree #10
    if (x[9] <= -181.5) {
        if (x[10] <= 84.5) {
            votes[1] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    else {
        if (x[5] <= -180.5) {
            votes[1] += 1;
        }

        else {
            votes[0] += 1;
        }
    }

    // tree #11
    if (x[8] <= 162.5) {
        if (x[7] <= 136.0) {
            votes[0] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    else {
        if (x[3] <= 135.0) {
            votes[1] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    // tree #12
    if (x[4] <= -180.5) {
        if (x[2] <= 51.5) {
            votes[1] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    else {
        if (x[4] <= 116.0) {
            votes[0] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    // tree #13
    if (x[14] <= 147.0) {
        if (x[12] <= 175.0) {
            votes[0] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    else {
        if (x[6] <= 143.5) {
            votes[1] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    // tree #14
    if (x[9] <= 179.5) {
        if (x[7] <= 135.0) {
            votes[0] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    else {
        if (x[12] <= -39.5) {
            votes[1] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    // tree #15
    if (x[2] <= 184.5) {
        if (x[10] <= -179.0) {
            votes[1] += 1;
        }

        else {
            votes[0] += 1;
        }
    }

    else {
        if (x[4] <= -177.5) {
            votes[1] += 1;
        }

        else {
            votes[1] += 1;
        }
    }

    // return argmax of votes
    uint8_t classIdx = 0;
    float maxVotes = votes[0];

    for (uint8_t i = 1; i < 2; i++) {
        if (votes[i] > maxVotes) {
            classIdx = i;
            maxVotes = votes[i];
        }
    }

    return classIdx;
}
