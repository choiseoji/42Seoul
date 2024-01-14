/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:00:42 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/14 16:54:13 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
protected:
    static const int HP = 100;
    static const int EP = 100;
    static const int AD = 30;

public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &ft);
	FragTrap& operator = (const FragTrap &ft);
    ~FragTrap();

    void highFivesGuys(void);
};

#endif
