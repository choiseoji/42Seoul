/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:30:26 by seojchoi          #+#    #+#             */
/*   Updated: 2023/12/10 20:24:29 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// 생성자
Account::Account(int initial_deposit)
{
    // 초기화
    this->_accountIndex = _accountIndex;
    _accountIndex++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    // 정보 갱신
    _nbAccounts++;
    _totalAmount += this->_amount;
    _totalNbDeposits += this->_nbDeposits;
    _totalNbWithdrawals += this->_nbWithdrawals;
    // 출력 문구
    std::cout << "[19920104_091532] ";
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:"<< this->_amount << ";";
    std::cout << "created\n";
}

Account::Account(void) { }

// 소멸자
Account::~Account(void)
{
    std::cout << "[19920104_091532] ";
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:"<< this->_amount << ";";
    std::cout << "closed\n";
}

int     Account::getNbAccounts(void)
{
    return (_nbAccounts);
}

int     Account::getTotalAmount(void)
{
    return (_totalAmount);
}

int     Account::getNbDeposits(void)
{
    return (_totalNbDeposits);
}

int     Account::getNbWithdrawals(void)
{
    return (_totalNbWithdrawals);
}

void    Account::displayAccountsInfos(void)
{
    std::cout << "[19920104_091532] ";
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:"<< Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << "\n";
}

void    Account::makeDeposit(int deposit)
{
    std::cout << "[19920104_091532] ";
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    this->_amount += deposit;
    _totalAmount += deposit;
    std::cout << "amount:" << this->_amount << ";";
    if (deposit != 0)
    {
        std::cout << "nb_deposits:1\n";
        _nbDeposits++;
    }
    else
        std::cout << "nb_deposits:0\n";
}

bool    Account::makeWithdrawal(int withdrawal)
{
    std::cout << "[19920104_091532] ";
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    if (this->_amount - withdrawal <= 0)       // 뭔가 여기에 checkAmount 함수 사용하는거 같은데..
        std::cout << "withdrawal:" << "refused\n";
    else
    {
        std::cout << "withdrawal:" << withdrawal << ";";
        this->_amount -= withdrawal;
        _totalAmount -= withdrawal;
        std::cout << "amount:" << this->_amount << ";";
        std::cout << "nb_withdrawals:1\n";
        _nbWithdrawals++;
    }
    return (0);
}

// int     Account::checkAmount(void) const
// {
        
// }

void    Account::displayStatus(void) const
{
    std::cout << "[19920104_091532] ";
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals" << this->_nbWithdrawals << "\n";
}
