//
//  GBAPIServiceIOS.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/10.
//
//

#ifndef __InAppPurchase__GBAPIServiceIOS__
#define __InAppPurchase__GBAPIServiceIOS__

#include <iostream>
#include "InAppPurchaseVOs.h"
#include "GBAPIServiceBridge.h"

class GBAPIServiceIOS : public GBAPIServiceBridge
{
public:
    GBAPIServiceIOS();
    virtual ~GBAPIServiceIOS();
    virtual void getProductList(IAPProductListVO *vo);
    virtual void purchase(IAPPurchaseVO *vo);
};

#endif /* defined(__InAppPurchase__GBAPIServiceIOS__) */
