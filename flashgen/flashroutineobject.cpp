#include "flashroutineobject.h"

#include <QElapsedTimer>

FlashRoutineObject::FlashRoutineObject()
{
    m_keyPressed = false;
    m_timer = new QElapsedTimer();
}

FlashRoutineObject::~FlashRoutineObject()
{
    delete m_timer;
}

void FlashRoutineObject::startKeyPress(int key)
{
    if (m_keyPressed) {
        // stop the current recording
        if (flashes.count()) {
            flashes.last().hold = m_timer->elapsed();
            flashes.last().pause = 0;   // no pause, this one was still going
        }
    }
    else {
        // save the pause time for the last key
        if (flashes.count()) {
            flashes.last().pause = m_timer->elapsed();
        }
    }

    // start the new key
    FlashObject flash;
    if (key == Qt::Key_A) {
        // red on the EL wire
        flash.channel = 1;
    }
    if (key == Qt::Key_S) {
        // orange on the EL wire
        flash.channel = 2;
    }
    if (key == Qt::Key_D) {
        // yellow on the EL wire
        flash.channel = 2;
    }

    // add it to the end of the list
    flashes.append(flash);

    // restart the timer
    m_timer->restart();

    // set recording flag
    m_keyPressed = true;
}

void FlashRoutineObject::stopKeyPress()
{
    // save the hold time of the current key
    if (m_keyPressed) {
        if (flashes.count()) {
            flashes.last().hold = m_timer->elapsed();
        }
    }

    // key is no longer pressed, unset flag
    m_keyPressed = false;

    // restart the timer
    m_timer->restart();
}

void FlashRoutineObject::clear()
{
    flashes.clear();
    m_keyPressed = false;
}
