/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 03:16:57 by aboumall          #+#    #+#             */
/*   Updated: 2025/07/10 03:17:31 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain default constructor called" << std::endl;
}
Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i) {
		_ideas[i] = other._ideas[i];
	}
}
Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

void Brain::setIdea(int index, const std::string &idea) {
	if (index >= 0 && index < 100) {
		_ideas[index] = idea;
	}
}
std::string Brain::getIdea(int index) const {
	if (index >= 0 && index < 100) {
		return _ideas[index];
	}
	return "";
}
