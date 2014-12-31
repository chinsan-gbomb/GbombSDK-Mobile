//
//  GBAPIServiceDelegate.h
//  InAppPurchase
//
//  Created by kaijung on 13/5/13.
//
//

#ifndef __InAppPurchase__GBAPIServiceDelegate__
#define __InAppPurchase__GBAPIServiceDelegate__

#include <iostream>
#include <map>

struct URLResponse
{
    int statusCode;
    std::string URL;
    //std::string MIMEType;
    //long long expectedContentLength;
    //std::string  textEncodingName;
    //std::string  suggestedFilename;
};

struct Error
{
    int  code;
    std::string  domain;
    std::map<std::string, std::string>  userInfo;
};

class GBAPIServiceDelegate
{
public:
    GBAPIServiceDelegate();
    virtual ~GBAPIServiceDelegate();
    static GBAPIServiceDelegate* GetInstance();
    
    void GBDidReceiveResponse(URLResponse *reps);
    void GBDidReceiveData(char *data);
    void GBConnectionDidFinishLoading();
    void GBDidFailWithError(Error *err);
private:
    static GBAPIServiceDelegate *__gbAPIServiceDelegate;
    URLResponse *__urlResponse;
    std::string __responseText;
};

#endif /* defined(__InAppPurchase__GBAPIServiceDelegate__) */
