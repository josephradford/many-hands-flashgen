#ifndef FLASHROUTINEOBJECT_H
#define FLASHROUTINEOBJECT_H

#include <QList>

class FlashObject
{
public:
    FlashObject();

    int channel;
    int hold;
    int pause;
};

// stores the flash routine information
class FlashRoutineObject
{
public:
    FlashRoutineObject();

    QList<FlashObject> flashes;
};

#endif // FLASHROUTINEOBJECT_H
