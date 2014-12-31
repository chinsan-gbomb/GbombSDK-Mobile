//
//  InAppPurchaseModel.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/9.
//
//

#ifndef __InAppPurchase__InAppPurchaseModel__
#define __InAppPurchase__InAppPurchaseModel__

#include "IUpdateable.h"
#include <PureMVC/PureMVC.hpp>
#include "GameModel.h"

using PureMVC::Interfaces::IModel;
using PureMVC::Core::Model;

class InAppPurchaseModel
: public virtual IModel,
public virtual IUpdateable,
public virtual GameModel
{
    friend class Model;
protected:
    explicit InAppPurchaseModel(const std::string & key);


    void initializeModel(void);
public:
    InAppPurchaseModel();


    static InAppPurchaseModel & getInstance(const std::string & key);
    virtual void update(float dt);
    void onGBAPIProductListResponse(void *vo);
    void onStoreProductListResponse(void *vo);
    void onStoreStoreFailTransaction(void *vo);
    void onStoreStoreCompleteTransaction(void *vo);
    void onGBAPIPurchaseResponse(void *vo);
    void onStoreConfirmedTransaction(void *vo);
public:
    static const char *const NAME;
    ~InAppPurchaseModel();
    std::string getAccessToken() const;
    std::string getPaymentId() const;
    std::string getProviderId() const;
//    std::string getClientId() const;
    int getFreeID() const;
    void setAccessToken(std::string accessToken);
    void setPaymentId(std::string paymentId);
    void setProviderId(std::string providerId);
//    void setClientId(std::string clientId);
    void setFreeId(int freeId);
private:
    std::string __paymentID;
    std::string __providerID;
    std::string __accessToken;
//    std::string __clientID;
    std::string __gameId;
    int __freeID;
};

#endif /* defined(__InAppPurchase__InAppPurchaseModel__) */
