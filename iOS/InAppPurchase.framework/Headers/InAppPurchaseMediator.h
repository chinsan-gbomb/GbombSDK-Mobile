//
//  libInAppPurchaseMediator.h
//  InAppPurchase
//
//  Created by kaijung on 13/10/7.
//  Copyright (c) 2013年 kaijung. All rights reserved.
//

#ifndef __InAppPurchase__InAppPurchaseMediator__
#define __InAppPurchase__InAppPurchaseMediator__

#include "PureMVC/PureMVC.hpp"


using PureMVC::Patterns::Mediator;
using PureMVC::Patterns::StdContainerAggregate;
using PureMVC::Interfaces::IMediator;
using PureMVC::Interfaces::INotification;




class InAppPurchaseMediator:public Mediator
{
public:
    /**
     * The Mediator name
     */
    static char const* const NAME;
    
public:
    /**
     * Copy constructor.
     */
    explicit InAppPurchaseMediator(Mediator const& arg);
    
public:
    /**
     * Constructor.
     */
    InAppPurchaseMediator(std::string const& name, void const* view);
    /**
     * Get the name of the <code>Mediator</code>.
     */
    virtual std::string const& getMediatorName(void) const;
    
    /**
     * Set the <code>IMediator</code>'s view component.
     *
     * @param view_component the view component.
     */
    virtual void setViewComponent(void const* view_component);
    
    /**
     * Get the <code>Mediator</code>'s view component.
     *
     * <P>
     * Additionally, an implicit getter will usually
     * be defined in the subclass that casts the view
     * object to a type</P>
     *
     * @return the view component.
     */
    virtual void const* getViewComponent(void) const;
    
    /**
     * List the <code>INotification</code> names this
     * <code>Mediator</code> is interested in being notified of.
     *
     * @return Array the list of <code>INotification</code> names.
     */
    virtual Mediator::NotificationNames listNotificationInterests(void) const;
    
    /**
     * Handle <code>INotification</code>s.
     *
     * <P>
     * Typically this will be handled in a switch statement,
     * with one 'case' entry per <code>INotification</code>
     * the <code>Mediator</code> is interested in.
     */
    virtual void handleNotification(INotification const& notification);
    
    /**
     * Called by the View when the Mediator is registered.
     */
    virtual void onRegister(void);
    
    /**
     * Called by the View when the Mediator is removed.
     */
    virtual void onRemove(void);
    
    
    /**
     * Virtual destructor.
     */
    virtual ~InAppPurchaseMediator(void);
    /**
     * Constructor
     */
};

#endif /* defined(__InAppPurchase__InAppPurchaseMediator__) */
