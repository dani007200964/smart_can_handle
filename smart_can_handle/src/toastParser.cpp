#include "gestureParser.hpp"
int RandomForest::predictToast(float *x) {
    uint8_t votes[2] = { 0 };
    // tree #1
    if (x[8] <= 1.2365000247955322) {
        if (x[4] <= 1.3229999542236328) {
            if (x[3] <= 1.0074999928474426) {
                votes[0] += 1;
            }

            else {
                votes[0] += 1;
            }
        }

        else {
            if (x[3] <= 1.337499976158142) {
                votes[1] += 1;
            }

            else {
                votes[0] += 1;
            }
        }
    }

    else {
        if (x[4] <= 1.3959999680519104) {
            if (x[3] <= 1.0980000495910645) {
                votes[1] += 1;
            }

            else {
                votes[0] += 1;
            }
        }

        else {
            votes[0] += 1;
        }
    }

    // tree #2
    if (x[6] <= 1.2120000123977661) {
        if (x[11] <= 1.2544999718666077) {
            if (x[9] <= 1.403499960899353) {
                votes[0] += 1;
            }

            else {
                votes[1] += 1;
            }
        }

        else {
            if (x[9] <= 1.2520000338554382) {
                votes[0] += 1;
            }

            else {
                votes[1] += 1;
            }
        }
    }

    else {
        if (x[11] <= 1.1759999990463257) {
            if (x[7] <= 1.2304999828338623) {
                votes[1] += 1;
            }

            else {
                votes[1] += 1;
            }
        }

        else {
            votes[0] += 1;
        }
    }

    // tree #3
    if (x[6] <= 1.2120000123977661) {
        if (x[11] <= 1.1865000128746033) {
            if (x[4] <= 1.3899999856948853) {
                votes[0] += 1;
            }

            else {
                votes[0] += 1;
            }
        }

        else {
            if (x[9] <= 1.4345000386238098) {
                votes[0] += 1;
            }

            else {
                votes[1] += 1;
            }
        }
    }

    else {
        if (x[9] <= 1.1924999952316284) {
            if (x[4] <= 1.6735000014305115) {
                votes[1] += 1;
            }

            else {
                votes[0] += 1;
            }
        }

        else {
            if (x[3] <= 1.059499979019165) {
                votes[1] += 1;
            }

            else {
                votes[0] += 1;
            }
        }
    }

    // tree #4
    if (x[6] <= 1.190500020980835) {
        if (x[9] <= 1.2400000095367432) {
            if (x[2] <= 1.3740000128746033) {
                votes[0] += 1;
            }

            else {
                votes[0] += 1;
            }
        }

        else {
            if (x[3] <= 1.0584999918937683) {
                votes[1] += 1;
            }

            else {
                votes[0] += 1;
            }
        }
    }

    else {
        if (x[1] <= 1.1704999804496765) {
            if (x[1] <= 1.0475000143051147) {
                votes[1] += 1;
            }

            else {
                votes[1] += 1;
            }
        }

        else {
            votes[0] += 1;
        }
    }

    // tree #5
    if (x[7] <= 1.1899999976158142) {
        if (x[10] <= 1.4549999833106995) {
            if (x[11] <= 1.487500011920929) {
                votes[0] += 1;
            }

            else {
                votes[0] += 1;
            }
        }

        else {
            if (x[5] <= 1.0524999499320984) {
                votes[1] += 1;
            }

            else {
                votes[0] += 1;
            }
        }
    }

    else {
        if (x[0] <= 1.0574999451637268) {
            if (x[7] <= 1.2304999828338623) {
                votes[0] += 1;
            }

            else {
                votes[1] += 1;
            }
        }

        else {
            if (x[3] <= 1.1054999828338623) {
                votes[1] += 1;
            }

            else {
                votes[0] += 1;
            }
        }
    }

    // tree #6
    if (x[10] <= 1.209000051021576) {
        if (x[8] <= 1.2364999651908875) {
            if (x[5] <= 1.4240000247955322) {
                votes[0] += 1;
            }

            else {
                votes[1] += 1;
            }
        }

        else {
            if (x[11] <= 0.9805000126361847) {
                votes[1] += 1;
            }

            else {
                votes[0] += 1;
            }
        }
    }

    else {
        if (x[2] <= 1.0554999709129333) {
            if (x[11] <= 1.3865000009536743) {
                votes[1] += 1;
            }

            else {
                votes[1] += 1;
            }
        }

        else {
            votes[0] += 1;
        }
    }

    // tree #7
    if (x[6] <= 1.1945000290870667) {
        if (x[9] <= 1.2400000095367432) {
            if (x[11] <= 1.4620000123977661) {
                votes[0] += 1;
            }

            else {
                votes[0] += 1;
            }
        }

        else {
            if (x[1] <= 1.0554999709129333) {
                votes[1] += 1;
            }

            else {
                votes[0] += 1;
            }
        }
    }

    else {
        if (x[2] <= 1.1050000190734863) {
            if (x[11] <= 1.4039999842643738) {
                votes[1] += 1;
            }

            else {
                votes[0] += 1;
            }
        }

        else {
            if (x[7] <= 1.2664999961853027) {
                votes[0] += 1;
            }

            else {
                votes[0] += 1;
            }
        }
    }

    // tree #8
    if (x[5] <= 1.2179999947547913) {
        if (x[6] <= 1.225000023841858) {
            if (x[1] <= 1.0084999799728394) {
                votes[0] += 1;
            }

            else {
                votes[0] += 1;
            }
        }

        else {
            if (x[3] <= 1.1014999747276306) {
                votes[1] += 1;
            }

            else {
                votes[0] += 1;
            }
        }
    }

    else {
        if (x[10] <= 1.1389999985694885) {
            if (x[6] <= 1.371500015258789) {
                votes[0] += 1;
            }

            else {
                votes[1] += 1;
            }
        }

        else {
            if (x[11] <= 1.0520000159740448) {
                votes[1] += 1;
            }

            else {
                votes[0] += 1;
            }
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