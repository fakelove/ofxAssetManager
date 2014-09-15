#pragma once

#include "ofMain.h"
//#include "ofxFTGLFont.h"
//#include "ofxTrueTypeFontUC.h"
class ofxAssetManager {
  public:
	static ofxAssetManager* getInstance();
	ofImage* getImage( string url, bool cache=true );
    void removeCachedImage( string url );

//    ofxFTGLFont* getFont(string fontName, int fontSize);
//    ofxTrueTypeFontUC* getUCFont(string fontName, int fontSize);
    ofTrueTypeFont* getTTFont(string fontPath, int fontSize);
    void exit();
  private:
  	ofxAssetManager(){};	// private ctor
  	~ofxAssetManager();
  	ofxAssetManager( ofxAssetManager const& ){}; // copy ctor is private
  	static ofxAssetManager *mInstance;
//    ofxThreadedImageLoader *mLoader;
  	std::map<string, ofImage*>	mImageMap;
//  	std::map<string, ofxFTGLFont*>  mFontMap;
//   std::map<string, ofxTrueTypeFontUC*>  mUCFontMap;
    std::map<string, ofTrueTypeFont*>  mTTFontMap;
};
