/*
 * InitInAppPurchaseCommand.h
 *
 *  Created on: 2013/12/2
 *      Author: kaijung
 */

#ifndef __InAppPurchase_InitInAppPurchaseCommand__
#define __InAppPurchase_InitInAppPurchaseCommand__

#include <PureMVC/PureMVC.hpp>

using PureMVC::Patterns::SimpleCommand;
using PureMVC::Interfaces::INotification;
using PureMVC::Interfaces::ICommand;

struct InitInAppPurchaseCommand
: public virtual ICommand
, public SimpleCommand
{
public:
	InitInAppPurchaseCommand(void):SimpleCommand()
	{ }
	virtual void execute(INotification const& note);
};

#endif /* __InAppPurchase_InitInAppPurchaseCommand__ */
