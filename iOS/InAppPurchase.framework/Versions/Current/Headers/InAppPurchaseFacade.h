
//
//  AppFacade.h
//  InAppPurchase
//
//  Created by kaijung on 13/2/20.
//
//

//For test only, must be removed
//#define TEST_MAKE_HAND_ONLY

#ifndef __InAppPurchase__InAppPurchaseFacade__
#define __InAppPurchase__InAppPurchaseFacade__

#include "PureMVC/PureMVC.hpp"
#include "InAppPurchaseVOs.h"


using PureMVC::Interfaces::IFacade;
using PureMVC::Interfaces::ICommand;
using PureMVC::Interfaces::IModel;
using PureMVC::Interfaces::IView;
using PureMVC::Interfaces::IController;
using PureMVC::Interfaces::IMediator;
using PureMVC::Interfaces::IProxy;
using PureMVC::Interfaces::IAggregate;
using PureMVC::Interfaces::INotification;
using PureMVC::Patterns::Facade;

class InAppPurchaseFacade
: public virtual IFacade
, public Facade
{
    friend class Facade;
public:
    //IAP Commands
    
    static const std::string APP_NAME;
    static const std::string INIT;
    static const std::string REQUEST_PRODUCT_LIST;
    static const std::string RESPONSE_PRODUCT_LIST;
    static const std::string REQUEST_PURCHASE;
    static const std::string RESPONSE_PURCHASE;
    static const std::string RESPONSE_PURCHASE_FAIL;
    //Lobby
    
protected:
    InAppPurchaseFacade(std::string const& key)
    :Facade(this, key)
    { }
public:
    static InAppPurchaseFacade& getInstance(std::string const& key);
    static void setProductList(IAPProductListResponseVO* productList);
    static std::map<std::string, IAPProduct> getProductList();
    static IAPPurchaseVO currentPurchase;
private:
    static std::map<std::string, IAPProduct> _productList;


protected:
    void initializeNotifier(std::string const& key);
    
    void initializeFacade(void);
    
    virtual ~InAppPurchaseFacade();
public:
    /**
    * Register an <code>ICommand</code> with the <code>Controller</code> by Notification name.
     *
     * @param notification_name the name of the <code>INotification</code> to associate the <code>ICommand</code> with
     * @param command a reference to the instance of the <code>ICommand</code>
     */
    virtual void registerCommand(std::string const& notification_name, ICommand* command);

    /**
     * Remove a previously registered <code>ICommand</code> to <code>INotification</code> mapping from the Controller.
     *
     * @param notification_name the name of the <code>INotification</code> to remove the <code>ICommand</code> mapping for
     * @return the <code>ICommand</code> that was removed from the <code>Controller</code>
     */
    virtual ICommand* removeCommand(std::string const& notification_name);

    /**
     * Retrieve an <code>ICommand</code> instance from the Controller.
     *
     * @param notification_name the notification of the <code>INotification</code>
     * @return the <code>ICommand</code> instance previously registered with the given <code>notification</code>.
     */
    virtual ICommand const& retrieveCommand(std::string const& notification_name) const;

    /**
     * Retrieve an <code>ICommand</code> instance from the Controller.
     *
     * @param notification_name the name of the <code>INotification</code>
     * @return the <code>ICommand</code> instance previously registered with the given <code>notification</code>.
     */
    virtual ICommand& retrieveCommand(std::string const& notification_name);

    /**
     * Check if a Command is registered for a given Notification
     *
     * @param notification_name
     * @return whether a Command is currently registered for the given <code>notificationName</code>.
     */
    virtual bool hasCommand(std::string const& notification_name) const;

    /**
     * Register an <code>IProxy</code> with the <code>Model</code> by name.
     *
     * @param proxy the name of the <code>IProxy</code>.
     * @param proxy the <code>IProxy</code> instance to be registered with the <code>Model</code>.
     */
    virtual void registerProxy (IProxy* proxy);

    /**
     * Retrieve an <code>IProxy</code> from the <code>Model</code> by name.
     *
     * @param proxy_name the name of the proxy to be retrieved.
     * @return the <code>IProxy</code> instance previously registered with the given <code>proxyName</code>.
     */
    virtual IProxy const& retrieveProxy (std::string const& proxy_name) const;

    /**
     * Retrieve an <code>IProxy</code> from the <code>Model</code> by name.
     *
     * @param proxy_name the name of the proxy to be retrieved.
     * @return the <code>IProxy</code> instance previously registered with the given <code>proxyName</code>.
     */
    virtual IProxy& retrieveProxy (std::string const& proxy_name);

    /**
     * Remove an <code>IProxy</code> from the <code>Model</code> by name.
     *
     * @param proxy_name the <code>IProxy</code> to remove from the <code>Model</code>.
     * @return the <code>IProxy</code> that was removed from the <code>Model</code>
     */
    virtual IProxy* removeProxy (std::string const& proxy_name);

    /**
     * Check if a Proxy is registered
     *
     * @param proxy_name
     * @return whether a Proxy is currently registered with the given <code>proxyName</code>.
     */
    virtual bool hasProxy(std::string const& proxy_name) const;

    /**
     * Register a <code>IMediator</code> with the <code>View</code>.
     *
     * @param mediator a reference to the <code>IMediator</code>
     */
    virtual void registerMediator(IMediator* mediator);

    /**
     * Retrieve an <code>IMediator</code> from the <code>View</code>.
     *
     * @param mediator_name
     * @return the <code>IMediator</code> previously registered with the given <code>mediatorName</code>.
     */
    virtual IMediator const& retrieveMediator(std::string const& mediator_name) const;

    /**
     * Retrieve an <code>IMediator</code> from the <code>View</code>.
     *
     * @param mediator_name
     * @return the <code>IMediator</code> previously registered with the given <code>mediatorName</code>.
     */
    virtual IMediator& retrieveMediator(std::string const& mediator_name);

    /**
     * Remove an <code>IMediator</code> from the <code>View</code>.
     *
     * @param mediator_name name of the <code>IMediator</code> to be removed.
     * @return the <code>IMediator</code> that was removed from the <code>View</code>
     */
    virtual IMediator* removeMediator(std::string const& mediator_name);

    /**
     * Check if a Mediator is registered or not
     *
     * @param mediator_name
     * @return whether a Mediator is registered with the given <code>mediatorName</code>.
     */
    virtual bool hasMediator(std::string const& mediator_name) const;

    /**
     * Create and send an <code>INotification</code>.
     *
     * <P>
     * Keeps us from having to construct new notification
     * instances in our implementation code.
     * @param notification_name the name of the notification to send
     * @param body the body of the notification (optional)
     * @param type the type of the notification (optional)
     */
     virtual void sendNotification(std::string const& notification_name, void const* body = NULL, std::string const& type = "");

    /**
     * Notify <code>Observer</code>s.
     * <P>
     * This method is left public mostly for backward
     * compatibility, and to allow you to send custom
     * notification classes using the facade.</P>
     *<P>
     * Usually you should just call sendNotification
     * and pass the parameters, never having to
     * construct the notification yourself.</P>
     *
     * @param notification the <code>INotification</code> to have the <code>View</code> notify <code>Observers</code> of.
     */
    virtual void notifyObservers(INotification const& notification);

    virtual std::string const& getMultitonKey(void) const;
};


#endif /* defined(__MobileThirteen__AppFacade__) */
