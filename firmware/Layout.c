
#include "Layout.h"
#include "Keyboard.h"

extern bool caps_lock;
extern uint8_t switch_caps_count;


void set_modifiers(uint8_t row, uint8_t col, USB_KeyboardReport_Data_t* KeyboardReport) {
	if (col == 0 && row == 5)
		KeyboardReport->Modifier |= HID_KEYBOARD_MODIFIER_LEFTCTRL;
	else if (col == 0 && row == 3)
		KeyboardReport->Modifier |= HID_KEYBOARD_MODIFIER_LEFTALT;
	else if (col == 6 && row == 4)
		KeyboardReport->Modifier |= HID_KEYBOARD_MODIFIER_RIGHTSHIFT;
	else if (col == 7 && row == 2)
		KeyboardReport->Modifier |= HID_KEYBOARD_MODIFIER_RIGHTALT;
	else if (col == 7 && row == 3)
		switch_layer();
		//KeyboardReport->Modifier |= HID_KEYBOARD_MODIFIER_RIGHTCTRL;
	else if (col == 6 && row == 0)
		KeyboardReport->Modifier |= HID_KEYBOARD_MODIFIER_LEFTGUI;
	else if (col == 9 && row == 4)
		KeyboardReport->Modifier |= HID_KEYBOARD_MODIFIER_RIGHTCTRL;
}

void shift_lock_action(USB_KeyboardReport_Data_t* KeyboardReport, uint8_t* UsedKeyCodes) {
#ifdef MX_LOCK
				if (!caps_lock)
					KeyboardReport->KeyCode[(*UsedKeyCodes)++] = HID_KEYBOARD_SC_CAPS_LOCK;
				else
					switch_caps_count = 2;
#else
				KeyboardReport->KeyCode[(*UsedKeyCodes)++] = HID_KEYBOARD_SC_CAPS_LOCK;
#endif
}

