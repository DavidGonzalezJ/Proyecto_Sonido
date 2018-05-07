#pragma once 
#include "btBulletDynamicsCommon.h"
#include <vector>
#include <map>
#include "LinearMath\btIDebugDraw.h"


//Esta clase tendr� una instancia en el estado
//Regular� todo lo relacionado con el mundo f�sico
class Fisic { 
public: 
	Fisic(); 
	~Fisic(); 
	btDiscreteDynamicsWorld* getDynamicsWorld() { return dynamicsWorld; };
	std::vector<btCollisionShape *> getCollisionShapes() { return collisionShapes; };
	//Devuelve el cuerpo con el nombre del nodo que se le pasa
	btRigidBody* getRigidBody(std::string nombre) { return physicsAccessors.at(nombre); };
	void addBodyToMap(std::string n, btRigidBody* b) { physicsAccessors.insert(std::pair<std::string, btRigidBody*>(n, b)); };

private:
	btDefaultCollisionConfiguration* collisionConfig;
	btCollisionDispatcher* dispatcher;
	btBroadphaseInterface* overlappingPairCache;
	btSequentialImpulseConstraintSolver* solver;
	btDiscreteDynamicsWorld* dynamicsWorld;
	

	std::vector<btCollisionShape*> collisionShapes;
	std::map<std::string, btRigidBody *> physicsAccessors;
}; 