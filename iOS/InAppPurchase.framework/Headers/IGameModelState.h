//
//  IGameModelState.h
//  InAppPurchase
//
//  Created by kaijung on 13/2/23.
//
//

#ifndef __InAppPurchase__IGameModelState__
#define __InAppPurchase__IGameModelState__
#include "GameModel.h"

class GameModel;
struct IGameModelState
{
public:
    static IGameModelState& getInstance();    
    virtual void handle(GameModel *gm,void *value_object){};
    virtual ~IGameModelState() {};
};

#endif /* defined(__InAppPurchase__IGameModelState__) */
