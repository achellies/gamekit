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
#ifndef _gkMathNode_h_
#define _gkMathNode_h_

#include "gkLogicNode.h"

class gkMathNode : public gkLogicNode
{
public:
    gkMathNode(gkLogicTree *parent, size_t id);
    virtual ~gkMathNode() {}

    void update(gkScalar tick);

    GK_INLINE void setFunction(int func) {m_function = func;}

    static gkScalar doOp(gkScalar a, gkScalar b);

    // socket access
    GK_INLINE gkLogicSocket* getA(void)         {return &m_sockets[0];}
    GK_INLINE gkLogicSocket* getB(void)         {return &m_sockets[1];}

    // outputs
    GK_INLINE gkLogicSocket* getResult(void)    {return &m_sockets[2];}


private:
    gkLogicSocket   m_sockets[3];
    int             m_function;
};


#endif//_gkMathNode_h_
