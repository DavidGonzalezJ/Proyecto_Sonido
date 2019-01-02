#pragma once 
#include "Componente.h"
#include "fmod.hpp"
#include "Estado.h"

class SoundListener: public Componente { 
public: 
	SoundListener(Entidad* pEntidad, FMOD::System* sys);
	~SoundListener(); 
	virtual void Update(float deltaTime, Mensaje const & msj);
private:
	FMOD::System* system;
}; 
