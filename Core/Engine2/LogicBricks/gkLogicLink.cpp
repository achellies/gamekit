/*
-------------------------------------------------------------------------------
    This file is part of OgreKit.
    http://gamekit.googlecode.com/

    Copyright (c) 2006-2010 Charlie C.

    Contributor(s): none yet.
-------------------------------------------------------------------------------
  This software is provided 'as-is', without any express or implied
  warranty. In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
-------------------------------------------------------------------------------
*/
#include "gkLogicLink.h"
#include "gkLogicSensor.h"
#include "gkLogicController.h"
#include "gkLogicActuator.h"


gkLogicLink::gkLogicLink() : m_state(0)
{
}


gkLogicLink::~gkLogicLink()
{
    if (!m_sensors.empty()) {
        utListIterator<BrickList> it(m_sensors);
        while (it.hasMoreElements())
            delete it.getNext();
    }
    if (!m_controllers.empty()) {
        utListIterator<BrickList> it(m_controllers);
        while (it.hasMoreElements())
            delete it.getNext();
    }
    if (!m_actuators.empty()) {
        utListIterator<BrickList> it(m_actuators);
        while (it.hasMoreElements())
            delete it.getNext();
    }
}

void gkLogicLink::push(gkLogicSensor *v)
{
    GK_ASSERT(v); 
    m_sensors.push_back(v);
}

void gkLogicLink::push(gkLogicController *v)
{
    GK_ASSERT(v); 
    m_controllers.push_back(v);
}

void gkLogicLink::push(gkLogicActuator *v)
{
    GK_ASSERT(v); 
    m_actuators.push_back(v);
}


gkLogicActuator* gkLogicLink::findActuator(const gkString& name)
{
    if (!m_actuators.empty()) {

        utListIterator<BrickList> it(m_actuators);
        while (it.hasMoreElements()) {
            gkLogicBrick *ac = it.getNext();
            if (ac->getName() == name) return static_cast<gkLogicActuator*>(ac);
        }
    }
    return 0;
}

gkLogicController* gkLogicLink::findController(const gkString& name)
{
    if (!m_controllers.empty()) {

        utListIterator<BrickList> it(m_controllers);
        while (it.hasMoreElements()) {
            gkLogicBrick *co = it.getNext();
            if (co->getName() == name) return static_cast<gkLogicController*>(co);
        }
    }
    return 0;
}
