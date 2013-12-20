#pragma once

#include "ofMain.h"
#include "ofxFTGL.h"

class ofxAssetManager {
  public:
	static ofxAssetManager* getInstance();
	ofImage* getImage( string url, bool cache=true );
    void removeCachedImage( string url );

    ofxFTGLFont* getFont(string fontName, int fontSize);

  private:
  	ofxAssetManager(){};	// private ctor
  	~ofxAssetManager();
  	ofxAssetManager( ofxAssetManager const& ){}; // copy ctor is private
  	static ofxAssetManager *mInstance;

  	std::map<string, ofImage*>	mImageMap;
  	std::map<string, ofxFTGLFont*>  mFontMap;
};
