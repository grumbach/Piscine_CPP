/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 23:15:43 by agrumbac          #+#    #+#             */
/*   Updated: 2018/03/27 23:25:38 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiningBarge.hpp"
#include "DeepCoreMiner.hpp"
#include "StripMiner.hpp"
#include "AsteroKreog.hpp"
#include "KoalaSteroid.hpp"

int		main(void)
{
	MiningBarge		windowsXP;

	DeepCoreMiner	angavrel;
	StripMiner		web_developpers;

	windowsXP.equip(&angavrel);
	windowsXP.equip(&web_developpers);

	AsteroBocal		vba;
	BocalSteroid	microsotf_exel;

	windowsXP.mine(&vba);
	windowsXP.mine(&microsotf_exel);


	return (0);
}
