// Test.h
// �e�X�g���s��

#include "UI.h"
#include "FileManager.h"

class CTest
{
private:
	CSeatManager seatManager;
	CConverter converter;
	CUserInterface ui;
	CFileManager fileManager;
	void Update();
public:
	CTest();
	void Cansel();
	void Run();
};