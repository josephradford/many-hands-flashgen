#ifndef FLASHROUTINEOBJECT_H
#define FLASHROUTINEOBJECT_H

#include <QList>

class QElapsedTimer;

struct FlashObject
{
    int channel;
    int hold;
    int pause;
};

// stores the flash routine information
class FlashRoutineObject
{
public:
    FlashRoutineObject();
    ~FlashRoutineObject();

    QList<FlashObject> flashes;

    void startKeyPress(int key);
    void stopKeyPress();

    void clear();
private:
    bool m_keyPressed;
    QElapsedTimer *m_timer;
};

#endif // FLASHROUTINEOBJECT_H
