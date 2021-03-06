
#include "ofxHotKeys.h"

#ifdef TARGET_WIN32


// not tested yet

bool ofGetModifierSelection(){
	return ofGetModifierShiftPressed();
}

//COMMAND on OS X, CTRL on Windows
//----------------------------------------
bool ofGetModifierShortcutKeyPressed(){
	return ofGetModifierPressed(OF_MODIFIER_KEY_CTRL);
}
bool ofGetModifierPressed(ofxModifierKey mod)
{
	unsigned int t = 0;
	
	if ((OF_MODIFIER_KEY_CTRL & mod) == OF_MODIFIER_KEY_CTRL)
		return (GetKeyState( VK_CONTROL ) & 0x80) > 0;
	
	else if ((OF_MODIFIER_KEY_ALT & mod) == OF_MODIFIER_KEY_ALT)
		return (GetKeyState( VK_MENU ) & 0x80) > 0;
	
	else if ((OF_MODIFIER_KEY_SHIFT & mod) == OF_MODIFIER_KEY_SHIFT)
		return (GetKeyState( VK_SHIFT ) & 0x80) > 0;
	
	else if ((OF_MODIFIER_KEY_SPECIAL & mod) == OF_MODIFIER_KEY_SPECIAL)
		return (GetKeyState( VK_LWIN ) & 0x80) > 0 || (GetKeyState( VK_RWIN ) & 0x80) > 0;
	
	return false;
}

#endif