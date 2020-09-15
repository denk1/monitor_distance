#ifndef CONTROLLEDSPACE_H
#define CONTROLLEDSPACE_H

#include <QVector3D>
#include "datasources.h"

class ControlledSpace
{
public:
    ControlledSpace();
    bool verifyX(float x);
    bool verifyZ(float z);

private:
    DataSources _dataSources;
    QVector3D nearLeft{-2.5, .0, .0};
    QVector3D nearRight{2.5, .0, .0};
    QVector3D farLeft{-2.5, .0, 5.0};
    QVector3D farRight{2.5, .0, 5.0};

};

#endif // CONTROLLEDSPACE_H
