/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 03:42:32 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/04 18:53:00 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

#ifndef DEBUG
# define DEBUG 0
#endif

Character::Character() : _name("default") {
	#if DEBUG
	std::cout << "Character default constructor called" << std::endl;
	#endif
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const std::string name) : _name(name) {
	#if DEBUG
	std::cout << "Character parameterized constructor called" << std::endl;
	#endif
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

Character::Character(const Character &other) : _name(other._name) {
	#if DEBUG
	std::cout << "Character copy constructor called" << std::endl;
	#endif
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

Character &Character::operator=(const Character &other) {
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = nullptr;
		}
	}
	return *this;
}

Character::~Character() {
	#if DEBUG
	std::cout << "Character destructor called" << std::endl;
	#endif
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

std::string const & Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (!m) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			std::cout << _name << " equipped " << m->getType() << " materia in slot " << i << "." << std::endl;
			return;
		}
	}
	std::cout << _name << "'s inventory is full. Cannot equip more materia." << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		return;
	}
	if (_inventory[idx]) {
		std::cout << _name << " unequipped " << _inventory[idx]->getType() << " materia from slot " << idx << "." << std::endl;
		_inventory[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= 4) {
		return;
	}
	if (_inventory[idx]) {
		std::cout << _name << " uses " << _inventory[idx]->getType() << " materia on " << target.getName() << "." << std::endl;
		_inventory[idx]->use(target);
	}
}
