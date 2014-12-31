//
//  RequestPurchaseCommand.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/22.
//
//

#ifndef __InAppPurchase__RequestPurchaseCommand__
#define __InAppPurchase__RequestPurchaseCommand__

#include "PureMVC/PureMVC.hpp"

using PureMVC::Patterns::SimpleCommand;
using PureMVC::Interfaces::INotification;
using PureMVC::Interfaces::ICommand;

struct RequestPurchaseCommand
: public virtual ICommand
, public SimpleCommand
{
    RequestPurchaseCommand(void)
    :SimpleCommand()
    { }
    virtual void execute(INotification const& note);
};

#endif /* defined(__InAppPurchase__RequestPurchaseCommand__) */
