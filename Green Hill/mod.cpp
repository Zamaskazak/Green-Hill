#include "pch.h"

extern "C"
{
	__declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		// Executed at startup, contains helperFunctions and the path to your mod (useful for getting the config file.)
		// This is where we override functions, replace static data, etc.
#define ReplacePNG_StageE(a) do { \
	_snprintf_s(pathbuf, LengthOfArray(pathbuf), "%s\\textures\\pvr_stage_en\\index.txt", path); \
	helperFunctions.ReplaceFile("system\\" a ".PVR", pathbuf); \
} while (0)

#define ReplacePNG_StageJ(a) do { \
	_snprintf_s(pathbuf, LengthOfArray(pathbuf), "%s\\textures\\pvr_stage_jp\\index.txt", path); \
	helperFunctions.ReplaceFile("system\\" a ".PVR", pathbuf); \
} while (0)
	{

		char pathbuf[MAX_PATH];
		const std::string s_path(path);

		// English stage PVRs
		ReplacePNG_StageE("B_STAGE03_E");
		ReplacePNG_StageE("E_STAGE02_E");
		ReplacePNG_StageE("S_STAGE01_E");

		// Japanese stage PVRs
		ReplacePNG_StageJ("B_STAGE03");
		ReplacePNG_StageJ("E_STAGE02");
		ReplacePNG_StageJ("S_STAGE01");
	}

	}


__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer }; // This is needed for the Mod Loader to recognize the DLL.

}