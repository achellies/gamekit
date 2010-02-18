/*
-------------------------------------------------------------------------------
	This file is part of OgreKit.
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
#include "OgreManualBone.h"
#include "OgreBone.h"


using namespace Ogre;



static TransformState ManualBone_GetConstMatrix(Ogre::Bone *bone)
{
	OGRE_ASSERT(bone);
	TransformState r;
	r.loc = bone->getInitialPosition();
	r.rot = bone->getInitialOrientation();
	r.scl = bone->getInitialScale();
	return r;
}


ManualBone::ManualBone(Ogre::Bone *bone) :
	m_bone(bone), m_bind(ManualBone_GetConstMatrix(bone)), m_parent(0)
{
	m_pose.setIdentity();
}


ManualBone::~ManualBone()
{
}
