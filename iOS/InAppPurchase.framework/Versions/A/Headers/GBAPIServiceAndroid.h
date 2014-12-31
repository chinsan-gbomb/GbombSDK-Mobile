//
//  GBAPIServiceAndroid.h
//  InAppPurchase
//
//  Created by kaijung on 13/7/10.
//
//

#ifndef __InAppPurchase__GBAPIServiceAndroid__
#define __InAppPurchase__GBAPIServiceAndroid__

#include <iostream>
#include "InAppPurchaseVOs.h"
#include "GBAPIServiceBridge.h"

class GBAPIServiceAndroid : public GBAPIServiceBridge
{
public:
    GBAPIServiceAndroid();
    virtual ~GBAPIServiceAndroid();
    virtual void getProductList(IAPProductListVO *vo);
    virtual void purchase(IAPPurchaseVO *vo);
};
#endif /* defined(__InAppPurchase__GBAPIServiceAndroid__) */
