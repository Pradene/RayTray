#include "../../includes/rt.h"

// float clamp(float v, float min, float max)
// {
//     if (v >= min && v <= max)
//         return (v);
//     else if (v < min)
//         return (min);
//     return (max);
// }

// This fucntion clamp the number between 2 values
float   clamp(float value, float min, float max)
{
    return (fmaxf(min, fminf(value, max)));
}