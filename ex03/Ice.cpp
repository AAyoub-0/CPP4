/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 17:56:23 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/04 18:47:50 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

#ifndef DEBUG
# define DEBUG 0
#endif

Ice::Ice() : AMateria("ice") {
	#if DEBUG
	std::cout << "Ice default constructor called" << std::endl;
	#endif
}

Ice::Ice(const Ice& other) : AMateria(other) {
	#if DEBUG
	std::cout << "Ice copy constructor called" << std::endl;
	#endif
}

Ice& Ice::operator=(const Ice& other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice() {
	#if DEBUG
	std::cout << "Ice destructor called" << std::endl;
	#endif
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
