#include "DLLMain.h"
#include "Utilities.h"

#include "Hooks.h"
#include "RenderManager.h"
#include "Hacks.h"
#include "Menu.h"


#define ExampleHWID 676387714


extern HINSTANCE hAppInstance;

UCHAR szFileSys[255], szVolNameBuff[255];
DWORD dwMFL, dwSysFlags;
DWORD dwSerial;
LPCTSTR szHD = "C:\\";

HINSTANCE HThisModule;
bool DoUnload;

int InitialThread()
{
#ifdef Avoz_DEBUG
	Utilities::OpenConsole("Huehuehue");
#endif
	PrintMetaHeader();

	Offsets::Initialise();
	Interfaces::Initialise();
	NetVar.RetrieveClasses();
	NetvarManager::Instance()->CreateDatabase();
	Render::Initialise();
	Hacks::SetupHacks();
	Menu::SetupMenu();
	Hooks::Initialise();

	//Dump::DumpClassIds();


	Utilities::Log("Ready");

	while (DoUnload == false)
	{
		Sleep(1000);
	}

	Hooks::UndoHooks();
	Sleep(2000);
	FreeLibraryAndExitThread(HThisModule, 0);

	return 0;
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		GetVolumeInformation(szHD, (LPTSTR)szVolNameBuff, 255, &dwSerial, &dwMFL, &dwSysFlags, (LPTSTR)szFileSys, 255);

		if (dwSerial == ExampleHWID)
		{
			Sleep(100);
		}
		else
		{
			// when HWID rejected
			MessageBox(NULL, "Fuck off cunt, ur HWID doesn't match.", "Nope", MB_OK);
			exit(0);
			return TRUE;
		}

		{
			{
				DisableThreadLibraryCalls(hModule);

				CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)InitialThread, NULL, NULL, NULL);

				return TRUE;
			}
		}
		return FALSE;
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
	}
	return TRUE;
}