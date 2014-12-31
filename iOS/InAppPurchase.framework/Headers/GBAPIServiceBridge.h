//
//  GBAPIServiceBridge.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/9.
//
//

#ifndef __InAppPurchase__GBAPIServiceBridge__
#define __InAppPurchase__GBAPIServiceBridge__

#include <iostream>
#include "InAppPurchaseVOs.h"

class GBAPIServiceBridge
{
public:
    GBAPIServiceBridge();
    virtual ~GBAPIServiceBridge();
    virtual void getProductList(IAPProductListVO *vo);
    virtual void purchase(IAPPurchaseVO *vo);
};

#endif /* defined(__InAppPurchase__GBAPIServiceBridge__) */
