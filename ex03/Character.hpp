/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 03:27:27 by aboumall          #+#    #+#             */
/*   Updated: 2025/11/28 14:13:45 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#define nullptr 0

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria*	_inventory[4];
	public:
		Character();
		Character(const std::string name);
		Character(const Character &other);
		~Character();
		
		Character &operator=(const Character &other);
		
		std::string const & getName() const;
		void		equip(AMateria* m);
		void		unequip(int idx);
		void		use(int idx, ICharacter &target);
};

#endif