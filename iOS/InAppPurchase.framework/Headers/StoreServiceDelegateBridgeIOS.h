//
//  StoreServiceDelegateBridgeIOS.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/15.
//
//

#ifndef __InAppPurchase__StoreServiceDelegateBridgeIOS__
#define __InAppPurchase__StoreServiceDelegateBridgeIOS__

#import <Foundation/Foundation.h>
#import <StoreKit/StoreKit.h>

@interface  StoreServiceDelegateBridgeIOS : NSObject<SKProductsRequestDelegate,SKPaymentTransactionObserver>
{
    NSMutableDictionary *_queuedTransaction;
}

@property(nonatomic, copy) NSMutableDictionary* queuedTransaction;

- (void) confirmPurchase: (IAPPurchaseResponseVO*) vo;
@end

#endif /* defined(__InAppPurchase__StoreServiceDelegateBridgeIOS__) */
