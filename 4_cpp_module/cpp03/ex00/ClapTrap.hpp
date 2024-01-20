/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:00:12 by seojchoi          #+#    #+#             */
/*   Updated: 2024/01/20 15:39:54 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>
# define C_HP 10
# define C_EP 10
# define C_AD 0

class ClapTrap {

private:
	std::string name;
	int hitPoints;
	int energyPoints; // attack, beRepaired 사용할 시 1 감소
	int attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &ct);    // 복사 생성자
	ClapTrap& operator = (const ClapTrap &ct);    // 복사 대입 연산자
	~ClapTrap();

	void attack(const std::string& target);  // 상대방의 hitPoint를 attackDamage만큼 감소
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);  // amount만큼 hitPoint 증가

	void printStat();
	bool checkPoint();
};

#endif
