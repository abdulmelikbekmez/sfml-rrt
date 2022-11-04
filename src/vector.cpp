
#include <math.h>
#include <vector.hpp>

float Vector::length() const
{
    return std::sqrt(x * x + y * y);
}

Vector Vector::normalize() const
{
    return Vector(*this / length());
}
