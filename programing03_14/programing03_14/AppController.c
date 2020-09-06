#include "AppController.h"
#include "AppView.h"
#include "Dictionary.h"
#include "Object.h"
#include "Key.h"
#include "Common.h"
#include "Traverse.h"
#include <conio.h>

typedef struct _AppCotroller
{
	Dictionary* _dictionary;
	
} AppController;

AppController* AppController_new()
{
	AppController* _this = NewObject(AppController);
	_this->_dictionary = Dictionary_new();
	return _this;
}

void AppController_showInternalShapeOfBinaryTree(AppController* _this, Traverse* aTraverse)
{ 
	Dictionary_scanInSortedOrder(_this->_dictionary, aTraverse);
}

void AppController_run(AppController* _this)
{
	AppView_out_start();
	char inputChar = AppView_in(_this);

	while (inputChar != Esc) {

		if (isAlpha(inputChar))
		{
			Key* newKey = Key_newWith(inputChar);
			Object* newobject = Object_newWith(inputChar);
			if (!Dictionary_keyDoesExist(_this->_dictionary, newKey))
			{
				Dictionary_addKeyAndObject(_this->_dictionary, newKey, newobject);
				AppView_out_add(newKey, newobject);
			}
			else AppView_out_replace(inputChar);
		}
		else if (inputChar == '-')
		{
			if (Dictionary_isEmpty(_this->_dictionary))
				AppView_out("[Empty] 큐에 삭제할 원소가 없습니다.\n");
			else
			{
				AppView_out("삭제할 객체의 Key 값을 입력하시오: ");
				Key* removekey = Key_newWith(_getch());
				AppView_out_key(removekey);

				if (Dictionary_keyDoesExist(_this->_dictionary, removekey))
				{
					Object* removeobject = Dictionary_removeObjectForKey(_this->_dictionary, removekey);
					AppView_keydelete(removekey, removeobject);
				}
				else AppView_out("[검색]주어진 키가 사전에 존재하지 않습니다.\n");
			}
		}
		else if (inputChar == '#')
		{
			int size = Dictionary_size(_this->_dictionary);
			AppView_out_showsize(size);
		}
		else if (inputChar == '/')
		{
			AppView_out("[Tree]\n");
			Traverse* test = Traverse_new();
			Dictionary_inorderRecursively(_this->_dictionary, test, Dictionary_root( _this->_dictionary), 0);
		}
		else if (inputChar == '?')
		{
			AppView_out("검색할 객체의 Key 값을 입력하시오:");
			Key* input = Key_newWith(_getch());
			AppView_out_key(input);
			if (Dictionary_keyDoesExist(_this->_dictionary, input))
				AppView_out_search(input, Dictionary_objectForKey(_this->_dictionary, input));
			else AppView_out("[검색]주어진 키가 사전에 존재하지 않습니다.\n");
		}
		else {
			AppView_out("[ignore] 의미 없는 문자가 입력되었습니다.\n");
		}

		inputChar = AppView_in(_this);
	}

	AppView_out("\n<<< 사전 활용 프로그램을 종료합니다. >>>");
}

void AppController_delete(AppController* appcontroller)
{
	free(appcontroller);
}