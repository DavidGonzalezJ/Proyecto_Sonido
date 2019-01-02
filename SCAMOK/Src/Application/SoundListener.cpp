#include "SoundListener.h"
#include <string>
 
SoundListener::SoundListener(Entidad * pEntidad,FMOD::System* sys) : Componente(pEntidad)
{
	system = sys;
}
SoundListener::~SoundListener() {
}

//El mensaje llega del componente físico
//Recibe un mensaje de que el personaje se ha movido y el listener entonces también tiene que hacerlo
void SoundListener::Update(float deltaTime, Mensaje const & msj)
{
	Mensaje msg = msj;
	if (msg.getTipo() == Tipo::Audio) {
		if (msg.getSubTipo() == SubTipo::ReposicionListener) {
			int pos = msg.getMsg().find("/");
			std::string xS = msg.getMsg().substr(0, pos);
			std::string subcad = msg.getMsg().substr(pos + 1);
			pos = subcad.find("/");
			std::string yS = subcad.substr(0, pos);
			subcad = subcad.substr(pos + 1);
			pos = subcad.find("/");
			std::string zS = subcad.substr(0, pos);

			//forward
			subcad = subcad.substr(pos + 1);
			pos = subcad.find("/");
			std::string fxS = subcad.substr(0, pos); subcad = subcad.substr(pos + 1);
			pos = subcad.find("/");
			std::string fyS = subcad.substr(0, pos); subcad = subcad.substr(pos + 1);
			std::string fzS = subcad.substr(0);

			

			float x = std::stof(xS);
			float y = std::stof(yS);
			float z = std::stof(zS);
			FMOD_VECTOR poss = { x,y,z }, up = { 0,1,0 }, vel = { 0,0,0 };
			if (x == y && y == z  && z == 0) {
				system->get3DListenerAttributes(0, &poss, NULL, NULL, NULL);
			}
			float fx = std::stof(fxS);
			float fy = std::stof(fyS);
			float fz = std::stof(fzS);
			FMOD_VECTOR forward = { fx,fy,fz };
			if (fx == fy && fy == fz && fz == 0) {
				system->get3DListenerAttributes(0, NULL, NULL, &forward, NULL);
			}

			system->set3DListenerAttributes(0, &poss, &vel, &forward, &up);
			system->update();
		}
	}
}
