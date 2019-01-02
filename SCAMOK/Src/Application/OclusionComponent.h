#pragma once 
#include "Componente.h"
#include "fmod.hpp"
#include "Estado.h"

class OclusionComponent: public Componente { 
public: 
	OclusionComponent(Entidad* pEntidad, FMOD::System* sys);
	~OclusionComponent(); 

private:
	FMOD::System* system;
	FMOD::Geometry* geometry;
	int polygonIndex;
}; 
