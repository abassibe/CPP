/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abassibe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:25:28 by abassibe          #+#    #+#             */
/*   Updated: 2019/04/05 17:44:47 by abassibe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/HostModule.hpp"
#include "includes/OSModule.hpp"
#include "includes/DateModule.hpp"
#include "includes/CPUModule.hpp"
#include "includes/RAMModule.hpp"
#include "includes/NetworkModule.hpp"

int		main()
{
	HostModule host(0, 0);
	std::cout << "--------HOST-------\n";
	std::cout << host.getHostName() << std::endl;
	std::cout << host.getLoginName() << std::endl;
	std::cout << host.getDomaineName() << std::endl;
	std::cout << "\n--------OS-------\n";
	OSModule os(0, 0);
	std::cout << os.getProductName();
	std::cout << os.getProductVersion();
	std::cout << os.getBuildVersion();
	std::cout << os.getSysName() << std::endl;
	std::cout << os.getReleaseVersion() << std::endl;
	std::cout << os.getMachineArchitecture() << std::endl;
	std::cout << "\n--------DATE-------\n";
	DateModule date(0, 0);
	std::cout << date.getDate() << std::endl;
	std::cout << date.getTime() << std::endl;
	std::cout << "\n--------CPU-------\n";
	CPUModule cpu(0, 0);
	std::cout << cpu.getModel() << std::endl;
	std::cout << cpu.getClockSpeed() << std::endl;
	std::cout << cpu.getCore() << std::endl;
	std::cout << cpu.getActivity() << std::endl;
	for (int i = 0; i < 10; i++)
	{
		//sleep(1);
		cpu.updateData();
	}
	std::list<float> tnp = cpu.getPreviousActivity();
	for (std::list<float>::iterator it = tnp.begin(); it != tnp.end(); it++)
		std::cout << *it << std::endl;
	std::cout << "\n--------RAM-------\n";
	RAMModule ram(0, 0);
	std::cout << ram.getRAMCapacity() << std::endl;
	std::cout << ram.getRAMActivity() << std::endl;
	for (int i = 0; i < 10; i++)
	{
		//sleep(1);
		ram.updateData();
	}
	std::list<float> tmp = ram.getPreviousActivity();
	for (std::list<float>::iterator it = tmp.begin(); it != tmp.end(); it++)
		std::cout << *it << std::endl;

	std::cout << "\n--------Network-------\n";
	NetworkModule net(0, 0);
	while (1)
	{
		std::cout << "Input: " << net.getInputActivity() << std::endl;
		std::cout << "Output: " << net.getOutputActivity() << std::endl;
		net.updateData();
		sleep(1);
	}
}
