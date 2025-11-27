/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 03:27:27 by aboumall          #+#    #+#             */
/*   Updated: 2025/11/27 12:14:58 by aboumall         ###   ########.fr       */
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
		virtual ~Character();
		Character();
		Character(const std::string name);
		Character(const Character &other);
		
		Character &operator=(const Character &other);
		
		std::string const & getName() const;
		void		equip(AMateria* m);
		void		unequip(int idx);
		void		use(int idx, ICharacter &target);
};

#endif