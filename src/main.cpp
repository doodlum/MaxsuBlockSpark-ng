
#include "LoadGame.h"

void Init()
{
	auto g_message = SKSE::GetMessagingInterface();
	if (!g_message) {
		logger::error("Messaging Interface Not Found!");
	}

	g_message->RegisterListener(MaxsuBlockSpark::EventCallback);
}


EXTERN_C [[maybe_unused]] __declspec(dllexport) bool SKSEAPI SKSEPlugin_Load(const SKSE::LoadInterface* a_skse)
{
#ifndef NDEBUG
	while (!IsDebuggerPresent()) {};
#endif

	DKUtil::Logger::Init(Plugin::NAME, REL::Module::get().version().string());

	logger::info("Loaded plugin");

	SKSE::Init(a_skse);

	Init();

	return true;
}

EXTERN_C [[maybe_unused]] __declspec(dllexport) constinit auto SKSEPlugin_Version = []() noexcept {
	SKSE::PluginVersionData data;
	data.PluginVersion(Plugin::Version);
	data.PluginName(Plugin::NAME);
	data.AuthorName(Plugin::AUTHOR);
	data.UsesAddressLibrary(true);
	data.HasNoStructUse(true);
	return data;
}();

EXTERN_C [[maybe_unused]] __declspec(dllexport) bool SKSEAPI SKSEPlugin_Query(const SKSE::QueryInterface*, SKSE::PluginInfo* pluginInfo)
{
	pluginInfo->name = SKSEPlugin_Version.pluginName;
	pluginInfo->infoVersion = SKSE::PluginInfo::kVersion;
	pluginInfo->version = SKSEPlugin_Version.pluginVersion;
	return true;
}
