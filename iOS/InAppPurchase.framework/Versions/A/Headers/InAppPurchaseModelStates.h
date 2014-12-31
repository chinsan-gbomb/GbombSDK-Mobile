//
//  InAppPurchaseModelStates.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/16.
//
//

#ifndef __InAppPurchase__InAppPurchaseModelStates__
#define __InAppPurchase__InAppPurchaseModelStates__

#include "IGameModelState.h"

class InAppPurchaseModelInitState
: public virtual IGameModelState
{
public:
	InAppPurchaseModelInitState();
	virtual ~InAppPurchaseModelInitState();

    static IGameModelState*  getInstance();
    virtual void handle(GameModel *gm,void *value_object);
    static InAppPurchaseModelInitState *__inst;
};

class InAppPurchaseModelGBAPIProductListResponseState
: public virtual IGameModelState
{
public:
	InAppPurchaseModelGBAPIProductListResponseState();
	virtual ~InAppPurchaseModelGBAPIProductListResponseState();

    static IGameModelState* getInstance();
    virtual void handle(GameModel *gm,void *value_object);
    static InAppPurchaseModelGBAPIProductListResponseState *__inst;
};

class InAppPurchaseModelStoreProductsResponseResponseState
: public virtual IGameModelState
{
public:
	InAppPurchaseModelStoreProductsResponseResponseState();
	virtual ~InAppPurchaseModelStoreProductsResponseResponseState();

    static IGameModelState*  getInstance();
    virtual void handle(GameModel *gm,void *value_object);
    static InAppPurchaseModelStoreProductsResponseResponseState *__inst;
};


class InAppPurchaseModelStoreStoreCompleteTransactionState
: public virtual IGameModelState
{
public:
	InAppPurchaseModelStoreStoreCompleteTransactionState();
	virtual ~InAppPurchaseModelStoreStoreCompleteTransactionState();

    static IGameModelState* getInstance();
    virtual void handle(GameModel *gm,void *value_object);
    static InAppPurchaseModelStoreStoreCompleteTransactionState *__inst;
};

class InAppPurchaseModelGBAPIPurchaseResponseState
: public virtual IGameModelState
{
public:
	InAppPurchaseModelGBAPIPurchaseResponseState();
	virtual ~InAppPurchaseModelGBAPIPurchaseResponseState();

    static IGameModelState* getInstance();
    virtual void handle(GameModel *gm,void *value_object);
    static InAppPurchaseModelGBAPIPurchaseResponseState *__inst;
};

class InAppPurchaseModelStoreStoreComfirmedTransactionState
: public virtual IGameModelState
{
public:
	InAppPurchaseModelStoreStoreComfirmedTransactionState();
	virtual ~InAppPurchaseModelStoreStoreComfirmedTransactionState();

    static IGameModelState* getInstance();
    virtual void handle(GameModel *gm,void *value_object);
    static InAppPurchaseModelStoreStoreComfirmedTransactionState *__inst;
};

#endif /* defined(__InAppPurchase__InAppPurchaseModelStates__) */
