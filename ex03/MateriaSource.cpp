/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:16:13 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/04 18:48:19 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

#ifndef DEBUG
# define DEBUG 0
#endif

MateriaSource::MateriaSource() {
	#if DEBUG
	std::cout << "MateriaSource default constructor called" << std::endl;
	#endif
	for (int i = 0; i < 4; i++)
		_inventory[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	#if DEBUG
	std::cout << "MateriaSource copy constructor called" << std::endl;
	#endif
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = nullptr;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
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

MateriaSource::~MateriaSource() {
	#if DEBUG
	std::cout << "MateriaSource destructor called" << std::endl;
	#endif
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			std::cout << "Learned materia of type: " << m->getType() << std::endl;
			return;
		}
	}
	std::cout << "Inventory full, cannot learn more materia." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i] && _inventory[i]->getType() == type) {
			std::cout << "Creating materia of type: " << type << std::endl;
			return _inventory[i]->clone();
		}
	}
	std::cout << "Materia of type " << type << " not found." << std::endl;
	return nullptr;
}
