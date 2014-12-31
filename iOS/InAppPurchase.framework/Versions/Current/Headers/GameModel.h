//
//  GameModel.h
//  InAppPurchase
//
//  Created by kaijung on 13/2/23.
//
//

#ifndef __InAppPurchase__GameModel__
#define __InAppPurchase__GameModel__

#include "IUpdateable.h"
#include <PureMVC/PureMVC.hpp>
#include "IGameModelState.h"

using PureMVC::Interfaces::IModel;
using PureMVC::Core::Model;

class IGameModelState;
class GameModel
: public virtual IModel
, public virtual IUpdateable
, public Model
{
    friend class Model;
    
protected:
    template<typename _DerivedType>    
    explicit GameModel(_DerivedType* instance,std::string const& key)
    :Model(instance,key)
    { }

    explicit GameModel(std::string const& key)
    {}
public:
    static GameModel& getInstance(std::string const& key);
    virtual void update(float dt);
    IGameModelState *__gameModelState;
    GameModel() {};
protected:
    virtual void initializeModel(void);
  
public:
    static char const* const NAME;
    ~GameModel();
    
private:
    GameModel(GameModel const&) {};
};

#endif /* defined(__MobileThirteen__GameModel__) */
