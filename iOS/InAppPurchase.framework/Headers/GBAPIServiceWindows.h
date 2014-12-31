//
//  GBAPIServiceIOS.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/10.
//
//

#ifndef __InAppPurchase__GBAPIServiceWindows__
#define __InAppPurchase__GBAPIServiceWindows__

#include <iostream>
#include "InAppPurchaseVOs.h"
#include "GBAPIServiceBridge.h"

class GBAPIServiceWindows : public GBAPIServiceBridge
{
public:
    GBAPIServiceWindows();
    virtual ~GBAPIServiceWindows();
    virtual void getProductList(IAPProductListVO *vo);
    virtual void purchase(IAPPurchaseVO *vo);
};

#endif /* defined(__InAppPurchase__GBAPIServiceWindows__) */
