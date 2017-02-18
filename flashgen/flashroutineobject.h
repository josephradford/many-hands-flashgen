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
class FlashRoutines
{
public:
    FlashRoutines();
    ~FlashRoutines();

    QList<FlashObject> flashes;

    void startKeyPress(int key);
    void stopKeyPress();

    void clear();
    void stopRecording();
private:
    bool m_keyPressed;
    bool m_ignoreNextRelease;
    QElapsedTimer *m_timer;
};

#endif // FLASHROUTINEOBJECT_H
