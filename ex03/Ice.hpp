/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall42@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 03:25:00 by aboumall          #+#    #+#             */
/*   Updated: 2025/11/28 14:01:32 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice& other);
		virtual ~Ice();
		
		Ice& operator=(const Ice& other);

		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);
};

#endif