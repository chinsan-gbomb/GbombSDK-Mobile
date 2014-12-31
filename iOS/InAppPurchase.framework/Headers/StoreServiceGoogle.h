//
//  StoreServiceGoogle.h
//  InAppPurchase
//
//  Created by kaijung on 13/7/10.
//
//

#ifndef __InAppPurchase__StoreServiceGoogle__
#define __InAppPurchase__StoreServiceGoogle__

#include <iostream>
#include "InAppPurchaseVOs.h"
#include "StoreServiceDelegate.h"
#include "StoreServiceBridge.h"

class StoreServiceGoogle : public StoreServiceBridge
{
public:
	StoreServiceGoogle();
	virtual ~StoreServiceGoogle();

	virtual void productsRequest(IAPProductListResponseVO *vo);
	virtual void addPayment(IAPPurchaseVO *vo);

//    virtual void confirmPurchase(IAPPurchaseResponseVO *vo);
	virtual void confirmPurchase(IAPPurchaseVO *vo);
};

#endif /* defined(__InAppPurchase__StoreServiceGoogle__) */
