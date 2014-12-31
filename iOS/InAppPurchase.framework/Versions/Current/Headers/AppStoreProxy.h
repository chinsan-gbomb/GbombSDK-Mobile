//
//  AppStoreProxy.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/9.
//
//

#ifndef __InAppPurchase__AppStoreProxy__
#define __InAppPurchase__AppStoreProxy__
#include <PureMVC/PureMVC.hpp>
#include "StoreServiceBridge.h"

using PureMVC::Interfaces::IProxy;
using PureMVC::Patterns::Proxy;

class AppStoreProxy
: public virtual IProxy
, public Proxy
{
    friend class Proxy;
    
public:
    AppStoreProxy(std::string const& key)
    :Proxy(key)
    { }
    
    /**
     * Set the data object
     *
     * @param data the data object
     */
    virtual void setData(void const* data){};
    
    /**
     * Get the data object
     *
     * @return the data as type void*
     */
    virtual void const* getData(void) const{return NULL;};
    virtual void  onRegister(void);
    static char const* const NAME;
    
    void productsRequest(IAPProductListResponseVO *vo);
    void addPayment(IAPPurchaseVO *vo);
//    void confirmPurchase(IAPPurchaseResponseVO *vo);
    void confirmPurchase(IAPPurchaseVO *vo);
private:
    StoreServiceBridge *__storeService;
};

#endif /* defined(__InAppPurchase__AppStoreProxy__) */
