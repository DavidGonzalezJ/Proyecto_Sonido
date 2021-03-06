#pragma once 
#include "Componente.h"
#include <fmod.hpp>
#include <fmod_studio.hpp>
#include "Estado.h"
#include <vector>
class SoundManager : public Componente { 
public: 
	SoundManager(Entidad* pEnt, FMOD::Studio::System* sys);
	~SoundManager(); 

	//Audio-----------------------------------------

	void reproduceFx(std::string fx, float x, float y, float z, float wet);
	void reproduceInstance(std::string eventInstance,std::string paraName, float paramValue);
	void reproduceAmbM(std::string amb, float wet, bool fade);
	void paraAmb(int ch, bool fade);
	// Lanzamos el evento 
	void createInstanceEvent(std::string evento, bool play = false);
	virtual void Update(float deltaTime, Mensaje const & msj);

private:
	// Fmod settings
	FMOD::ChannelGroup* reverbGroup;
	FMOD::ChannelGroup* mainGroup;
	FMOD::DSP* reverbUnit;
	FMOD::DSP* channelHead;
	
	FMOD::System* system;
	FMOD::Studio::System* studioSystem;

	std::vector<FMOD::DSPConnection*> reverbConnectionfx;
	std::vector<FMOD::Channel*> cFx;
	std::vector<FMOD::Channel*> cMA;
	std::vector<FMOD::DSPConnection*> reverbConnectionAmbM;
	std::map<std::string, FMOD::Sound*> vfx;
	std::map<std::string, FMOD::Sound*> vmusic;

	std::map<std::string, FMOD::Studio::EventInstance*> eInstance;
	//FMOD::Studio::EventInstance* pasos;
	//Cambio de reverb
	void reverbSwap();
	FMOD::Reverb3D* actualRev;
	int rev;

	void cargaAudio(std::string irPath);
	void cargarAssetsAudio();
}; 
