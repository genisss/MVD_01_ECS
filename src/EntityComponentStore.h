#pragma once
#include "Components.h"
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

/**** ENTITY COMPONENT STORE ****/

//the entity component manager is a global struct that contains an array of
//all the entities, and an array to store each of the component types
struct EntityComponentStore {

	vector<Entity> entities;

	ComponentArrays components; // tuple of arrrays

	int createEntity(string name) {
		entities.emplace_back(name);
		return (int)entities.size() - 1;
	}

	//create Entity and add transform component by default
	//return array id of new entity
//    int createEntity(string name) {
//
//    }
//
	//creates a new component with no entity parent
	template<typename T>
	int createComponent() {
		vector<T>& the_comps = get<vector<T>>(components);
		//Creates a new object directly at the back
		the_comps.emplace_back();

		return (int)the_comps.size() - 1; // index of new component in its array
	}

	//creates a new component and associates it with an entity
	template<typename T>
	T& createComponentForEntity(int entity_id) {
		vector<T>& the_comps = get<vector<T>>(components);
		the_comps.emplace_back();

		//ad to entity component array the index og the new component
		int type_index = type2int<T>::result;

		entities[entity_id].components[type_index] = the_comps.size() - 1;

		the_comps.back().owner = entity_id;
		return the_comps.back();
	}
	
	    //return reference to component at id in array
	    template<typename T>
	    T& getComponentInArray(int an_id) {
			vector<T>& the_comps = get<vector<T>>(components);
			return the_comps[an_id];
	    }
	
	    //return reference to component stored in entity
	    template<typename T>
	    T& getComponentFromEntity(int entity_id) {
			//index of type T e.g. Transform = 0
			int type_index = type2int<T>::result;
			//gets index of component or this entity
			int comp_index = entities[entity_id].components[type_index];
			//return a reference to the component
			return  get<vector<T>>(components)[comp_index];

	    }
	
	    //return id of component in relevant array
	    template<typename T>
	    int getComponentID(int entity_id) {
			//index of type T e.g. Transform = 0
			int type_index = type2int<T>::result;
			//gets index of component or this entity
			return entities[entity_id].components[type_index];
	    }
	
	    //returns a const (i.e. non-editable) reference to vector of Type
	    //i.e. array will not be editable
	    template<typename T>
	    std::vector<T>& getAllComponents() {
			return get<Vector<T>>(components);
	    }

		//stores main camera id
	int main_camera = -1;
	
};

