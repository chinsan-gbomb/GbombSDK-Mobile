//
//  APIServiceProxy.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/9.
//
//

#ifndef __InAppPurchase__GBAPIServiceProxy__
#define __InAppPurchase__GBAPIServiceProxy__

#include <PureMVC/PureMVC.hpp>
#include "InAppPurchaseVOs.h"
#include "GBAPIServiceBridge.h"

using PureMVC::Interfaces::IProxy;
using PureMVC::Patterns::Proxy;

class GBAPIServiceProxy
: public virtual IProxy
, public Proxy
{
    friend class Proxy;
    
public:
    GBAPIServiceProxy(std::string const& key)
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
    
    void getProductList(IAPProductListVO *vo);
    void purchase(IAPPurchaseVO *vo);
    
    //void onProductListResponse(IAPProductListResponseVO *vo);
   //void onPurchaseResponse(IAPPurchaseResponseVO *vo);
    
    
    IAPProductListResponseVO * getProductListResponseVO();
    IAPPurchaseResponseVO * getPurchaseResponseVO();
    
    static char const* const NAME;
private:
    GBAPIServiceBridge *__gbAPIService;
    IAPProductListResponseVO *__productListResponseVO;
    IAPPurchaseResponseVO *__purchaseResponseVO;
};

#endif /* defined(__InAppPurchase__APIServiceProxy__) */
