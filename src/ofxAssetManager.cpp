#include "ofxAssetManager.h"

ofxAssetManager* ofxAssetManager::mInstance = NULL;

ofxAssetManager* ofxAssetManager::getInstance(){
	if( !mInstance ){
		mInstance = new ofxAssetManager();
        	}

	return mInstance;
}

ofxAssetManager::~ofxAssetManager() {

}

ofImage* ofxAssetManager::getImage( string url, bool cache ){
    ofLog(OF_LOG_ERROR)<<url<<endl;
	if( mImageMap[url] ){
		return mImageMap[url];
	}else{
		ofImage *newImg = new ofImage();
		newImg->loadImage(url);

		if( cache ){
            mImageMap[url] = newImg;
		}

		return newImg;
	}
	return NULL;
}

void ofxAssetManager::removeCachedImage( string url ){
    ofImage *tmp = mImageMap[url];
    mImageMap.erase(url);
    delete tmp;
    tmp = NULL;
}
ofTrueTypeFont* ofxAssetManager::getTTFont(string fontPath, int fontSize){
    
    string key = fontPath + ofToString(fontSize);
    
    if( mTTFontMap[key] ){
        return mTTFontMap[key];
    }else{
        ofTrueTypeFont *newFont = new ofTrueTypeFont();
        newFont->loadFont( fontPath, fontSize , true, true);
        mTTFontMap[key] = newFont;
        
        return newFont;
    }
    
    return NULL;
    
}

//ofxFTGLFont* ofxAssetManager::getFont(string fontPath, int fontSize){
//
//    string key = fontPath + ofToString(fontSize);
//
//    if( mFontMap[key] ){
//        return mFontMap[key];
//    }else{
//        ofxFTGLFont *newFont = new ofxFTGLFont();
//        newFont->loadFont( fontPath, fontSize );
//        mFontMap[key] = newFont;
//
//        return newFont;
//    }
//
//    return NULL;
//
//}

