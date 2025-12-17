/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 03:00:59 by aboumall          #+#    #+#             */
/*   Updated: 2025/12/17 15:59:11 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
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
		std::cout << std::endl;

		for (int i = 0; i < 4; ++i) {
			std::cout << "Animal " << i + 1 << " type: " << animals[i]->getType() << std::endl;
			animals[i]->makeSound();
			std::cout << std::endl;
			delete animals[i];
			std::cout << std::endl;
		}
	}
	std::cout << "\nTesting Brain:\n" << std::endl;
	{
		Cat* cat = new Cat();
		Dog* dog = new Dog();

		std::cout << std::endl;
		
		cat->getBrain()->setIdea(0, "sleep");
		cat->getBrain()->setIdea(1, "hunt");
		cat->getBrain()->setIdea(2, "eat");

		dog->getBrain()->setIdea(0, "sleep");
		dog->getBrain()->setIdea(1, "eat");

		std::string idea = cat->getBrain()->getIdea(0);
		for (int i = 0; !idea.empty(); i++)
		{
			std::cout << "cat idea " << i << " " << idea << std::endl;
			idea = cat->getBrain()->getIdea(i + 1);
		}
		std::cout << std::endl;
		idea = dog->getBrain()->getIdea(0);
		for (int i = 0; !idea.empty(); ++i)
		{
			std::cout << "dog idea " << i << " " << idea << std::endl;
			idea = dog->getBrain()->getIdea(i + 1);
		}

		std::cout << std::endl;

		delete cat;
		delete dog;
	}
	return 0;
}