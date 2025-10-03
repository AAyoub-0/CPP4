/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 03:00:59 by aboumall          #+#    #+#             */
/*   Updated: 2025/07/10 03:42:34 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	// doesn't work because Animal is an abstract class
	// Animal* animal = new Animal();
	std::cout << "Creating individual animals:\n" << std::endl;
	{
		Animal* animal = new Dog();
		std::cout << "Animal type: " << animal->getType() << std::endl;
		animal->makeSound();
		delete animal;

		animal = new Cat();
		std::cout << "Animal type: " << animal->getType() << std::endl;
		animal->makeSound();
		delete animal;
	}
	std::cout << "\nCreating an array of animals:\n" << std::endl;
	{
		Animal* animals[4];

		animals[0] = new Dog();
		animals[1] = new Cat();
		animals[2] = new Dog();
		animals[3] = new Cat();

		for (int i = 0; i < 4; ++i) {
			std::cout << "Animal " << i + 1 << " type: " << animals[i]->getType() << std::endl;
			animals[i]->makeSound();
			delete animals[i];
		}
	}
	return 0;
}