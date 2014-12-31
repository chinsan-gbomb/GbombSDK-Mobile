//
//  StoreServiceWindows.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/21.
//
//

#ifndef __InAppPurchase__StoreServiceWindows__
#define __InAppPurchase__StoreServiceWindows__

#include <iostream>
#include <iostream>
#include "InAppPurchaseVOs.h"
#include "StoreServiceDelegate.h"
#include "StoreServiceBridge.h"

class StoreServiceWindows : public StoreServiceBridge
{
public:
    StoreServiceWindows();
    virtual ~StoreServiceWindows();
    
    virtual void productsRequest(IAPProductListResponseVO *vo);
    virtual void addPayment(IAPPurchaseVO *vo);
    virtual void confirmPurchase(IAPPurchaseResponseVO *vo);
};
#endif /* defined(__InAppPurchase__StoreServiceDelegateBridgeWindows__) */
