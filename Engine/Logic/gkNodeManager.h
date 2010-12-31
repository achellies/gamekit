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
#ifndef _gkNodeManager_h_
#define _gkNodeManager_h_

#include "gkLogicCommon.h"
#include "gkMathUtils.h"
#include "utSingleton.h"

class gkGameObject;

class gkNodeManager : public utSingleton<gkNodeManager>
{
public:
	typedef utHashTable<utIntHashKey, gkLogicTree*> NodeTree;
	typedef utHashTableIterator<NodeTree>           NodeTreeIterator;
	typedef utList<gkLogicTree*>                    TreeList;
public:
	gkNodeManager();
	~gkNodeManager();

	gkLogicTree* create();
	gkLogicTree* create(const gkString& name);

	gkLogicTree* get(int id);
	gkLogicTree* get(const gkString& name);

	NodeTreeIterator getIterator();

	void destroy(gkLogicTree* tree);
	void destroy(int handle);

	static gkNodeManager& getSingleton();
	static gkNodeManager* getSingletonPtr();

	void update(gkScalar tick);
	void clear();

private:
	TreeList    m_locals;
	int         m_uniqueHandle;
	NodeTree    m_trees;
};


#endif//_gkNodeManager_h_
