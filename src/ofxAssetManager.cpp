#include "ofxAssetManager.h"

ofxAssetManager* ofxAssetManager::mInstance = NULL;

ofxAssetManager* ofxAssetManager::getInstance(){
	if( !mInstance ){
		mInstance = new ofxAssetManager();
	}

	return mInstance;
}

ofxAssetManager::~ofxAssetManager() {
	// cleanup
}

ofImage* ofxAssetManager::getImage( string url, bool cache ){
	if( mImageMap[url] ){
		return mImageMap[url];
	}else{
		ofImage *newImg = new ofImage();
		if( cache ){
            mImageMap[url] = newImg;
		}
		newImg->loadImage( url );

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
