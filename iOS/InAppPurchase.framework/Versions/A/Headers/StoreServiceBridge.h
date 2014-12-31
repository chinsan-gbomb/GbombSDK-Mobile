//
//  StoreServiceBridge.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/15.
//
//

#ifndef __InAppPurchase__StoreServiceBridge__
#define __InAppPurchase__StoreServiceBridge__

#include <iostream>
#include "InAppPurchaseVOs.h"

class StoreServiceBridge
{
public:
	StoreServiceBridge();
	virtual ~StoreServiceBridge();
	virtual void productsRequest(IAPProductListResponseVO *vo);
	virtual void addPayment(IAPPurchaseVO *vo);

//    virtual void confirmPurchase(IAPPurchaseResponseVO *vo);
	virtual void confirmPurchase(IAPPurchaseVO *vo);
};

#endif /* defined(__InAppPurchase__StoreServiceBridge__) */
