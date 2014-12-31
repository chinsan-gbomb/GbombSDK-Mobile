//
//  InAppPurchaseVOs.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/9.
//
//

#ifndef InAppPurchase_InAppPurchaseVOs_h
#define InAppPurchase_InAppPurchaseVOs_h

#include <iostream>
#include <vector>

struct IAPProduct
{
    std::string Title;
    std::string ImageUrl;
    std::string ItemId;
    std::string Description;
//    std::string ProductUrl;
    std::string CurrencyCode;
    std::string OnSaleId;
    double Price;
};

struct IAPTransaction
{
    time_t TransactionTime;
    std::string TransactionID;
    std::string TransactionDetail;
};

#define IAP_INIT     6000   ///
struct IAPInitVO
{
    int Protocol;
    std::string PaymentID;
    std::string ProviderID;
    std::string AccessToken;
    std::string ClientID;
    IAPInitVO(){ Protocol=IAP_INIT; }
};

#define IAP_PRODUCT_LIST     6001   ///
struct IAPProductListVO
{
    int Protocol;
    std::string PaymentID;
    std::string GameId;
    IAPProductListVO(){ Protocol=IAP_PRODUCT_LIST; }
};

#define IAP_PRODUCT_LIST_RESPONSE     6002   ///
struct IAPProductListResponseVO
{
    int Protocol;
    int Success;
    std::string ErrorMsg;
    std::vector<IAPProduct *> Products;
    IAPProductListResponseVO(){ Protocol=IAP_PRODUCT_LIST_RESPONSE; }
};

#define IAP_PURCHASE     6003   ///
struct IAPPurchaseVO
{
    int Protocol;
    std::string ProviderId;
    std::string AccessToken;
    std::string OnSaleId;
    std::string Receipt;
    std::string ServerId;
    std::string CharacterId;
    std::string OrderId;
    std::string ItemId;
    std::string OrderDetails;
    std::string GameId;
//    std::string ClientID;
    IAPPurchaseVO(){ Protocol=IAP_PURCHASE; }
};

#define IAP_PURCHASE_RESPONSE     6004  ///
struct IAPPurchaseResponseVO
{
    int Protocol;
    int Success;
    std::string ErrorMsg;
    std::string OrderID;
    IAPPurchaseResponseVO(){ Protocol=IAP_PURCHASE_RESPONSE; }
};

#endif
