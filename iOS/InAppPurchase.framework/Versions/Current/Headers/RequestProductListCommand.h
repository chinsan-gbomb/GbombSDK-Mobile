//
//  OpenIAPViewCommand.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/14.
//
//

#ifndef __InAppPurchase__RequestProductListCommand__
#define __InAppPurchase__RequestProductListCommand__

#include "PureMVC/PureMVC.hpp"

using PureMVC::Patterns::SimpleCommand;
using PureMVC::Interfaces::INotification;
using PureMVC::Interfaces::ICommand;

struct RequestProductListCommand
: public virtual ICommand
, public SimpleCommand
{
    RequestProductListCommand(void)
    :SimpleCommand()
    { }
    virtual void execute(INotification const& note);
};

#endif /* defined(__InAppPurchase__OpenIAPViewCommand__) */
