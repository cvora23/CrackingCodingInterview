/*
 * AnimalShelter.cpp
 *
 *  Created on: Aug 24, 2017
 *      Author: chivora
 */

#include<iostream>
#include<stdlib.h>
#include <stack>
#include <vector>
#include <list>

using namespace std;

class Animal{
public:

	enum Type{
		CAT,
		DOG
	};

	Type getType(){
		return type;
	}

	string getName(){
		return name;
	}

	Animal(Animal::Type type,string name){
		this->type = type;
		this->name = name;
	}

private:
	string name;
	Animal::Type type;
};

class Dog : public Animal{
public:
	Dog(string name):Animal(Animal::DOG,name){

	}
};

class Cat : public Animal{

public:
	Cat(string name):Animal(Animal::CAT,name){

	}
};

class AnimalShelter{
private:
	list<Animal*>animalList;
	list<Dog*>dogList;
	list<Cat*>catList;

public:

	void enqueue(Animal* animal){
		animalList.push_back(animal);
		if(animal->getType() == Animal::DOG){
			dogList.push_back(static_cast <Dog*>(animal));
		}else if(animal->getType() == Animal::CAT){
			catList.push_back(static_cast <Cat*>(animal));
		}
	}

	Animal* dequeueAny(){
		if(animalList.empty()){
			return NULL;
		}
		Animal* animal = animalList.front();
		animalList.pop_front();
		if(animal->getType() == Animal::DOG){
			dogList.pop_front();
		}else if(animal->getType() == Animal::CAT){
			catList.pop_front();
		}
		return animal;
	}

	Dog* dequeueDog(){
		if(dogList.empty()){
			return NULL;
		}
		Dog* dog = dogList.front();
		dogList.pop_front();
		return dog;
	}

	Cat* dequeueCat(){
		if(catList.empty()){
			return NULL;
		}
		Cat* cat = catList.front();
		catList.pop_front();
		return cat;
	}
};


int main(){

	AnimalShelter animalShelter;
	Animal* cat1 = new Cat("cat1");
	Animal* cat2 = new Cat("cat2");
	Animal* cat3 = new Cat("cat3");
	Animal* cat4 = new Cat("cat4");
	Animal* cat5 = new Cat("cat5");
	Animal* cat6 = new Cat("cat6");
	Animal* dog1 = new Dog("dog1");
	Animal* dog2 = new Dog("dog2");
	Animal* dog3 = new Dog("dog3");
	Animal* dog4 = new Dog("dog4");
	Animal* dog5 = new Dog("dog5");
	Animal* dog6 = new Dog("dog6");

	animalShelter.enqueue(cat1);
	animalShelter.enqueue(dog1);
	animalShelter.enqueue(dog2);
	animalShelter.enqueue(dog3);
	animalShelter.enqueue(cat2);
	animalShelter.enqueue(cat3);
	animalShelter.enqueue(cat4);
	animalShelter.enqueue(cat5);
	animalShelter.enqueue(dog4);
	animalShelter.enqueue(dog5);
	animalShelter.enqueue(dog6);
	animalShelter.enqueue(cat6);

	Animal* anim = animalShelter.dequeueAny();
	if(anim != NULL)
		cout<<"Animal Name : "<<anim->getName()<<endl;
	anim = animalShelter.dequeueDog();
	if(anim != NULL)
		cout<<"Animal Name : "<<anim->getName()<<endl;
	anim = animalShelter.dequeueDog();
	if(anim != NULL)
		cout<<"Animal Name : "<<anim->getName()<<endl;
	anim = animalShelter.dequeueDog();
	if(anim != NULL)
		cout<<"Animal Name : "<<anim->getName()<<endl;
	anim = animalShelter.dequeueCat();
	cout<<"Animal Name : "<<anim->getName()<<endl;
	anim = animalShelter.dequeueDog();
	if(anim != NULL)
		cout<<"Animal Name : "<<anim->getName()<<endl;
	anim = animalShelter.dequeueCat();
	if(anim != NULL)
		cout<<"Animal Name : "<<anim->getName()<<endl;
}

