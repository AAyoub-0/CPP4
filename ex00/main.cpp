/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 03:00:59 by aboumall          #+#    #+#             */
/*   Updated: 2025/07/10 03:01:24 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << "Dog type: " << dog->getType() << std::endl;
	dog->makeSound();

	std::cout << "Cat type: " << cat->getType() << std::endl;
	cat->makeSound();

	std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
	wrongCat->makeSound();

	delete dog;
	delete cat;
	delete wrongCat;

	return 0;
}