/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:00:42 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/20 15:55:06 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include "ClapTrap.hpp"
# define F_HP 100
# define F_EP 100
# define F_AD 30

class FragTrap : virtual public ClapTrap
{
protected:
    static const int HP = F_HP;
    static const int EP = F_EP;
    static const int AD = F_AD;

public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &ft);
	FragTrap& operator = (const FragTrap &ft);
    ~FragTrap();

    void highFivesGuys(void);
};

#endif
