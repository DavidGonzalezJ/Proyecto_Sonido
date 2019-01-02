#include "OclusionComponent.h"  
#include "FComponent.h"
 
OclusionComponent::OclusionComponent(Entidad* pEntidad, FMOD::System* sys):Componente(pEntidad) {
	system = sys;
	system->createGeometry(6, 8, &geometry);

	Ogre::Vector3 posN = pEntidad->getPEstado()->getScnManager()->getSceneNode("GNode" + pEntidad->getNombreNodo())->getPosition();
	Ogre::AxisAlignedBox bbox = pEntidad->getPEstado()->getScnManager()->getSceneNode(pEntidad->getNombreNodo())->_getWorldAABB();
	Ogre::Vector3  v = bbox.getSize();


	FMOD_VECTOR vertices[4];
	vertices[0] = { posN.x - v.x / 2,posN.y + v.y / 2,posN.z };
	vertices[1] = { posN.x - v.x / 2,posN.y - v.y / 2,posN.z };
	vertices[2] = { posN.x + v.x / 2,posN.y - v.y / 2,posN.z };
	vertices[3] = { posN.x + v.x / 2,posN.y + v.y / 2,posN.z };
	geometry->addPolygon(0.7, 0.5, true, 4, vertices, &polygonIndex);
	
	FMOD_VECTOR pos = { posN.x,posN.y,posN.z };
	geometry->setPosition(&pos);
} 
OclusionComponent::~OclusionComponent() { 
} 
