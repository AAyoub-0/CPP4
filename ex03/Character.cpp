/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 03:42:32 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/03 03:53:54 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): _name("NPC") {
	std::cout << "Character default constructor called" << std::endl;
}

Character::Character(const std::string name) : _name(name) {
	std::cout << "Character " << _name << " constructor called" << std::endl;
}

Character::~Character() {
	std::cout << "Character " << _name << " destructor called" << std::endl;
}

Character::Character(const Character &other) : Character(other._name) {
	std::cout << "Character copy constructor called" << std::endl;
}

Character &Character::operator=(const Character &other) {
	return *this;
}

std::string Character::getName() {
	return this->_name;
}

void	Character::equip(AMateria *m) {
	
}