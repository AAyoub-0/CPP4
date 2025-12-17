/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 03:19:52 by aboumall          #+#    #+#             */
/*   Updated: 2025/12/17 15:27:34 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

#ifndef DEBUG
# define DEBUG 0
#endif

AMateria::AMateria(std::string const &type) : _type(type) {
	#if DEBUG
	std::cout << "AMateria constructor called" << std::endl;
	#endif
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
	#if DEBUG
	std::cout << "AMateria copy constructor called" << std::endl;
	#endif
}

AMateria::AMateria() : _type("fist") {
	#if DEBUG
	std::cout << "AMateria default constructor called" << std::endl;
	#endif
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		this->_type = other._type;
	}
	return *this;
}

AMateria::~AMateria() {
	#if DEBUG
	std::cout << "AMateria destructor called" << std::endl;
	#endif
}

std::string const & AMateria::getType() const {
	return this->_type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "* punches " << target.getName() << " *" << std::endl;
}
