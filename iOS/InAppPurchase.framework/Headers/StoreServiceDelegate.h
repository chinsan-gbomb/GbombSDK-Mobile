//
//  StoreServiceDelegate.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/15.
//
//

#ifndef __InAppPurchase__StoreServiceDelegate__
#define __InAppPurchase__StoreServiceDelegate__

#include <iostream>
#include <map>
#include "InAppPurchaseVOs.h"


class StoreServiceDelegate
{
public:
    StoreServiceDelegate();
    virtual ~StoreServiceDelegate();
    static StoreServiceDelegate* GetInstance();
    
    void StoreProductsResponse(IAPProductListResponseVO *vo);
    void StoreCompleteTransaction(IAPPurchaseVO *vo);
    void StoreFailedTransaction(IAPPurchaseResponseVO *vo);
    void StoreRestoreTransaction(IAPPurchaseVO *vo);
    void StoreConfirmedTransaction(IAPPurchaseResponseVO *vo);
private:
    static StoreServiceDelegate *__storeServiceDelegate;
    std::string __responseText;
};


#endif /* defined(__InAppPurchase__StoreServiceDelegate__) */
