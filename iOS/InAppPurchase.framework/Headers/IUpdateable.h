//
//  IUpdateable.h
//  InAppPurchase
//
//  Created by kaijung on 13/2/22.
//
//

#ifndef InAppPurchase_IUpdateable_h
#define InAppPurchase_IUpdateable_h


struct IUpdateable
{
    virtual void update(float dt){};
    virtual ~IUpdateable(){};
};

#endif
