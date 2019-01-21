#pragma once 
#include "Componente.h"
#include "fmod.hpp"
#include "Estado.h"

class OclusionComponent: public Componente { 
public: 
	OclusionComponent(Entidad* pEntidad, FMOD::System* sys, Ogre::Vector3 pos = Ogre::Vector3::UNIT_X);
	~OclusionComponent(); 

private:
	FMOD::System* system;
	FMOD::Geometry* geometry;
	int polygonIndex;
}; 
