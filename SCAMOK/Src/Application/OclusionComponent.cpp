#include "OclusionComponent.h"  
#include "FComponent.h"
#include <iostream>
OclusionComponent::OclusionComponent(Entidad* pEntidad, FMOD::System* sys, Ogre::Vector3 pos):Componente(pEntidad) {
	system = sys;
	std::cout<<system->createGeometry(1, 4, &geometry) << std::endl;
	Ogre::Vector3 posN = pos;// pEntidad->getPEstado()->getScnManager()->getSceneNode("GNode" + pEntidad->getNombreNodo())->getPosition();
	Ogre::AxisAlignedBox bbox = pEntidad->getPEstado()->getScnManager()->getSceneNode(pEntidad->getNombreNodo())->_getWorldAABB();
	Ogre::Vector3  v = bbox.getSize()/2;


	FMOD_VECTOR vertices[4];
	vertices[0] = { posN.x - v.x,posN.y + v.y,posN.z};
	vertices[1] = { posN.x - v.x,posN.y - v.y,posN.z};
	vertices[2] = { posN.x + v.x,posN.y - v.y,posN.z};
	vertices[3] = { posN.x + v.x,posN.y + v.y,posN.z};
	std::cout<< geometry->addPolygon(1.0, 1.0, true, 4, vertices, &polygonIndex) << std::endl;

	system->update();
} 
OclusionComponent::~OclusionComponent() { 
} 
