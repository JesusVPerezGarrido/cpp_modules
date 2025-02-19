/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeperez- <jeperez-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:48:48 by jeperez-          #+#    #+#             */
/*   Updated: 2025/02/19 13:06:36 by jeperez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int main(void)
{
	int	starting[8] = {42, 54, 957, 432, 1234, 0, 754, 16576};
	int	deposits[8] = {5, 765, 564, 2, 87, 23, 9, 20};
	int	withdrawals[8] = {69420, 34, 657, 4, 76, -69, 657, 7654};

	Account acc0(starting[0]);
	Account acc1(starting[1]);
	Account acc2(starting[2]);
	Account acc3(starting[3]);
	Account acc4(starting[4]);
	Account acc5(starting[5]);
	Account acc6(starting[6]);
	Account acc7(starting[7]);
	acc0.displayAccountsInfos();
	acc0.displayStatus();
	acc1.displayStatus();
	acc2.displayStatus();
	acc3.displayStatus();
	acc4.displayStatus();
	acc5.displayStatus();
	acc6.displayStatus();
	acc7.displayStatus();
	acc0.makeDeposit(deposits[0]);
	acc1.makeDeposit(deposits[1]);
	acc2.makeDeposit(deposits[2]);
	acc3.makeDeposit(deposits[3]);
	acc4.makeDeposit(deposits[4]);
	acc5.makeDeposit(deposits[5]);
	acc6.makeDeposit(deposits[6]);
	acc7.makeDeposit(deposits[7]);
	acc0.displayAccountsInfos();
	acc0.displayStatus();
	acc1.displayStatus();
	acc2.displayStatus();
	acc3.displayStatus();
	acc4.displayStatus();
	acc5.displayStatus();
	acc6.displayStatus();
	acc7.displayStatus();
	acc0.makeWithdrawal(withdrawals[0]);
	acc1.makeWithdrawal(withdrawals[1]);
	acc2.makeWithdrawal(withdrawals[2]);
	acc3.makeWithdrawal(withdrawals[3]);
	acc4.makeWithdrawal(withdrawals[4]);
	acc5.makeWithdrawal(withdrawals[5]);
	acc6.makeWithdrawal(withdrawals[6]);
	acc7.makeWithdrawal(withdrawals[7]);
	acc0.displayAccountsInfos();
	acc0.displayStatus();
	acc1.displayStatus();
	acc2.displayStatus();
	acc3.displayStatus();
	acc4.displayStatus();
	acc5.displayStatus();
	acc6.displayStatus();
	acc7.displayStatus();
}
