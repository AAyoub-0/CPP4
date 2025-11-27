/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 02:51:23 by aboumall          #+#    #+#             */
/*   Updated: 2025/11/27 12:12:31 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other), _brain(NULL) {
	std::cout << "Cat copy constructor called" << std::endl;
}
Cat::~Cat() {
	delete _brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
		if (_brain) {
			delete _brain;
		}
		_brain = new Brain(*other._brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "MEOW MEOW MEOW" << std::endl;
}