uint8_t matrix[3][11][9] = {

{ //VICE layout
	{HID_KEYBOARD_SC_1_AND_EXCLAMATION,HID_KEYBOARD_SC_GRAVE_ACCENT_AND_TILDE,HID_KEYBOARD_SC_TAB,HID_KEYBOARD_SC_ESCAPE,HID_KEYBOARD_SC_SPACE,0,HID_KEYBOARD_SC_Q,HID_KEYBOARD_SC_2_AND_AT,0},
	{HID_KEYBOARD_SC_3_AND_HASHMARK,HID_KEYBOARD_SC_W,HID_KEYBOARD_SC_A,0,HID_KEYBOARD_SC_Z,HID_KEYBOARD_SC_S,HID_KEYBOARD_SC_E,HID_KEYBOARD_SC_4_AND_DOLLAR,0},
	{HID_KEYBOARD_SC_5_AND_PERCENTAGE,HID_KEYBOARD_SC_R,HID_KEYBOARD_SC_D,HID_KEYBOARD_SC_X,HID_KEYBOARD_SC_C,HID_KEYBOARD_SC_F,HID_KEYBOARD_SC_T,HID_KEYBOARD_SC_6_AND_CARET,0},
	{HID_KEYBOARD_SC_7_AND_AND_AMPERSAND,HID_KEYBOARD_SC_Y,HID_KEYBOARD_SC_G,HID_KEYBOARD_SC_V,HID_KEYBOARD_SC_B,HID_KEYBOARD_SC_H,HID_KEYBOARD_SC_U,HID_KEYBOARD_SC_8_AND_ASTERISK,0},
	{HID_KEYBOARD_SC_9_AND_OPENING_PARENTHESIS,HID_KEYBOARD_SC_I,HID_KEYBOARD_SC_J,HID_KEYBOARD_SC_N,HID_KEYBOARD_SC_M,HID_KEYBOARD_SC_K,HID_KEYBOARD_SC_O,HID_KEYBOARD_SC_0_AND_CLOSING_PARENTHESIS,0},
	{HID_KEYBOARD_SC_MINUS_AND_UNDERSCORE,HID_KEYBOARD_SC_P,HID_KEYBOARD_SC_L,HID_KEYBOARD_SC_COMMA_AND_LESS_THAN_SIGN,HID_KEYBOARD_SC_DOT_AND_GREATER_THAN_SIGN,HID_KEYBOARD_SC_SEMICOLON_AND_COLON,HID_KEYBOARD_SC_OPENING_BRACKET_AND_OPENING_BRACE,HID_KEYBOARD_SC_EQUAL_AND_PLUS,0},
	{HID_KEYBOARD_SC_INSERT,HID_KEYBOARD_SC_CLOSING_BRACKET_AND_CLOSING_BRACE,HID_KEYBOARD_SC_APOSTROPHE_AND_QUOTE,HID_KEYBOARD_SC_SLASH_AND_QUESTION_MARK,0,HID_KEYBOARD_SC_BACKSLASH_AND_PIPE,HID_KEYBOARD_SC_DELETE,HID_KEYBOARD_SC_HOME,0},
	{HID_KEYBOARD_SC_BACKSPACE,HID_KEYBOARD_SC_ENTER,HID_KEYBOARD_SC_RIGHT_ARROW,HID_KEYBOARD_SC_DOWN_ARROW,HID_KEYBOARD_SC_F1,HID_KEYBOARD_SC_F3,HID_KEYBOARD_SC_F5,HID_KEYBOARD_SC_F7,0},
	{0,0,0,0,0,0,0,0,HID_KEYBOARD_SC_PAUSE},
	{HID_KEYBOARD_SC_KEYPAD_8_AND_UP_ARROW,HID_KEYBOARD_SC_KEYPAD_2_AND_DOWN_ARROW,HID_KEYBOARD_SC_KEYPAD_4_AND_LEFT_ARROW,HID_KEYBOARD_SC_KEYPAD_6_AND_RIGHT_ARROW,0,0,0,0,0},
	{HID_KEYBOARD_SC_W,HID_KEYBOARD_SC_S,HID_KEYBOARD_SC_A,HID_KEYBOARD_SC_D,HID_KEYBOARD_SC_X,HID_KEYBOARD_SC_G,HID_KEYBOARD_SC_H,HID_KEYBOARD_SC_I,HID_KEYBOARD_SC_J}
},

{ //tlt layout
	{HID_KEYBOARD_SC_1_AND_EXCLAMATION,HID_KEYBOARD_SC_ESCAPE,HID_KEYBOARD_SC_TAB,0,HID_KEYBOARD_SC_SPACE,0,HID_KEYBOARD_SC_Q,HID_KEYBOARD_SC_2_AND_AT,0},
	{HID_KEYBOARD_SC_3_AND_HASHMARK,HID_KEYBOARD_SC_W,HID_KEYBOARD_SC_A,0,HID_KEYBOARD_SC_Z,HID_KEYBOARD_SC_S,HID_KEYBOARD_SC_E,HID_KEYBOARD_SC_4_AND_DOLLAR,0},
	{HID_KEYBOARD_SC_5_AND_PERCENTAGE,HID_KEYBOARD_SC_R,HID_KEYBOARD_SC_D,HID_KEYBOARD_SC_X,HID_KEYBOARD_SC_C,HID_KEYBOARD_SC_F,HID_KEYBOARD_SC_T,HID_KEYBOARD_SC_6_AND_CARET,0},
	{HID_KEYBOARD_SC_7_AND_AND_AMPERSAND,HID_KEYBOARD_SC_Y,HID_KEYBOARD_SC_G,HID_KEYBOARD_SC_V,HID_KEYBOARD_SC_B,HID_KEYBOARD_SC_H,HID_KEYBOARD_SC_U,HID_KEYBOARD_SC_8_AND_ASTERISK,0},
	{HID_KEYBOARD_SC_9_AND_OPENING_PARENTHESIS,HID_KEYBOARD_SC_I,HID_KEYBOARD_SC_J,HID_KEYBOARD_SC_N,HID_KEYBOARD_SC_M,HID_KEYBOARD_SC_K,HID_KEYBOARD_SC_O,HID_KEYBOARD_SC_0_AND_CLOSING_PARENTHESIS,0},
	{HID_KEYBOARD_SC_MINUS_AND_UNDERSCORE,HID_KEYBOARD_SC_P,HID_KEYBOARD_SC_L,HID_KEYBOARD_SC_COMMA_AND_LESS_THAN_SIGN,HID_KEYBOARD_SC_DOT_AND_GREATER_THAN_SIGN,HID_KEYBOARD_SC_SEMICOLON_AND_COLON,HID_KEYBOARD_SC_OPENING_BRACKET_AND_OPENING_BRACE,HID_KEYBOARD_SC_EQUAL_AND_PLUS,0},
	{0,HID_KEYBOARD_SC_CLOSING_BRACKET_AND_CLOSING_BRACE,HID_KEYBOARD_SC_APOSTROPHE_AND_QUOTE,HID_KEYBOARD_SC_SLASH_AND_QUESTION_MARK,0,HID_KEYBOARD_SC_BACKSLASH_AND_PIPE,HID_KEYBOARD_SC_NON_US_BACKSLASH_AND_PIPE,HID_KEYBOARD_SC_HOME,0},
	{HID_KEYBOARD_SC_DELETE,HID_KEYBOARD_SC_ENTER,0,0,HID_KEYBOARD_SC_F1,HID_KEYBOARD_SC_F3,HID_KEYBOARD_SC_F5,HID_KEYBOARD_SC_F7,0},
	{0,0,0,0,0,0,0,0,HID_KEYBOARD_SC_BACKSPACE},
	{HID_KEYBOARD_SC_KEYPAD_8_AND_UP_ARROW,HID_KEYBOARD_SC_KEYPAD_2_AND_DOWN_ARROW,HID_KEYBOARD_SC_KEYPAD_4_AND_LEFT_ARROW,HID_KEYBOARD_SC_KEYPAD_6_AND_RIGHT_ARROW,0,0,0,0,0},
	{HID_KEYBOARD_SC_W,HID_KEYBOARD_SC_S,HID_KEYBOARD_SC_A,HID_KEYBOARD_SC_D,HID_KEYBOARD_SC_SPACE,HID_KEYBOARD_SC_G,HID_KEYBOARD_SC_H,HID_KEYBOARD_SC_I,HID_KEYBOARD_SC_J}
},

{ //layer
	{HID_KEYBOARD_SC_F1,HID_KEYBOARD_SC_GRAVE_ACCENT_AND_TILDE,HID_KEYBOARD_SC_TAB,0,HID_KEYBOARD_SC_SPACE,0,HID_KEYBOARD_SC_Q,HID_KEYBOARD_SC_F2,0},
	{HID_KEYBOARD_SC_F3,HID_KEYBOARD_SC_UP_ARROW,HID_KEYBOARD_SC_LEFT_ARROW,0,HID_KEYBOARD_SC_Z,HID_KEYBOARD_SC_DOWN_ARROW,HID_KEYBOARD_SC_E,HID_KEYBOARD_SC_F4,0},
	{HID_KEYBOARD_SC_F5,HID_KEYBOARD_SC_R,HID_KEYBOARD_SC_RIGHT_ARROW,HID_KEYBOARD_SC_X,HID_KEYBOARD_SC_C,HID_KEYBOARD_SC_F,HID_KEYBOARD_SC_T,HID_KEYBOARD_SC_F6,0},
	{HID_KEYBOARD_SC_F7,HID_KEYBOARD_SC_Y,HID_KEYBOARD_SC_G,HID_KEYBOARD_SC_V,HID_KEYBOARD_SC_B,HID_KEYBOARD_SC_H,HID_KEYBOARD_SC_U,HID_KEYBOARD_SC_F8,0},
	{HID_KEYBOARD_SC_F9,HID_KEYBOARD_SC_PRINT_SCREEN,HID_KEYBOARD_SC_J,HID_KEYBOARD_SC_N,HID_KEYBOARD_SC_M,HID_KEYBOARD_SC_HOME,HID_KEYBOARD_SC_SCROLL_LOCK,HID_KEYBOARD_SC_F10,0},
	{HID_KEYBOARD_SC_F11,HID_KEYBOARD_SC_PAUSE,HID_KEYBOARD_SC_PAGE_UP,HID_KEYBOARD_SC_END,HID_KEYBOARD_SC_PAGE_DOWN,HID_KEYBOARD_SC_LEFT_ARROW,HID_KEYBOARD_SC_UP_ARROW,HID_KEYBOARD_SC_F12,0},
	{0,HID_KEYBOARD_SC_CLOSING_BRACKET_AND_CLOSING_BRACE,HID_KEYBOARD_SC_RIGHT_ARROW,HID_KEYBOARD_SC_DOWN_ARROW,0,HID_KEYBOARD_SC_BACKSLASH_AND_PIPE,HID_KEYBOARD_SC_NON_US_BACKSLASH_AND_PIPE,HID_KEYBOARD_SC_HOME,0},
	{HID_KEYBOARD_SC_INSERT,HID_KEYBOARD_SC_ENTER,0,0,HID_KEYBOARD_SC_VOLUME_UP,HID_KEYBOARD_SC_VOLUME_DOWN,HID_KEYBOARD_SC_MUTE,HID_KEYBOARD_SC_F7,0},
	{0,0,0,0,0,0,0,0,HID_KEYBOARD_SC_MUTE},
	{HID_KEYBOARD_SC_KEYPAD_8_AND_UP_ARROW,HID_KEYBOARD_SC_KEYPAD_2_AND_DOWN_ARROW,HID_KEYBOARD_SC_KEYPAD_4_AND_LEFT_ARROW,HID_KEYBOARD_SC_KEYPAD_6_AND_RIGHT_ARROW,0,0,0,0,0},
	{HID_KEYBOARD_SC_W,HID_KEYBOARD_SC_S,HID_KEYBOARD_SC_A,HID_KEYBOARD_SC_D,HID_KEYBOARD_SC_SPACE,HID_KEYBOARD_SC_G,HID_KEYBOARD_SC_H,HID_KEYBOARD_SC_I,HID_KEYBOARD_SC_J}

}
};
