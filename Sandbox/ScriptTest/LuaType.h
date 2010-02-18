/*
-------------------------------------------------------------------------------
	Lua 5.1 script tests.
	http://gamekit.googlecode.com/

	Copyright (c) 2009 Charlie C.
-------------------------------------------------------------------------------
 This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
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
#ifndef _LuaType_h_
#define _LuaType_h_

#include "LuaCommon.h"


typedef int (*LuaMethod)(LuaState *L);


/// Script method definition
struct LuaMethodDef
{
	const char	*name;
	LuaMethod	meth;
};

/// Script type definition (eg; table, class)
struct LuaTypeDef
{
	const char		*name;
	const char		*docs;
	LuaMethod		ctor;
	LuaMethod		dtor;
	LuaMethod		get;
	LuaMethod		set;
	LuaMethodDef	*methods;
};


#endif//_gkType_h_
