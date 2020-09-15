#include "controlledspace.h"

ControlledSpace::ControlledSpace()
{

}

bool ControlledSpace::verifyX(float x)
{
    bool r =  nearLeft.x() < x && x < nearRight.x() && farLeft.x() < x && x < farRight.x();
    return r;
}

bool ControlledSpace::verifyZ(float z)
{
    bool r = nearLeft.z() < z && z > nearRight.z() && farLeft.z() > z && z < farRight.z();
    return r;
}
