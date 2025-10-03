/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 03:27:27 by aboumall          #+#    #+#             */
/*   Updated: 2025/10/03 03:42:07 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : ICharacter
{
	private:
		std::string _name;
	public:
		~Character();
		Character();
		Character(const std::string name);
		Character(const Character &other);
		
		Character &operator=(const Character &other);
		
		std::string getName();
		void		equip(AMateria* m);
		void		unequip(int idx);
		void		use(int idx, ICharacter &target);
};

#endif