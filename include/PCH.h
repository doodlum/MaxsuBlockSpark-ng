#pragma once
#pragma warning(push)
#if defined(FALLOUT4)
#include "RE/Fallout.h"
#include "F4SE/F4SE.h"
#define SKSE F4SE
#define SKSEAPI F4SEAPI
#define SKSEPlugin_Load F4SEPlugin_Load
#define SKSEPlugin_Query F4SEPlugin_Query
#define RUNTIME RUNTIME_1_10_163
#else
#include "RE/Skyrim.h"
#include "SKSE/SKSE.h"
#if defined(SKYRIMAE)
#define RUNTIME 0
#elif defined(SKYRIMVR)
#define RUNTIME SKSE::RUNTIME_VR_1_4_15_1
#else
#define RUNTIME SKSE::RUNTIME_1_5_97
#endif
#endif

#ifdef NDEBUG
#include <spdlog/sinks/basic_file_sink.h>
#else
#include <spdlog/sinks/msvc_sink.h>
#endif
#define MICROSOFT_WINDOWS_WINBASE_H_DEFINE_INTERLOCKED_CPLUSPLUS_OVERLOADS 0
#include <Windows.h>

#pragma warning(pop)

using namespace std::literals;

namespace logger = SKSE::log;

namespace util
{
	using SKSE::stl::report_and_fail;
}

#define DLLEXPORT __declspec(dllexport)

#include "Plugin.h"

#pragma pack(push, 1)
struct AbsoluteJump
{
	std::uint8_t jump{ 0xFF };       // 0
	std::uint8_t modRm{ 0x25 };      // 1
	std::int32_t relative32{ 0x0 };  // 2
	std::int64_t absolute64;         // 6
};
#pragma pack(pop)

void JumpProcAddress(FARPROC procAddress, int64_t address);
