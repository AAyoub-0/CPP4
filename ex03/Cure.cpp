/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 17:55:56 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/04 18:47:28 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

#ifndef DEBUG
# define DEBUG 0
#endif

Cure::Cure() : AMateria("cure") {
	#if DEBUG
	std::cout << "Cure default constructor called" << std::endl;
	#endif
}

Cure::Cure(const Cure& other) : AMateria(other) {
	#if DEBUG
	std::cout << "Cure copy constructor called" << std::endl;
	#endif
}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return *this;
}

Cure::~Cure() {
	#if DEBUG
	std::cout << "Cure destructor called" << std::endl;
	#endif
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
