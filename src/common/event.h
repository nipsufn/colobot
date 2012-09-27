// * This file is part of the COLOBOT source code
// * Copyright (C) 2001-2008, Daniel ROUX & EPSITEC SA, www.epsitec.ch
// *
// * This program is free software: you can redistribute it and/or modify
// * it under the terms of the GNU General Public License as published by
// * the Free Software Foundation, either version 3 of the License, or
// * (at your option) any later version.
// *
// * This program is distributed in the hope that it will be useful,
// * but WITHOUT ANY WARRANTY; without even the implied warranty of
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// * GNU General Public License for more details.
// *
// * You should have received a copy of the GNU General Public License
// * along with this program. If not, see  http://www.gnu.org/licenses/.

/**
 * \file common/event.h
 * \brief Event types, structs and event queue
 */

#pragma once


#include "common/key.h"
#include "common/event_ids.h"
#include "math/point.h"
#include "math/vector.h"

class CInstanceManager;


/**
 * \struct KeyEventData
 * \brief Additional data for keyboard event
 */
struct KeyEventData
{
    //! If true, the key is a virtual code generated by certain key modifiers or joystick buttons
    bool virt;
    //! Key symbol: KEY(...) macro value or virtual key VIRTUAL_... (from common/key.h)
    unsigned int key;
    //! Unicode character
    //! NOTE: applicable only to EVENT_KEY_DOWN events!
    unsigned int unicode;
};

/**
 * \enum MouseButton
 * \brief Mouse button
 *
 * Values are a bitmask to have a state bitmask
 */
enum MouseButton
{
    MOUSE_BUTTON_LEFT   = (1<<1),
    MOUSE_BUTTON_MIDDLE = (1<<2),
    MOUSE_BUTTON_RIGHT  = (1<<3),
    //! There may be additional mouse buttons >= this value
    MOUSE_BUTTON_OTHER  = (1<<4)
};

/**
 * \struct MouseButtonEventData
 * \brief Additional data mouse button event
 */
struct MouseButtonEventData
{
    //! The mouse button
    MouseButton button;
};

/**
 * \enum WheelDirection
 * \brief Direction of mouse wheel movement
 */
enum WheelDirection
{
    WHEEL_UP,
    WHEEL_DOWN
};

/**
 * \struct MouseWheelEventData
 * \brief Additional data for mouse wheel event.
 */
struct MouseWheelEventData
{
    //! Wheel direction
    WheelDirection dir;
};

/**
 * \struct JoyAxisEventData
 * \brief Additional data for joystick axis event
 */
struct JoyAxisEventData
{
    //! The joystick axis index
    unsigned char axis;
    //! The axis value (range: -32768 to 32767)
    int value;
};

/**
 * \struct JoyButtonEventData
 * \brief Additional data for joystick button event
 */
struct JoyButtonEventData
{
    //! The joystick button index
    unsigned char button;
};

/**
 * \enum ActiveEventFlags
 * \brief Type of focus gained/lost
 */
enum ActiveEventFlags
{
    //! Application window focus
    ACTIVE_APP   = 0x01,
    //! Input focus
    ACTIVE_INPUT = 0x02,
    //! Mouse focus
    ACTIVE_MOUSE = 0x04

};

/**
 * \struct ActiveEventData
 * \brief Additional data for active event
 */
struct ActiveEventData
{
    //! Flags (bitmask of enum values ActiveEventFlags)
    unsigned char flags;
    //! True if the focus was gained; false otherwise
    bool gain;
};


/**
 * \struct Event
 * \brief Event sent by system, interface or game
 *
 * Event is described by its type (EventType) and the union
 * \a data contains additional data about the event.
 * Different members of the union are filled with different event types.
 * With some events, nothing is filled (it's zeroed out).
 * The union contains roughly the same information as SDL_Event struct
 * but packaged to independent structs and fields.
 **/
struct Event
{
    //! Type of event
    EventType type;

    //! If true, the event was produced by system in CApplication; else, it has come from game engine
    bool systemEvent;

    //! Relative time since last EVENT_FRAME
    //! Scope: only EVENT_FRAME events
    // TODO: gradually replace the usage of this with new CApplication's time functions
    float        rTime;

    //! Motion vector set by keyboard or joystick (managed by CRobotMain)
    //! Scope: all system events
    Math::Vector motionInput;

    //! Current state of keyboard modifier keys: bitmask made of KEY_MOD(...) macro values (from common/key.h)
    //! Scope: all system events
    unsigned int kmodState;

    //! Current state of tracked keys: bitmask of TrackedKey enum values
    //! Scope: all system events
    unsigned int trackedKeysState;

    //! Current position of mouse cursor in interface coords
    //! Scope: all system events
    Math::Point  mousePos;

    //! Current state of mouse buttons: bitmask of MouseButton enum values
    //! Scope: all system events
    unsigned int mouseButtonsState;

    //! Custom parameter that may be set for some events
    //! Scope: some interface events
    long         customParam;

    //! Union with additional data, applicable only to some events
    union
    {
        //! Additional data for EVENT_KEY_DOWN and EVENT_KEY_UP
        KeyEventData key;
        //! Additional data for EVENT_MOUSE_BUTTON_DOWN and EVENT_MOUSE_BUTTON_UP
        MouseButtonEventData mouseButton;
        //! Additional data for EVENT_MOUSE_WHEEL
        MouseWheelEventData mouseWheel;
        //! Additional data for EVENT_JOY
        JoyAxisEventData joyAxis;
        //! Additional data for EVENT_JOY_AXIS
        JoyButtonEventData joyButton;
        //! Additional data for EVENT_ACTIVE
        ActiveEventData active;
    };

    Event(EventType type = EVENT_NULL)
    {
        this->type = type;

        systemEvent = false;
        rTime = 0.0f;
        mouseButtonsState = 0;
        trackedKeysState = 0;
        customParam = 0;
    }
};


//! Returns an unique event type (above the standard IDs)
EventType GetUniqueEventType();


/**
 * \class CEventQueue
 * \brief Global event queue
 *
 * Provides an interface to a global FIFO queue with events (both system- and user-generated).
 * The queue has a fixed maximum size but it should not be a problem.
 */
class CEventQueue
{
public:
    //! Constant maximum size of queue
    static const int MAX_EVENT_QUEUE = 100;

public:
    //! Object's constructor
    CEventQueue(CInstanceManager* iMan);
    //! Object's destructor
    ~CEventQueue();

    //! Empties the FIFO of events
    void    Flush();
    //! Adds an event to the queue
    bool    AddEvent(const Event &event);
    //! Removes and returns an event from queue front
    bool    GetEvent(Event &event);

protected:
    CInstanceManager* m_iMan;
    Event        m_fifo[MAX_EVENT_QUEUE];
    int          m_head;
    int          m_tail;
    int          m_total;
};
