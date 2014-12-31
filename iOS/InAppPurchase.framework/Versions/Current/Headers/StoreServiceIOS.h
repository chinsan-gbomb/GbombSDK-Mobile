//
//  StoreServiceIOS.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/15.
//
//

#ifndef __InAppPurchase__StoreServiceIOS__
#define __InAppPurchase__StoreServiceIOS__

#include <iostream>
#include "InAppPurchaseVOs.h"
#include "StoreServiceBridge.h"

class StoreServiceIOS : public StoreServiceBridge
{
public:
    StoreServiceIOS();
    virtual ~StoreServiceIOS();
    virtual void productsRequest(IAPProductListResponseVO *vo);
    virtual void addPayment(IAPPurchaseVO *vo);
    virtual void confirmPurchase(IAPPurchaseResponseVO *vo);
};
#endif /* defined(__InAppPurchase__StoreServiceIOS__) */
