#include "OclusionComponent.h"  
#include "FComponent.h"
 
OclusionComponent::OclusionComponent(Entidad* pEntidad, FMOD::System* sys):Componente(pEntidad) {
	system = sys;
	system->createGeometry(6, 8, &geometry);

	Ogre::Vector3 posN = pEntidad->getPEstado()->getScnManager()->getSceneNode("GNode" + pEntidad->getNombreNodo())->getPosition();
	Ogre::AxisAlignedBox bbox = pEntidad->getPEstado()->getScnManager()->getSceneNode(pEntidad->getNombreNodo())->_getWorldAABB();
	Ogre::Vector3  v = bbox.getSize();


	FMOD_VECTOR vertices[4];
	vertices[0] = { posN.x - 80*v.x,posN.y + 80*v.y,posN.z-2 };
	vertices[1] = { posN.x - 80*v.x,posN.y - 80*v.y,posN.z-2 };
	vertices[2] = { posN.x + 80*v.x,posN.y - 80*v.y,posN.z-2 };
	vertices[3] = { posN.x + 80*v.x,posN.y + 80*v.y,posN.z-2 };
	geometry->addPolygon(1.0, 1.0, true, 4, vertices, &polygonIndex);
	FMOD_VECTOR vertices2[4];
	vertices2[0] = { posN.x - 80 * v.x,posN.y + 80 * v.y,posN.z + 2 };
	vertices2[1] = { posN.x - 80 * v.x,posN.y - 80 * v.y,posN.z + 2 };
	vertices2[2] = { posN.x + 80 * v.x,posN.y - 80 * v.y,posN.z + 2 };
	vertices2[3] = { posN.x + 80 * v.x,posN.y + 80 * v.y,posN.z + 2 };
	int l;
	geometry->addPolygon(1.0, 1.0, true, 4, vertices, &l);
	
	FMOD_VECTOR pos = { posN.x,posN.y,posN.z };
	geometry->setPosition(&pos);
	system->update();
} 
OclusionComponent::~OclusionComponent() { 
} 
